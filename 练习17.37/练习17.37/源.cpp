#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	ifstream in("E://class two.txt", ifstream::in);
	ofstream out("E://class two.txt", ofstream::app);
	out.put('\n');
	////����ʵ�ְ��ļ��еĶ�Ӧ�ַ��޸��ٷŻ�ȥ,�����Ƿ����ļ�ĩβ
	//int ch;
	//while ((ch = in.get()) != EOF)
	//{
	//	if (ch == '1') ch = 'a';
	//	out.put(ch);
	//}
	char sink[100];
	size_t size = 100;
	while (in.getline(sink, size, '\n'))//�޷������������
	{
		size_t len = strlen(sink);//���ӵĻ��������sink�������
		for (size_t i = 0; i < len; ++i)
		{
			if (sink[i] == ' ') cout << '*' << ends;
			
			cout << sink[i] << " ";
		}
		cout << '\n';
	}
}