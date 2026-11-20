#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cctype>
#include <ctime>
#include<fstream>
#include"clsString.h"
using namespace std;
class clsDate
{
private:
	short year;
	short month;
	short day;
	short hour;
	short minute;
	short second;
	static bool firstDay(clsDate date)
	{
		return date.day == 1;
	}
	static bool firstMonth(short month)
	{
		return month == 1;
	}
public:
	void setYear(short year)
	{
		this->year = year;
	}
	short getYear()
	{
		return year;
	}
	void setMonth(short month)
	{
		this->month = month;
	}
	short getMonth()
	{
		return month;
	}
	void setDay(short day)
	{
		this->day = day;
	}
	short getDay()
	{
		return day;
	}
	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;
	}
	clsDate(short day, short month, short year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	clsDate(string date)
	{
		vector<string>vdate = clsString::split(date, "/");
		day = stoi(vdate[0]);
		month = stoi(vdate[1]);
		year = stoi(vdate[2]);
	}
	clsDate(int numberOfDayInYear, short year)
	{
		clsDate date = dateFromDayOrderInAyear(numberOfDayInYear, year);
		day = date.day;
		month = date.month;
		year = date.year;
	}
	static bool isLeapYear(short year)
	{
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}
	bool isLeapYear()
	{
		return isLeapYear(year);
	}
	static int NumberOfDaysInYear(short year)
	{
		return isLeapYear(year) ? 366 : 365;
	}
	int NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(year);
	}
	static int NumberOfHoursInYear(short year)
	{
		return NumberOfDaysInYear(year) * 24;
	}
	int NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(year);
	}
	static int NumberOfMinutesInYear(short year)
	{
		return NumberOfHoursInYear(year) * 60;
	}
	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(year);
	}
	static int NumberOfSecondsInYear(short year)
	{
		return NumberOfMinutesInYear(year) * 60;
	}
	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(year);
	}
	static short NumberOfHoursInAMonth(short year, short month)
	{
		return daysOfMonth(year, month) * 24;
	}
	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(year, month);
	}
	static int NumberOfMinutesInAMonth(short year, short month)
	{
		return NumberOfHoursInAMonth(year, month) * 60;
	}
	int NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(year, month);
	}
	static int NumberOfSecondsInAMonth(short year, short month)
	{
		return NumberOfMinutesInAMonth(year, month) * 60;
	}
	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(year, month);
	}
	static short daysOfMonth(short year, short month)
	{
		if (month < 1 || month>12)
			return 0;
		short arrmonthdays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return  month == 2 ? isLeapYear(year) ? 29 : 28 : arrmonthdays[month - 1];
	}
	short daysOfMonth()
	{
		return daysOfMonth(year, month);
	}
	static clsDate getSystemDate()
	{
		/*return clsDate();*/
		time_t t = time(0);
		tm* now = localtime(&t);
		short day, month, year;
		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;
		return clsDate(day, month, year);
	}
	static string getSystemDateTimeString()
	{
		/*return clsDate();*/
		time_t t = time(0);
		tm* now = localtime(&t);
		short day, month, year, hour, minute, second;
		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;
		hour = now->tm_hour;
		minute = now->tm_min;
		second = now->tm_sec;
		return  to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " - " + to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
	}
	static clsDate stringtoDate(string stringDate)
	{
		return clsDate(stringDate);
	}
	static bool isValidDate(clsDate date)
	{
		return (date.year > 0 && date.day >= 1 && daysOfMonth(date.year, date.month) >= date.day);
	}
	bool isValid()
	{
		return isValidDate(*this);
	}
	static string dateToString(clsDate date)
	{
		return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
	}
	string dateToString()
	{
		return dateToString(*this);
	}
	static void print(clsDate date)
	{
		if (isValidDate(date))
		{
			cout << dateToString(date) << endl;
		}
		else
		{
			cout << "this is inValid date\n";
		}
	}
	void print()
	{
		cout << dateToString() << endl;
	}
	static clsDate dateFromDayOrderInAyear(int dateOrder, int year)
	{
		clsDate date;
		date.year = year;
		date.month = 1;
		short remainingDay = dateOrder;
		while (true)
		{
			short monthlyDay = daysOfMonth(year, date.month);
			if (remainingDay > monthlyDay)
			{
				remainingDay -= monthlyDay;
				date.month++;
			}
			else
			{
				date.day = remainingDay;
				break;
			}
		}
		return date;
	}
	static short DayOfWeekOrder(short year, short month, short day)
	{
		short y, m, a;
		a = (14 - month) / 12;
		m = month + 12 * a - 2;
		y = year - a;
		return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
	}
	static short DayOfWeekOrder(clsDate date)
	{
		return DayOfWeekOrder(date.year, date.month, date.day);
	}
	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(*this);
	}
	static string returnMonth(short indexOfMonth)
	{
		string arrDay[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return arrDay[indexOfMonth - 1];
	}
	string returnMonth()
	{
		return returnMonth(month);
	}
	static void PrintMonthCalendar(short Year, short Month)
	{
		if (Month < 1 || Month>12)
		{
			cout << "invalid month";
			return;
		}
		int NumberOfDays;
		int current = DayOfWeekOrder(Year, Month, 1);
		NumberOfDays = daysOfMonth(Year, Month);
		printf("\n _______________%s_______________\n\n",
			returnMonth(Month).c_str());
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		int i = 1;
		for (i = 1; i <= current; i++)
		{
			printf("     ");
		}
		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (i++ == 7)
			{
				i = 1;
				printf("\n");
			}
		}
		printf("\n ________________________________\n\n");
	}
	void printMonthCalender()
	{
		PrintMonthCalendar(year, month);
	}
	static void printYearCalender(short year)
	{
		printf("\n __________________________________\n\n");
		printf("            calender %d\n", year);
		printf(" __________________________________\n\n");
		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(year, i);
		}
	}
	void printYearCalender()
	{
		printYearCalender(year);
	}
	static bool lastDay(clsDate date)
	{
		return date.day == daysOfMonth(date.year, date.month);
	}
	bool lastDay()
	{
		return lastDay(*this);
	}
	static bool lastMonth(short month)
	{
		return month == 12;
	}
	bool lastMonth()
	{
		return lastMonth(month);
	}
	static bool isDate1BeforeDate2(clsDate date1, clsDate date2)
	{
		if (date1.year < date2.year)
		{
			return true;
		}
		else if (date1.year == date2.year)
		{
			if (date1.month < date2.month)
			{
				return true;
			}
			else if (date1.month > date2.month)
			{
				return false;
			}
			else
			{
				return date1.day < date2.day;
			}
		}
		return false;
		//return false;
		//return (date1.year < date2.year) ? true : (date1.year == date2.year) ? (date1.month < date2.month) ? true : (date1.month > date2.month) ? false : (date1.day < date2.day) ? true : false : false;
		//return (date1.year < date2.year) ? true : (date1.year == date2.year) ? (date1.month < date2.month) ? true:(date1.month==date2.month)?(date1.day<date2.day):false:false;
	}
	bool isDateBeforeDate2(clsDate date2)
	{
		return isDate1BeforeDate2(*this, date2);
	}
	static bool isDate1EquelsDate2(clsDate date1, clsDate date2)
	{
		return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
	}
	bool isDateEquelsDate2(clsDate date2)
	{
		return isDate1EquelsDate2(*this, date2);
	}
	static clsDate increaseDateByOneDay(clsDate date)
	{
		if (lastDay(date) && lastMonth(date.month))
		{
			date.day = 1;
			date.month = 1;
			date.year++;
		}
		else if (lastDay(date) && !lastMonth(date.month))
		{
			date.day = 1;
			date.month++;
		}
		else if (!lastDay(date))
		{
			date.day += 1;
		}
		return date;
	}
	void increaseDateByOneDay()
	{
		*this = increaseDateByOneDay(*this);
	}
	static void swapDates(clsDate& date1, clsDate& date2)
	{
		clsDate tempDate;
		tempDate = date1;
		date1 = date2;
		date2 = tempDate;
	}
	void swapDates(clsDate& date2)
	{
		swapDates(*this, date2);
	}
	static int diffInDays(clsDate date1, clsDate date2, bool includeEndDay = false)
	{
		if (isDate1EquelsDate2(date1, date2))
		{
			return includeEndDay ? 1 : 0;
		}
		int days = 0;
		short flagValue = 1;
		if (!isDate1BeforeDate2(date1, date2))
		{
			swapDates(date1, date2);
			flagValue = -1;
		}
		while (isDate1BeforeDate2(date1, date2))
		{
			days++;
			date1 = increaseDateByOneDay(date1);
		}
		return includeEndDay ? ++days * flagValue : days * flagValue;
	}
	static int calculateMyAgeInDays(clsDate myBirthDate)
	{
		return diffInDays(myBirthDate, getSystemDate(), true);
	}
	int diffInDays(clsDate date2, bool includeEndDay)
	{
		return diffInDays(*this, date2, includeEndDay);
	}
	static clsDate increaseDateByXDays(clsDate& date, int x)
	{
		for (int i = 1; i <= x; i++)
		{
			date = increaseDateByOneDay(date);
		}
		return date;
	}
	void increaseDateByXDays(int x)
	{
		increaseDateByXDays(*this, x);
	}
	static clsDate increaseDateByOneWeek(clsDate& date)/*clsDate date,*/
	{
		date = increaseDateByXDays(date, 7);
		return date;
	}
	void increaseDateByOneWeek()
	{
		//*this=increaseDateByOneWeek(*this);
		increaseDateByOneWeek(*this);
	}
	static clsDate increaseDateByXWeeks(clsDate& date, int x)
	{
		for (int i = 1; i <= x; i++)
		{
			date = increaseDateByOneWeek(date);
		}
		return date;
	}
	void increaseDateByXWeeks(int x)
	{
		increaseDateByXWeeks(*this, x);
	}
	static clsDate increaseDateByOneMonth(clsDate& date)
	{/*
	 // If the date is the last day of February,
	 // move to the last day of the next month.
		if (date.month == 2 && lastDay(date))
		{
			date.month += 1;
			if (date.month > 12)
			{
				date.month = 1;
				date.year++;
			}
			date.day = daysOfMonth(date.year, date.month);
			return date;
		}*/
		date.month += 1;
		if (date.month > 12)
		{
			date.month = 1;
			date.year++;
		}
		int NumberOfDaysOfMonth = daysOfMonth(date.year, date.month);
		if (date.day > NumberOfDaysOfMonth)
		{
			date.day = NumberOfDaysOfMonth;
		}
		return date;
	}
	void increaseDateByOneMonth()
	{
		increaseDateByOneMonth(*this);
	}
	static clsDate increaseDateByXMonths(clsDate& date, int x)
	{
		short originalDay = date.day;
		for (int i = 1; i <= x; i++)
		{
			date = increaseDateByOneMonth(date);
		}
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		date.day = (originalDay <= numberOfDaysInCurrentMonth) ? originalDay : numberOfDaysInCurrentMonth;
		return date;
	}
	void increaseDateByXMonths(int x)
	{
		increaseDateByXMonths(*this, x);
	}
	static clsDate increaseDateByOneYear(clsDate& date)
	{
		date.year++;
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	void increaseDateByOneYear()
	{
		increaseDateByOneYear(*this);
	}
	static clsDate increaseDateByXYears(clsDate& date, int x)
	{
		date.year = date.year + x;
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	void increaseDateByXYears(int x)
	{
		increaseDateByXYears(*this, x);
	}
	static clsDate increaseDateByOneDecade(clsDate& date)
	{
		date.year = date.year + 10;
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	void increaseDateByOneDecade()
	{
		increaseDateByOneDecade(*this);
	}
	static clsDate increaseDateByXDecades(clsDate& date, int x)
	{
		date.year = date.year + 10 * x;
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	void increaseDateByXDecades(int x)
	{
		increaseDateByXDecades(*this, x);
	}
	static clsDate increaseDateByOneCentury(clsDate& date)
	{
		date.year += 100;
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	void increaseDateByOneCentury()
	{
		increaseDateByOneCentury(*this);
	}
	static clsDate increaseDateByOneMillennium(clsDate& date)
	{
		date.year = date.year + 1000;
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	void increaseDateByOneMillennium()
	{
		increaseDateByOneMillennium(*this);
	}
	static clsDate decreaseDateByOneDay(clsDate date)
	{
		if (firstDay(date) && firstMonth(date.month))
		{
			date.day = 31;
			date.month = 12;
			date.year--;
		}
		else if (firstDay(date) && !firstMonth(date.month))
		{
			date.month--;
			date.day = daysOfMonth(date.year, date.month);
		}
		else if (!firstDay(date))
		{
			date.day -= 1;
		}
		return date;
	}
	void decreaseDateByOneDay()
	{
		*this = decreaseDateByOneDay(*this);
	}
	static clsDate decreaseDateByXDays(clsDate& date, short days)
	{
		for (int i = 1; i <= days; i++)
		{
			date = decreaseDateByOneDay(date);
		}
		return date;
	}
	void decreaseDateByXDays(short days)
	{
		decreaseDateByXDays(*this, days);
	}
	static clsDate decreaseDateByOneWeek(clsDate& date)
	{
		date = decreaseDateByXDays(date, 7);
		return date;
	}
	void decreaseDateByOneWeek()
	{
		decreaseDateByOneWeek(*this);
	}
	static clsDate decreaseDateByXWeeks(clsDate& date, short weeks)
	{
		for (int i = 1; i <= weeks; i++)
		{
			date = decreaseDateByOneWeek(date);
		}
		return date;
	}
	void decreaseDateByXWeeks(short weeks)
	{
		decreaseDateByXWeeks(*this, weeks);
	}
	static clsDate decreaseDateByOneMonth(clsDate& date)
	{
		/*date.month -= 1;
		if (date.month ==0)
		{
			date.month = 12;
			date.year--;
		}*/
		if (date.month == 1)
		{
			date.month = 12;
			date.year--;
		}
		else
		{
			date.month -= 1;
		}
		int NumberOfDaysOfMonth = daysOfMonth(date.year, date.month);
		if (date.day > NumberOfDaysOfMonth)
		{
			date.day = NumberOfDaysOfMonth;
		}
		return date;
	}
	void decreaseDateByOneMonth()
	{
		decreaseDateByOneMonth(*this);
	}
	static clsDate decreaseDateByXMonths(clsDate& date, short months)
	{
		for (int i = 1; i <= months; i++)
		{
			date = decreaseDateByOneMonth(date);
		}
		return date;
	}
	void decreaseDateByXMonths(short months)
	{
		decreaseDateByXMonths(*this, months);
	}
	static clsDate decreaseDateByOneYear(clsDate& date)
	{
		date.year--;
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	void decreaseDateByOneYear()
	{
		decreaseDateByOneYear(*this);
	}
	static clsDate decreaseDateByXYears(clsDate& date, short years)
	{
		date.year -= years;
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	void decreaseDateByXYears(short years)
	{
		decreaseDateByXYears(*this, years);
	}
	static clsDate decreaseDateByOneDecade(clsDate& date)
	{
		date.year -= 10;
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	void decreaseDateByOneDecade()
	{
		decreaseDateByOneDecade(*this);
	}
	static clsDate decreaseDateByXDecades(clsDate& date, int decades)
	{
		date.year -= 10 * decades;
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	void decreaseDateByXDecades(int decades)
	{
		decreaseDateByXDecades(*this, decades);
	}
	static clsDate decreaseDateByOneCentury(clsDate& date)
	{
		date.year -= 100;
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	void decreaseDateByOneCentury()
	{
		decreaseDateByOneCentury(*this);
	}
	static clsDate decreaseDateByOneMillennium(clsDate& date)
	{
		date.year -= 1000;
		short numberOfDaysInCurrentMonth = daysOfMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}
	void decreaseDateByOneMillennium()
	{
		decreaseDateByOneMillennium(*this);
	}
	static string returnDay(short year, short month, short day)
	{
		string arrDay[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDay[DayOfWeekOrder(year, month, day)];
	}
	string returnDay()
	{
		return returnDay(year, month, day);
	}
	static bool isEndOfWeek(clsDate date)
	{
		string day = returnDay(date.year, date.month, date.year);
		return day == "Sat";
	}
	bool isEndOfWeek()
	{
		return isEndOfWeek(*this);
	}
	static bool isWeekEnd(clsDate date)
	{
		string day = returnDay(date.year, date.month, date.day);
		return day == "Fri" || day == "Sat";
	}
	bool isWeekEnd()
	{
		return isWeekEnd(*this);
	}
	static bool isBusinessDay(clsDate date)
	{
		return !isWeekEnd(date);
	}
	bool isBusinessDay()
	{
		return isBusinessDay(*this);
	}
	static int calcVacationDays(clsDate date1, clsDate date2)
	{
		int days = 0;
		while (isDate1BeforeDate2(date1, date2))
		{
			if (isBusinessDay(date1))
			{
				days++;
			}
			date1 = increaseDateByOneDay(date1);
		}
		return days;
	}
	int calcVacationDays(clsDate date2)
	{
		return calcVacationDays(*this, date2);
	}
	static clsDate getVacationDate(clsDate date1, int vacationDays)
	{
		short weekEndCounter = 0;
		while (isWeekEnd(date1))
		{
			date1 = increaseDateByOneDay(date1);
		}
		for (int i = 1; i <= vacationDays + weekEndCounter; i++)
		{
			if (isWeekEnd(date1))
			{
				weekEndCounter++;
			}
			date1 = increaseDateByOneDay(date1);
		}
		while (isWeekEnd(date1))
		{
			date1 = increaseDateByOneDay(date1);
		}
		return date1;
	}
	void getVacationDate(int vacationDays)
	{
		*this = getVacationDate(*this, vacationDays);
	}
	static bool isDate1AfterDate2(clsDate date1, clsDate date2)
	{
		return !(isDate1BeforeDate2(date1, date2)) && !(isDate1EquelsDate2(date1, date2));
	}
	bool isDateAfterDate2(clsDate date2)
	{
		return isDate1AfterDate2(*this, date2);
	}
	enum enCompareDates { BEFORE = -1, EQUEL = 0, AFTER = 1 };
	static enCompareDates compareDates(clsDate date1, clsDate date2)
	{
		if (isDate1BeforeDate2(date1, date2))
		{
			return enCompareDates::BEFORE;
		}
		else if (isDate1EquelsDate2(date1, date2))
		{
			return enCompareDates::EQUEL;
		}
		return enCompareDates::AFTER;
	}
	enCompareDates compareDates(clsDate date2)
	{
		return compareDates(*this, date2);
	}
	static string formatDate(clsDate date, string format = "dd/mm/yyyy")
	{
		string formattedDateString = "";
		formattedDateString = clsString::replaceWordUsingBuiltInFunction(format, "dd", to_string(date.day));
		formattedDateString = clsString::replaceWordUsingBuiltInFunction(formattedDateString, "mm", to_string(date.month));
		formattedDateString = clsString::replaceWordUsingBuiltInFunction(formattedDateString, "yyyy", to_string(date.year));
		return formattedDateString;
	}
	string formatDate(string format = "dd/mm/yyyy")
	{
		string date = formatDate(*this, format);
		return date;
	}
	static short daysFromTheBeginningOfyear(short year, short month, short day)
	{
		int sumOfDays = 0;
		for (int i = 1; i <= month - 1; i++)
		{
			sumOfDays += daysOfMonth(year, i);
		}
		sumOfDays += day;
		return sumOfDays;
	}
	short daysFromTheBeginningOfyear()
	{
		return daysFromTheBeginningOfyear(year, month, day);
	}
	static clsDate addDaysToDate(clsDate date, int addingDays)
	{
		if (addingDays < 0 || addingDays == 0)
		{
			return date;
		}
		int remainingDay = addingDays + daysFromTheBeginningOfyear(date.year, date.month, date.day);
		int monthlyDays = 0;
		date.month = 1;
		while (true)
		{
			short monthlyDay = daysOfMonth(date.year, date.month);
			if (remainingDay > monthlyDay)
			{
				remainingDay -= monthlyDay;
				date.month++;
				if (date.month > 12)
				{
					date.month = 1;
					date.year++;
				}
			}
			else
			{
				date.day = remainingDay;
				break;
			}
		}
		return date;
	}
	void addDaysToDate(int addingDays)
	{
		*this = addDaysToDate(*this, addingDays);
	}
	static short daysUntilTheEndOfWeek(clsDate date)
	{
		int indexOfDay = DayOfWeekOrder(date);
		return 6 - indexOfDay;
	}
	short daysUntilTheEndOfWeek()
	{
		return daysUntilTheEndOfWeek(*this);
	}
	static short daysUntilTheEndOfMonth(clsDate date)
	{
		//sDate oldDate = date;
		//date.day = daysOfMonth(date.year, date.month);
		//return (date.day - oldDate.day) + 1;
		clsDate endOfMonthDate;
		endOfMonthDate.year = date.year;
		endOfMonthDate.month = date.month;
		endOfMonthDate.day = daysOfMonth(date.year, date.month);
		return diffInDays(date, endOfMonthDate, true);
	}
	short daysUntilTheEndOfMonth()
	{
		return daysUntilTheEndOfMonth(*this);
	}
	static short daysUntilTheEndOfYear(clsDate date)
	{
		/*short dayFromTheBeginningOFYear = daysFromTheBeginningOfyear(date);
		short yearDays = NumberOfDaysInYear(date.year);
		return (yearDays - dayFromTheBeginningOFYear) + 1;*/
		clsDate endOfYearDate;
		endOfYearDate.day = 31;
		endOfYearDate.month = 12;
		endOfYearDate.year = date.year;
		return diffInDays(date, endOfYearDate, true);
	}
	short daysUntilTheEndOfYear()
	{
		return daysUntilTheEndOfYear(*this);
	}
	static int calcBusinessDays(clsDate date1, clsDate date2)
	{
		int days = 0;
		while (isDate1BeforeDate2(date1, date2))
		{
			if (isBusinessDay(date1))
			{
				days++;
			}
			date1 = increaseDateByOneDay(date1);
		}
		return days;
	}
	int calcBusinessDays(clsDate date2)
	{
		return calcBusinessDays(*this, date2);
	}
};
