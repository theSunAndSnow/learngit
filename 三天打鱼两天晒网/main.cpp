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

	std::ifstream input(dateArchiveFile);//打开测试数据文件
	std::ofstream output(dateTestFile);//打开程序读入文件
	
	inputDateFile(input, output);//将in.txt中的测试数据输入至in.dat中
	
	closeFile(input); //关闭input流与in.txt文件之间的关联
	closeFile(output);//关闭output流与in.dat文件之间的关联

	if (!Open(output, resultFile)) return 0;//错误处理包装函数,将output流与resultFile文件相关联，若失败，则程序结束
	if (!Open(input, dateTestFile)) return 0;

	judgingResult(input, output);
}