#ifndef DATA_H
#define DATA_H
extern int monthDays[13];
class Date
{
private :
	int year;
	int month;
	int days;
	
public:
	Date() = default;
	Date(const int &_year, const int &_month, const int &_days) :
		year(_year), month(_month), days(_days) {}

	bool leapYear(const int &year);//�ж��Ƿ�Ϊ����
	int fromDays();//����2010��1��1�ն�����
	bool fishInWork();//�жϽ����Ƿ�������
};

#endif
