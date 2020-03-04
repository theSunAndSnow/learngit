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

