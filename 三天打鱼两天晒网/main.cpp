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
	std::ofstream output(dateTestFile);//�򿪳�������ļ���û��������dateTestFile�ļ�
	
	inputDateFile(input, output);//��in.txt�еĲ�������������in.dat��
	
	closeFile(input); //�ر�input����in.txt�ļ�֮��Ĺ���
	closeFile(output);//�ر�output����in.dat�ļ�֮��Ĺ���

	if (!Open(output, resultFile)) return -1;//�������װ����,��output����resultFile�ļ����������ʧ�ܣ���������
	if (!Open(input, dateTestFile)) return -1;

	judgingResult(input, output);//�ж�ÿ���������ڴ��㻹����ɹ���������������out.txt�ļ���
}