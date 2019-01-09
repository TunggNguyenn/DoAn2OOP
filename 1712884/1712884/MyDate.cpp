#include "MyDate.h"
#include <iomanip>

void MyDate::nhap()
{
	do
	{
		cout << "Ngay: ";
		cin >> this->day;
		if (this->day > 31)
		{
			cout << "Ngay khong phu hop. Vui long nhap lai.\n\n";
		}
	} while (this->day > 31);

	do
	{
		cout << "Thang: ";
		cin >> this->month;
		if ((this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) && (this->day == 31))
		{
			cout << "Thang khong phu hop. Vui long nhap lai.\n\n";
		}
		else if (this->month == 2 && this->day > 28)
		{
			cout << "Thang khong phu hop. Vui long nhap lai.\n\n";
		}
		else if (this->month > 12)
		{
			cout << "Thang khong phu hop. Vui long nhap lai.\n\n";
		}
	} while (this->month > 12);

	do
	{
		cout << "Nam: ";
		cin >> this->year;
		if (((this->year % 4 == 0) && (this->year % 100 != 0)) || (this->year % 400 == 0) && this->month == 2 && this->day == 29)
		{
			cout << "Nam khong phu hop. Vui long nhap lai.\n\n";
		}
	} while (((this->year % 4 == 0) && (this->year % 100 != 0)) || (this->year % 400 == 0) && this->month == 2 && this->day == 29);
	cin.ignore();
}

void MyDate::xuat()
{
	cout << this->day << "/" << this->month << "/" << this->year;
}

int MyDate::distance(const MyDate & myDate)
{
	int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (this->year == myDate.year)
	{
		if (this->month == myDate.month)
		{
			return myDate.day - this->day;
		}
		else
		{
			if (((this->year % 4 == 0) && (this->year % 100 != 0)) || (this->year % 400 == 0) && this->month == 2)
			{
				return months[this->month - 1] - this->day + 1 + myDate.day;
			}
			else
			{
				return months[this->month - 1] - this->day + myDate.day;
			}
		}
	}
	else
	{
		return months[11] - this->day + myDate.day;
	}
}

istream & operator>>(istream & input, MyDate & myDate)
{
	input >> myDate.day;
	input.ignore();
	input >> myDate.month;
	input.ignore();
	input >> myDate.year;
	input.ignore();
	return input;
}

ostream & operator<<(ostream & output, const MyDate & myDate)
{
	//output << setw(15) << right;
	output << myDate.day << "/" << myDate.month << "/" << myDate.year;
	return output;
}
