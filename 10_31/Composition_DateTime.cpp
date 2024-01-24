#include <iostream>
#include <iomanip>
using namespace std;

/*
Wanted to show this way to write a file with classes in it.
This does not have a separate header file.
This is not a recommended way but it should be okay for learning purposes only
*/

//define a class to store & print the date, also do increment operation
class Date
{
public:
    Date(int mm=0, int dd=0, int yy=0)
    {
        year = yy;
        month = mm;
        day = dd;
    }
    void display()
    {
        cout << month << '/' << day << '/' << year;
    }

    //function to return true if year is leap year, false otherwise.
    bool isLeapYear()
    {
        if (year % 4)
            return false;

        // year is divisible by 4
        if (year % 400 == 0)
            return true;

        // year is not divisible by 400
        if (year % 100 == 0)
            return false;

        // year is divisible by 4, but not divisible by 100
        return true;
    }

    //increment the day, if needed, increment the month,
    //if needed, increment the year
    void increment()
    {

//CODIO SOLUTION BEGIN
        //static makes this array to be allocated like a global variable
        //but it is used only within this function
        static int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30,
                                           31, 31, 30, 31, 30, 31
                                          };
        if ((month == 2) && isLeapYear())
            daysInMonths[2] = 29;
        else
            daysInMonths[2] = 28;

        day++;

        //went beyond the last day of month?
        if (day > daysInMonths[month])
        {
            month++;
            day = 1;

            //went beyond December?
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
//CODIO SOLUTION END
    }
private:
    int day, month, year;
};

//class to store time and display and do increment() operation
class Time
{
public:
    Time(int hh=0, int mm=0, int ss=0)
    {
        hour = hh;
        minute = mm;
        second = ss;
    }

    //second: 59 --> 60: increment minute
    //minute: 59 --> 60: increment hour
    //hour: 23-->24: hour=0
    //return true if the day rolls over, return false otherwise.
    bool increment()
    {

//CODIO SOLUTION BEGIN
        second++;
        if (second == 60)
        {
            minute++;
            second = 0;
            if (minute == 60)
            {
                hour++;
                minute = 0;
                if (hour == 24)
                {
                    hour=0;
                    return true;
                }
            }
        }
        return false;
//CODIO SOLUTION END
    }

    void display()
    {
//CODIO SOLUTION BEGIN
        cout << setfill('0');
        if (hour == 0)
            cout << 12 << ':' << setw(2) << minute << ':' << setw(2) << second << " AM";
        else if (hour < 12)
            cout << setw(2) << hour << ':' << setw(2) << minute << ':' << setw(2) << second << " AM";
        else if (hour == 12)
            cout << setw(2) << hour << ':' << setw(2) << minute << ':' << setw(2) << second << " PM";
        else
            cout << setw(2) << hour-12 << ':' << setw(2) << minute << ':' << setw(2) << second << " PM";
//CODIO SOLUTION END
    }

private:
    int hour, minute, second;
};

//composition - we used 2 objects: Date & Time objects
class DateTime
{

//CODIO SOLUTION BEGIN
public:
    //pass the necessary parameters to each constructor
    //to populate member objects
    DateTime(int mm=0, int dd=0, int yy=0, int hh=0, int mmm=0, int ss=0)
    {
        date = Date(mm, dd, yy);
        time = Time(hh, mmm, ss);
    }

    void increment()
    {
        // if day rolled over, increment the date
        if (time.increment())
            date.increment();
    }

    void display()
    {
        date.display();
        cout << " ";
        time.display();
    }

private:
    Date date;
    Time time;
//CODIO SOLUTION END
};

int main()
{
    string dataType;
    int month, day, year, steps, hour, minutes, seconds;
    char temp;

    cin >> dataType;
//CODIO SOLUTION BEGIN
    if (dataType == "D") {
        cin >> month >> temp >> day >> temp >> year >> steps;
        Date date(month, day, year);
        for(int i=0; i<steps; i++)
            date.increment();
        date.display();
    }
    if (dataType == "T") {
        cin >> hour >> temp >> minutes >> temp >> seconds >> steps;
        Date date(month, day, year);
        Time time(hour, minutes, seconds);
        for(int i=0; i<steps; i++)
            time.increment();
        time.display();
    }
    if (dataType == "DT") {
        cin >> month >> temp >> day >> temp >> year
            >> hour >> temp >> minutes >> temp >> seconds >> steps;
        DateTime dt(month, day, year, hour, minutes, seconds);
        for(int i=0; i<steps; i++)
            dt.increment();
        dt.display();
    }
//CODIO SOLUTION END
}
