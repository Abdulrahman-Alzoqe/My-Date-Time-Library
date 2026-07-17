#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <string>
#include "ClsString.h"

using namespace std;

class ClsDate
{
	struct sDate
	{
		short _Day = 0;
		short _Month = 0;
		short _Year = 0;
	};

	struct sPeriod
	{
		sDate Date1;
		sDate Date2;
	};

	sDate Date1;
	sPeriod Period1;

	enum Result { Before = -1, Equal = 0, After = 1 };

public:

	ClsDate()
	{
		Date1 = GetSystemDate();
	}

	ClsDate(string S1)
	{
		Date1 = StringToDate(S1);
	}

	ClsDate(short Day, short Month, short Year)
	{
		Date1._Day = Day;
		Date1._Month = Month;
		Date1._Year = Year;
	}

	ClsDate(short Days, short Year)
	{
		Date1 = GetDateByDays(Days, Year);
	}

	void SetDay(short Day) {
		Date1._Day = Day;
	}
	short GetDay() {
		return Date1._Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;
	void SetMonth(short Month) {
		Date1._Month = Month;
	}
	short GetMonth() {
		return Date1._Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short
		Month;
	void SetYear(short Year) {
		Date1._Year = Year;
	}
	short GetYear() 
	{
		return Date1._Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;

	static bool CheckLeapYear(short Year)
	{
		return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
	}

	bool CheckLeapYear()
	{
		return CheckLeapYear(Date1._Year);
	}

	static int NumberOfDaysInYear(short Year)
	{
		return CheckLeapYear(Year) ? 366 : 365;
	}

	int NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(Date1._Year);
	}

	static int NumberOfHoursInYear(short Year)
	{
		return NumberOfDaysInYear(Year) * 24;
	}

	int NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(Date1._Year);
	}

	static int NumberOfMinutesInYear(short Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}

	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(Date1._Year);
	}

