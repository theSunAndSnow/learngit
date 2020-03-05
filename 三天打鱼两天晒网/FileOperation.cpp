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

//错误处理包装函数
bool Open(std::ofstream &output, const std::string &FileName)
{
	output.open(FileName);
	if (!output) {
		std::cerr << "can't open " << FileName << "!!" << std::endl;
		return false;
	}

	return true;
}

//错误处理包装函数
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
		//检查date字符格式，将其全部转换为"20100101"格式
		auto p = date.find_first_of(",. 年月日\\ /");//p为date字符串中第一个' '、'/'、','、'.'、'\'、"年"、"月"、"日"的位置
		while (p != std::string::npos) {
			date.erase(p, 1);//删除p位置的字符
			p = date.find_first_of(",. 年月日\\ /");
		}

		//解决201011之类的格式问题
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

		//先将字符串转化为数字
		int dateNumber = std::stoi(date);
		//std::cout << dateNumber << std::endl;
		int year = dateNumber / 10000;
		dateNumber -= year * 10000;
		int month = dateNumber / 100;
		dateNumber -= month * 100;
		int days = dateNumber;
		//std::cout << year << " " << month << " " << days << std::endl;

		if (!legalDate(year, month, days)) {
			output << date << "不是一个正确格式的日期，错误数据" << std::endl;
			continue;
		}

		Date time(year, month, days);

		if (time.fishInWork()) {
			output << date << "他在打鱼！！！" << std::endl;
		}
		else {
			output << date << "他在晒网" << std::endl;
		}
	}
}

