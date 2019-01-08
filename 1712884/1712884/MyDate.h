#ifndef __MYDATE_H__
#define __MYDATE_H__
#include <iostream>
using namespace std;

class MyDate
{
private:
	int day;
	int month;
	int year;
public:
	MyDate() {};
	~MyDate() {};

	void nhap();
	void xuat();

	int distance(const MyDate& myDate);


	friend istream& operator>>(istream& input, MyDate& myDate);
	friend ostream& operator<<(ostream& output, const MyDate& myDate);
};


#endif // !__MYDATE_H__
