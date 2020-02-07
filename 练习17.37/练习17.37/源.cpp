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
	////可以实现把文件中的对应字符修改再放回去,不过是放在文件末尾
	//int ch;
	//while ((ch = in.get()) != EOF)
	//{
	//	if (ch == '1') ch = 'a';
	//	out.put(ch);
	//}
	char sink[100];
	size_t size = 100;
	while (in.getline(sink, size, '\n'))//无法正常输出汉字
	{
		size_t len = strlen(sink);//不加的话会把整个sink数组输出
		for (size_t i = 0; i < len; ++i)
		{
			if (sink[i] == ' ') cout << '*' << ends;
			
			cout << sink[i] << " ";
		}
		cout << '\n';
	}
}