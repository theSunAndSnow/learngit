#include <iostream>
#include <fstream>
#include <string>
#include "FileOperation.h"
#include "Date.h"

void inputDateFile(std::ifstream &input, std::ofstream &output)
{
	std::string date;
	while (std::getline(input, date)) {
		output << date << '\n';
	}
}

void closeFile(std::ifstream &input)
{
	input.close();
}

void closeFile(std::ofstream &output)
{
	output.close();
}

//�������װ����
bool Open(std::ofstream &output, const std::string &FileName)
{
	output.open(FileName);
	if (!output) {
		std::cerr << "can't open " << FileName << "!!" << std::endl;
		return false;
	}

	return true;
}

//�������װ����
bool Open(std::ifstream &input, const std::string &FileName)
{
	input.open(FileName, std::ifstream::in);
	if (!input) {
		std::cerr << "can't open " << FileName << "!!" << std::endl;
		return false;
	}

	return true;
}

bool legalDate(const int &year, const int &month, const int &days)
{
	if (year < 2010 || month < 1 || month > 12 || days < 1) {
		return false;
	}
	if (monthDays[month] < days) {
		return false;
	}
	return true;
}

void judgingResult(std::ifstream &input, std::ofstream &output)
{
	std::string date;
	while (getline(input, date)) {
		//���date�ַ���ʽ������ȫ��ת��Ϊ"20100101"��ʽ
		auto p = date.find_first_of(",. ������\\ /");//pΪdate�ַ����е�һ��' '��'/'��','��'.'��'\'��"��"��"��"��"��"��λ��
		while (p != std::string::npos) {
			date.erase(p, 1);//ɾ��pλ�õ��ַ�
			p = date.find_first_of(",. ������\\ /");
		}

		//���201011֮��ĸ�ʽ����
		if (date.length() < 8) {
			std::string monthAndDays = date.substr(4);
			//std::cout << monthAndDays << std::endl;
			if (monthAndDays.length() == 2) {
				monthAndDays.insert(0, "0");
				monthAndDays.insert(2, "0");

				date.replace(4, 7, monthAndDays);

			}

			else if (monthAndDays.length() == 3) {
				if (monthAndDays.find_first_of("0") == 0) {//012
					monthAndDays.insert(2, "0");//0102
					date.replace(4, 8, monthAndDays);
				}
				else if (monthAndDays.find_first_of("0") == 1 || monthAndDays.find_first_of("0") == 2) {//102 || 120
					monthAndDays.insert(0, "0");//0102
					date.replace(4, 8, monthAndDays);
				}
			}
		}

		//�Ƚ��ַ���ת��Ϊ����
		int dateNumber = std::stoi(date);
		//std::cout << dateNumber << std::endl;
		int year = dateNumber / 10000;
		dateNumber -= year * 10000;
		int month = dateNumber / 100;
		dateNumber -= month * 100;
		int days = dateNumber;

		if (!legalDate(year, month, days)) {
			output << date << "����һ����ȷ��ʽ�����ڣ���������" << std::endl;
			continue;
		}

		Date time(year, month, days);

		if (time.fishInWork()) {
			output << date << "���ڴ��㣡����" << std::endl;
		}
		else {
			output << date << "����ɹ��" << std::endl;
		}
	}
}

