#include "Date.h"

int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//ƽ������

//�ж��Ƿ�Ϊ����
bool Date::leapYear(const int &year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

//����2010��1��1�ն�����
int Date::fromDays()
{
	int armYear = 2010,
		armMonth = 1,
		armDays = 1;

	int intervalYear = year - armYear + 1;
	int sumDays = 0;	
	for (int i = 0; i < intervalYear; ++i) {
		int temptYear = armYear + i;
		if (leapYear(temptYear)) {
			sumDays += 366;
		}
		else sumDays += 365;
	}

	if (leapYear(year)) monthDays[2] = 29;//����2����29��
	for (int i = 0; i < month; ++i) {
		sumDays += monthDays[i + 1];
	}
	monthDays[2] = 28;//�ָ�2��Ϊƽ��28��

	sumDays += days;
	return sumDays;
}

//�жϽ����Ƿ�������
bool Date::fishInWork()
{
	int Days = fromDays() % 5;
	if (1 <= Days && Days <= 3)
		return true;
	else
		return false;
}