	static int NumberOfSecondsInYear(short Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}

	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(Date1._Year);
	}

	static short NumberOfDaysInMonth(short Month, short Year)
	{
		switch (Month)
		{
		case 1:
			return 31;
		case 2:
			return CheckLeapYear(Year) ? 29 : 28;
		case 3:
			return 31;
		case 4:
			return 30;
		case 5:
			return 31;
		case 6:
			return 30;
		case 7:
			return 31;
		case 8:
			return 31;
		case 9:
			return 30;
		case 10:
			return 31;
		case 11:
			return 30;
		case 12:
			return 31;
		default:
			return 0;
		}
	}

	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(Date1._Month, Date1._Year);
	}

	static int NumberOfHoursInMonth(short Month, short Year)
	{
		return NumberOfDaysInMonth(Month, Year) * 24;
	}

	int NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(Date1._Month, Date1._Year);
	}

	static int NumberOfMinutesInMonth(short Month, short Year)
	{
		return NumberOfHoursInMonth(Month, Year) * 60;
	}

	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(Date1._Month, Date1._Year);
	}

	static int NumberOfSecondsInMonth(short Month, short Year)
	{
		return NumberOfMinutesInMonth(Month, Year) * 60;
	}

	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(Date1._Month, Date1._Year);
	}

	static short GetDayNumber(short Year, short Month, short Day)
	{
		short a = (14 - Month) / 12;
		short m = Month + 12 * a - 2;
		short y = Year - a;

		short d = (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

		return d;
	}

	short GetDayNumber()
	{
		return GetDayNumber(Date1._Year, Date1._Month, Date1._Day);
	}

	static void PrintMonthCalender(short Year, short Month)
	{
		string Months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		cout << "\n__________________" << Months[Month - 1] << "__________________\n\n";
		cout << "Sun   Mon   Tue   Wed   Thu   Fri   Sat";
		short FirstDay = GetDayNumber(Year, Month, 1);
		short NumberOfDays = NumberOfDaysInMonth(Month, Year);
		cout << "\n";

		for (short i = 0; i < NumberOfDays + FirstDay; i++)
		{
			if (i < FirstDay)
				cout << setw(6) << " ";
			else
				cout << setw(6) << left << i - FirstDay + 1;

			if ((i + 1) % 7 == 0)
				cout << "\n";
		}
		cout << "\n_______________________________________\n\n";

	}

	void PrintMonthCalender()
	{
		PrintMonthCalender(Date1._Year, Date1._Month);
	}

	static void PrintYearCalender(short Year)
	{
		cout << "\n_______________________________________\n\n";
		cout << "             " << Year << " Calender\n\n";
		cout << "_______________________________________\n\n";

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalender(Year, i);
		}
	}

	void PrintYearCalender()
	{
		PrintYearCalender(Date1._Year);
	}

	static short CalculateDaysInYear(short Day, short Month, short Year)
	{
		short SumOfDays = 0;

		for (short i = 1; i <= Month - 1; i++)
		{
			SumOfDays += NumberOfDaysInMonth(i, Year);
		}
		SumOfDays += Day;

		return SumOfDays;
	}

	short CalculateDaysInYear()
	{
		return CalculateDaysInYear(Date1._Day, Date1._Month, Date1._Year);
	}

	static void ShowDateByDays(short Days, short Year)
	{
		short Month = 1;
		short TotalDays = Days;

		while (TotalDays > NumberOfDaysInMonth(Month, Year))
		{
			TotalDays -= NumberOfDaysInMonth(Month, Year);
			Month++;
		}

		short Day = TotalDays;

		cout << "Date of [" << Days << "] : "
			<< Day << "/" << Month << "/" << Year;
	}

	static sDate DateAddDays(short Days, sDate &Date)
	{
		short RemainingDays = Days +
			CalculateDaysInYear(Date._Day, Date._Month, Date._Year);
		short MonthDays = 0;
		Date._Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Date._Month, Date._Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Year++;
				}
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	sDate DateAddDays(short Days)
	{
		return DateAddDays(Days, Date1);
	}

	static bool IsDate1MoreThanDate2(sDate Date1, sDate Date2)
	{
		return (Date1._Year > Date2._Year) ? true : ((Date1._Year == Date2._Year) ? ((Date1._Month > Date2._Month) ? true : ((Date1._Month == Date2._Month) ? ((Date1._Day > Date2._Day) ? true : false) : false)) : false);
	}

	bool IsDateMoreThanDate2(sDate Date2)
	{
		return IsDate1MoreThanDate2(Date1, Date2);
	}

	static bool IsDate1EqwalDate2(sDate Date1, sDate Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}

	bool IsDate1EqwalDate2(sDate Date2)
	{
		return IsDate1EqwalDate2(Date1, Date2);
	}

	static bool IsLastDayInMonth(short Day, short Month, short Year)
	{
		return (Day == NumberOfDaysInMonth(Month, Year));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(Date1._Day, Date1._Month, Date1._Year);
	}

	static bool lastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	bool lastMonthInYear()
	{
		return lastMonthInYear(Date1._Month);
	}

	static short NumberOfDaysFromBeginingOfTheYear(short Day, short Month, short Year)
	{
		short SumOfDays = 0;

		for (short i = 1; i <= Month - 1; i++)
		{
			SumOfDays += NumberOfDaysInMonth(i, Year);
		}
		SumOfDays += Day;

		return SumOfDays;
	}

	short NumberOfDaysFromBeginingOfTheYear()
	{
		return NumberOfDaysFromBeginingOfTheYear(Date1._Day, Date1._Month, Date1._Year);
	}

	static sDate GetDateByDays(short Days, short Year)
	{
		sDate Date;
		short Month = 1;
		short TotalDays = Days;

		while (TotalDays > NumberOfDaysInMonth(Month, Year))
		{
			TotalDays -= NumberOfDaysInMonth(Month, Year);
			Month++;
		}

		Date._Day = TotalDays;
		Date._Month = Month;
		Date._Year = Year;

		return Date;
	}

	sDate GetDateByDays()
	{
		return GetDateByDays(Date1._Day, Date1._Year);
	}

	static sDate IncreaseDateByDay(sDate &Date)
	{
		int TotalDays = NumberOfDaysFromBeginingOfTheYear(Date._Day, Date._Month, Date._Year) + 1;

		if (Date._Month == 12 && Date._Day == 31)
		{
			Date._Day = 1;
			Date._Month = 1;
			Date._Year += 1;

			return Date;
		}
		else
			return GetDateByDays(TotalDays, Date._Year);
	}

	sDate IncreaseDateByDay()
	{
		return IncreaseDateByDay(Date1);
	}

	static bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : (Date1._Year > Date2._Year) ? false : (Date1._Month < Date2._Month) ? true : (Date1._Month > Date2._Month) ? false : (Date1._Day < Date2._Day);
	}

	bool IsDateLessThanDate2(sDate Date2)
	{
		return IsDate1LessThanDate2(Date1, Date2);
	}

	static int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		while (IsDate1LessThanDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByDay(Date1);
		}
		return IncludeEndDay ? ++Days : Days;
	}

	int GetDifferenceInDays(sDate Date2,bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(Date1, Date2, IncludeEndDay);
	}

	static sDate GetSystemDate()
	{
		sDate Date;
		time_t t = time(0);
		tm now;
		localtime_s(&now, &t);

		Date._Year = now.tm_year + 1900;
		Date._Month = now.tm_mon + 1;
		Date._Day = now.tm_mday;
	}

	static void SwapDates(sDate& Date1, sDate& Date2)
	{
		sDate temp;

		temp._Day = Date1._Day;
		temp._Month = Date1._Month;
		temp._Year = Date1._Year;

		Date1._Year = Date2._Year;
		Date1._Day = Date2._Day;
		Date1._Month = Date2._Month;

		Date2._Day = temp._Day;
		Date2._Month = temp._Month;
		Date2._Year = temp._Year;
	}

	void SwapDates(sDate &Date2)
	{
		SwapDates(Date1, Date2);
	}

	static sDate IncreaseDateByXDays(sDate &Date, int Days)
	{
		for (int i = 0; i < Days; i++)
		{
			Date = IncreaseDateByDay(Date);
		}

		return Date;
	}

	sDate IncreaseDateByXDays(int Days)
	{
		return IncreaseDateByXDays(Date1, Days);
	}

	static sDate IncreaseDateBy1Week(sDate &Date)
	{
		Date = IncreaseDateByXDays(Date, 7);

		return Date;
	}

	sDate IncreaseDateBy1Week()
	{
		return IncreaseDateBy1Week(Date1);
	}

	static sDate IncreaseDateByXWeeks(sDate &Date, int Weeks)
	{
		for (int i = 0; i < 7 * Weeks; i++)
		{
			Date = IncreaseDateByDay(Date);
		}

		return Date;
	}

	static void Print(sDate Date)
	{
		cout << "Date : " << Date._Day << "/" << Date._Month << "/" << Date._Year << endl;
	}

	void Print()
	{
		Print(Date1);
	}

	sDate IncreaseDateByXWeeks(int Weeks)
	{
		return IncreaseDateByXWeeks(Date1, Weeks);
	}

	static sDate IncreaseDateBy1Month(sDate& Date)
	{
		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}

		short NumberOfDays = NumberOfDaysInMonth(Date._Month, Date._Year);

		if (Date._Day > NumberOfDays)
		{
			Date._Day = NumberOfDays;
		}

		return Date;
	}

	sDate IncreaseDateBy1Month()
	{
		return IncreaseDateBy1Month(Date1);
	}

	static sDate DecreaseDateByDay(sDate &Date)
	{
		int TotalDays = NumberOfDaysFromBeginingOfTheYear(Date._Day, Date._Month, Date._Year) - 1;

		if (Date._Month == 1 && Date._Day == 1)
		{
			Date._Day = 31;
			Date._Month = 12;
			Date._Year -= 1;

			return Date;
		}
		else
			return GetDateByDays(TotalDays, Date._Year);
	}

	sDate DecreaseDateByDay()
	{
		return DecreaseDateByDay(Date1);
	}

	static sDate DecreaseDateByXDays(sDate &Date, int Days)
	{
		for (int i = 0; i < Days; i++)
		{
			Date = DecreaseDateByDay(Date);
		}

		return Date;
	}

	sDate DecreaseDateByXDays(int Days)
	{
		return DecreaseDateByXDays(Date1,Days);
	}

	static sDate DecreaseDateBy1Week(sDate &Date)
	{
		Date = DecreaseDateByXDays(Date, 7);

		return Date;
	}

	sDate DecreaseDateBy1Week()
	{
		return DecreaseDateBy1Week(Date1);
	}

	static sDate DecreaseDateByXWeeks(sDate &Date, int Weeks)
	{
		for (int i = 0; i < 7 * Weeks; i++)
		{
			Date = DecreaseDateByDay(Date);
		}

		return Date;
	}

	sDate DecreaseDateByXWeeks(int Weeks)
	{
		return DecreaseDateByXWeeks(Date1,Weeks);
	}

	static sDate DecreaseDateBy1Month(sDate &Date)
	{
		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
		{
			Date._Month--;
		}

		short NumberOfDays = NumberOfDaysInMonth(Date._Month, Date._Year);

		if (Date._Day > NumberOfDays)
		{
			Date._Day = NumberOfDays;
		}

		return Date;
	}

	sDate DecreaseDateBy1Month()
	{
		return DecreaseDateBy1Month(Date1);
	}

	static sDate DecreaseDateByXMonths(sDate &Date, int Months)
	{
		for (int i = 0; i < Months; i++)
		{
			Date = DecreaseDateBy1Month(Date);
		}

		return Date;
	}

	sDate DecreaseDateByXMonths(int Months)
	{
		return DecreaseDateByXMonths(Date1,Months);
	}

	static sDate DecreaseDateBy1Year(sDate &Date)
	{
		Date._Year -= 1;

		if (Date._Month == 2 && Date._Day == 29 && !CheckLeapYear(Date._Year))
		{
			Date._Day = 28;
		}

		return Date;
	}

	sDate DecreaseDateBy1Year()
	{
		return DecreaseDateBy1Year(Date1);
	}

	static sDate DecreaseDateByXYears(sDate &Date, int Years)
	{
		Date._Year -= Years;

		return Date;
	}

	sDate DecreaseDateByXYears(int Years)
	{
		return DecreaseDateByXYears(Date1, Years);
	}

	static sDate DecreaseDateBy1Decade(sDate &Date)
	{
		for (int i = 0; i < 10; i++)
		{
			Date = DecreaseDateBy1Year(Date);
		}

		return Date;
	}

	sDate DecreaseDateBy1Decade()
	{
		return DecreaseDateBy1Decade(Date1);
	}

	static sDate DecreaseDateByXDecades(sDate &Date, int Decades)
	{
		Date._Year -= 10 * Decades;

		if (Date._Month == 2 && Date._Day == 29 && !CheckLeapYear(Date._Year))
		{
			Date._Day = 28;
		}

		return Date;
	}

	sDate DecreaseDateByXDecades(int Decades)
	{
		return DecreaseDateByXDecades(Date1, Decades);
	}

	static sDate DecreaseDateBy1Century(sDate& Date)
	{
		for (int i = 0; i < 10; i++)
		{
			Date = DecreaseDateBy1Decade(Date);
		}

		return Date;
	}

	sDate DecreaseDateBy1Century()
	{
		return DecreaseDateBy1Century(Date1);
	}

	static sDate DecreaseDateBy1Millennium(sDate& Date)
	{
		for (int i = 0; i < 10; i++)
		{
			Date = DecreaseDateBy1Century(Date);
		}

		return Date;
	}

	sDate DecreaseDateBy1Millennium()
	{
		return DecreaseDateBy1Millennium(Date1);
	}

	static void ShowTodaysDate()
	{
		time_t now = time(0);

		tm ltm;

		localtime_s(&ltm, &now);

		string Days[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		cout << "Today is " << Days[ltm.tm_wday];
		cout << " , " << ltm.tm_mday << "/" << ltm.tm_mon + 1 << "/" << ltm.tm_year + 1900;
	}

	static bool IsEndOfWeek(short Day)
	{
		return Day == 6;
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(GetDayNumber());
	}

	static bool IsWeekEnd(short Day)
	{
		return (Day == 5 || Day == 6);
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(GetDayNumber());
	}

	static bool IsBusinessDay(short Day)
	{
		return !IsWeekEnd(Day);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(GetDayNumber());
	}

	static short DaysUntilEndOfWeek(short Day)
	{
		return 7 - (Day + 1);
	}

	short DaysUntilEndOfWeek()
	{
		return DaysUntilEndOfWeek(GetDayNumber());
	}

	static short DaysUntilEndOfMonth(tm& Ltm)
	{
		return NumberOfDaysInMonth(Ltm.tm_mon + 1, Ltm.tm_year + 1900) - Ltm.tm_mday;
	}

	short DaysUntilEndOfYear(tm& Ltm)
	{
		short Days = NumberOfDaysFromBeginingOfTheYear(Ltm.tm_mday, Ltm.tm_mon + 1, Ltm.tm_year + 1900);

		return (CheckLeapYear(Ltm.tm_year + 1900)) ? 366 - Days : 365 - Days;
	}

	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(Date1._Day, Date1._Month, Date1._Year);
	}

	static string GetDayName(short Day)
	{
		string Days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri","Sat" };

		return Days[Day];
	}

	static bool IsWeekEndInDate(sDate Date)
	{
		short DayIndex = DayOfWeekOrder(Date._Day, Date._Month, Date._Year);

		return (DayIndex == 5 || DayIndex == 6);
	}

	static short GetVacationDays(sDate Date1, sDate Date2)
	{
		short Days = 0;

		while (IsDate1LessThanDate2(Date1, Date2))
		{
			if (!IsWeekEndInDate(Date1))
			{
				Days++;
			}
			Date1 = IncreaseDateByDay(Date1);
		}

		return Days;
	}

	short GetVacationDays(sDate Date2)
	{
		return GetVacationDays(Date1, Date2);
	}

	static bool IsDate1AfterDate2(sDate Date1, sDate Date2)
	{
		return (!IsDate1LessThanDate2(Date1, Date2) && !IsDate1EqwalDate2(Date1, Date2));
	}

	bool IsDate1AfterDate2(sDate Date2)
	{
		return IsDate1AfterDate2(Date1, Date2);
	}

	static bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : (Date1._Year > Date2._Year) ? false : (Date1._Month < Date2._Month) ? true : (Date1._Month > Date2._Month) ? false : (Date1._Day < Date2._Day);
	}

	bool IsDate1BeforeDate2(sDate Date2)
	{
		return IsDate1BeforeDate2(Date1, Date2);
	}

	static Result CompareTwoDates(sDate Date1, sDate Date2)
	{
		return IsDate1BeforeDate2(Date1, Date2) ? Before : IsDate1AfterDate2(Date1, Date2) ? After : Equal;
	}

	Result CompareTwoDates(sDate Date2)
	{
		return CompareTwoDates(Date1, Date2);
	}

	static bool IsOverlapPeriods(sPeriod Period1, sPeriod Period2)
	{
		return !(IsDate1BeforeDate2(Period2.Date2, Period1.Date1) || IsDate1AfterDate2(Period2.Date1, Period1.Date2));
	}

	bool IsOverlapPeriods(sPeriod Period2)
	{
		return IsOverlapPeriods(Period1, Period2);
	}

	static int PeriodLengthInDays(sPeriod Period, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(Period.Date1, Period.Date2, IncludeEndDay);
	}

	int PeriodLengthInDays(bool IncludeEndDay = false)
	{
		return PeriodLengthInDays(Period1, IncludeEndDay);
	}

	static bool IsDateInPeriod(sDate Date, sPeriod Period)
	{
		return !(IsDate1AfterDate2(Date, Period.Date2) || IsDate1BeforeDate2(Date, Period.Date1));
	}

	bool IsDateInPeriod()
	{
		return IsDateInPeriod(Date1, Period1);
	}

	static int CountOverlapDaysIn2Periods(sPeriod Period1, sPeriod Period2)
	{
		int Counter = 0;
		sDate Date = Period1.Date1;
		int Period1Length = PeriodLengthInDays(Period1);
		int Period2Length = PeriodLengthInDays(Period2);


		if (!IsOverlapPeriods(Period1, Period2))
			return 0;

		if (Period1Length < Period2Length)
		{
			while (IsDate1BeforeDate2(Date, Period1.Date2))
			{
				if (IsDateInPeriod(Date, Period2))
					Counter++;

				Date = IncreaseDateByDay(Date);
			}
		}
		else
		{
			while (IsDate1BeforeDate2(Period2.Date1, Period2.Date2))
			{
				if (IsDateInPeriod(Period2.Date1, Period1))
					Counter++;

				Period2.Date1 = IncreaseDateByDay(Period2.Date1);
			}
		}

		return Counter;
	}

	int CountOverlapDaysIn2Periods(sPeriod Period2)
	{
		return CountOverlapDaysIn2Periods(Period1, Period2);
	}

	static bool IsValidDate(sDate Date)
	{
		return (Date._Day <= NumberOfDaysInMonth(Date._Month, Date._Year));
	}

	bool IsValidDate()
	{
		return IsValidDate(Date1);
	}

	static sDate StringToDate(string S1)
	{
		vector <string> StringDate = ClsString::SplitString(S1, "/");

		if (StringDate.size() != 3)
		{
			cout << "Invalid Date Format!\n";
			return {};
		}

		sDate Date;

		Date._Day = stoi(StringDate[0]);
		Date._Month = stoi(StringDate[1]);
		Date._Year = stoi(StringDate[2]);

		return Date;
	}

	static string DateToString(sDate Date)
	{
		string StringDate = to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
		return StringDate;
	}

	string DateToString()
	{
		return DateToString(Date1);
	}

	string GetDateInFormat(sDate Date, string DateFormate = "dd/mm/yyyy")
	{
		string FormattedDateString = "";
		FormattedDateString = ClsString::ReplaceWordsInString(DateFormate, "dd", to_string(Date._Day));
		FormattedDateString = ClsString::ReplaceWordsInString(FormattedDateString, "mm", to_string(Date._Month));
		FormattedDateString = ClsString::ReplaceWordsInString(FormattedDateString, "yyyy", to_string(Date._Year));

		return FormattedDateString;
	}

};