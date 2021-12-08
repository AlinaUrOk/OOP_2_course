// laba_oop_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*Інформація про дату (рік, місяць, день) та час (години, хвилини, секунди). Перевірка правильності дати та часу відповідно до григоріанського календаря.
Арифметика моментів часу: різниця між двома моментами часу у заданих одиницях, додавання чи віднімання такої різниці до заданого моменту часу.

Обчислення дня тижня для заданої дати.*/

#include <iostream>

class Date {
private:
	bool isLeapYear;
	int maxDay()const;
	bool isLeap(int)const;
	int countDayYear;

	void dayOfTheWeek();
	void counterOfDaysAtYear();
	int indexTheDayOfWeek;
	void createNewDataBySec(long long current_sec);
public:
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	Date(int year, int month, int day, int hour, int min, int sec);
	Date(int year, int day, int month);
	Date() = default;
	void DifofTwoDates(Date& first_date, Date& second_date);
	void SumofTwoDates(Date& first_date, Date& second_date);
	long long countSecForData()const;
	void Print()
	{
		std::cout << "Your data: " << year << ", " << month << ", " << day << "   " << hour << ":" << min << ":" << sec << " "; std::cout << std::endl;
	}
};

Date::Date(int year, int month, int day, int hour, int min, int sec) {
	isLeapYear = isLeap(year);
	this->year = year;

	if (month > 12 || month <= 0) {
		std::cout << "Incorrect month" << std::endl;
		this->month = 1;
	}
	else
		this->month = month;

	if (day > maxDay()) {
		std::cout << "Incorrect day" << std::endl;
		this->day = 1;
	}
	else
		this->day = day;

	if (hour > 24 || hour < 0) {
		std::cout << "Incorrect hour " << std::endl;
		this->hour = 1;
	}
	else
		this->hour = hour;
	if (min > 60 || min < 00) {
		std::cout << "Incorrent minutes" << std::endl;
		this->min = 1;
	}
	else
		this->min = min;
	if (sec > 60 || sec < 0) {
		std::cout << "Incorrect sec" << std::endl;
		this->sec = 1;
	}
	else
		this->sec = sec;


}

Date::Date(int year, int month, int day) {
	isLeapYear = isLeap(year);

	this->year = year;

	if (month > 12 || month <= 0) {
		std::cout << "Incorrect month" << std::endl;;
		this->month = 1;
	}
	else
		this->month = month;

	if (day > maxDay()) {
		std::cout << "Incorrect day" << std::endl;
		this->day = 1;
	}
	else
		this->day = day;

	hour = min = sec = 1;


}

bool Date::isLeap(int y)const {
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}

int Date::maxDay() const {
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear)
		days[1] = 29;
	return days[month - 1];
}


//преобразование даты в секунды
long long Date::countSecForData()const {
	long long data = day * 86400 + hour * 3600 + min * 60 + sec;
	for (int i = 1; i < year; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			data += 366 * 86400;
		else
			data += 365 * 86400;

	}
	std::cout << "Date in second: " << data; std::cout << std::endl;
	return data;
}

void Date::DifofTwoDates(Date& first_date, Date& second_date)
{
	long long date_one = first_date.countSecForData();
	long long date_two = second_date.countSecForData();
	long long dif_date;
	if (date_one > date_two)
	{
		dif_date = date_one - date_two;
	}
	else
	{
		dif_date = date_two - date_one;
	}
	std::cout << "Date in second: " << dif_date; std::cout << std::endl;
	second_date.createNewDataBySec(dif_date);
}

void Date::SumofTwoDates(Date& first_date, Date& second_date)
{
	long long date_one = first_date.countSecForData();
	long long date_two = second_date.countSecForData();
	long long sum_date;
	sum_date = date_one + date_two;


	std::cout << "Sum in second: " << sum_date; std::cout << std::endl;
	second_date.createNewDataBySec(sum_date);
}

void Date::createNewDataBySec(long long current_sec) {
	year = 0;
	while (current_sec >= 365 * 24 * 60 * 60) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			if (current_sec >= 366 * 24 * 60 * 60) {
				current_sec -= 366 * 24 * 60 * 60;
			}
		}
		else {
			current_sec -= 365 * 24 * 60 * 60;
		}
		year++;
	}
	isLeapYear = isLeap(year);

	int counter_days = current_sec % 60 % 60 % 24;
	day = counter_days;

	sec = current_sec % 60;
	current_sec %= 60;
	min = current_sec % 60;
	current_sec %= 60;
	hour = current_sec % 24;
	current_sec %= 24;
	month = current_sec % 12;

}

int main()
{
	int year, month, day, hour, min, sec;
	std::cout << "Enter date"; std::cout << std::endl; std::cout << "Year: ";
	std::cin >> year; std::cout << "Month: ";
	std::cin >> month; std::cout << "Day: ";
	std::cin >> day;  std::cout << "Hour: ";
	std::cin >> hour;  std::cout << "Minute: ";
	std::cin >> min;  std::cout << "Second: ";
	std::cin >> sec;
	Date date(year, month, day, hour, min, sec);
	date.Print();
	/*date.countSecForData();*/
	std::cout << "_____________________________________________________________" << std::endl;
	int year1, month1, day1, hour1, min1, sec1;
	std::cout << "Enter second date"; std::cout << std::endl; std::cout << "Year: ";
	std::cin >> year1; std::cout << "Month: ";
	std::cin >> month1; std::cout << "Day: ";
	std::cin >> day1;  std::cout << "Hour: ";
	std::cin >> hour1;  std::cout << "Minute: ";
	std::cin >> min1;  std::cout << "Second: ";
	std::cin >> sec1;
	Date date1(year1, month1, day1, hour1, min1, sec1);
	date1.Print();
	//date1.countSecForData();
	date1.DifofTwoDates(date, date1);
	date1.Print();
	std::cout << "_____________________________________________________________" << std::endl;
	date1.DifofTwoDates(date, date1);
	date1.Print();


	/*std::cout << "_____________________________________________________________" << std::endl;
	date1.SumofTwoDates(date, date1);
	date1.Print();*/
}