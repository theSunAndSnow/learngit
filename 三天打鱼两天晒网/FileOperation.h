#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H
#include <fstream>

void inputDateFile(std::ifstream &input, std::ofstream &output);
void closeFile(std::ifstream &intput);
void closeFile(std::ofstream &output);
bool Open(std::ifstream &input, const std::string &FileName);
bool Open(std::ofstream &output, const std::string &FileName);
void judgingResult(std::ifstream &input, std::ofstream &output);

#endif
