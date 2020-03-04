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

	bool leapYear(const int &year);//判断是否为闰年
	int fromDays();//距离2010年1月1日多少天
	bool fishInWork();//判断今天是否在摸鱼
};

#endif
