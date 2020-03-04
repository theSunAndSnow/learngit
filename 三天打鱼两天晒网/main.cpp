#include <iostream>
#include <fstream>
#include <string>
#include "FileOperation.h"
#include "Date.h"

int main()
{
	std::string dateArchiveFile = "in.txt";
	std::string resultFile = "out.txt";
	std::string dateTestFile = "in.dat";

	std::ifstream input(dateArchiveFile);//�򿪲��������ļ�
	std::ofstream output(dateTestFile);//�򿪳�������ļ�
	
	inputDateFile(input, output);//��in.txt�еĲ�������������in.dat��
	
	closeFile(input); //�ر�input����in.txt�ļ�֮��Ĺ���
	closeFile(output);//�ر�output����in.dat�ļ�֮��Ĺ���

	if (!Open(output, resultFile)) return 0;//�������װ����,��output����resultFile�ļ����������ʧ�ܣ���������
	if (!Open(input, dateTestFile)) return 0;

	judgingResult(input, output);
}