#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

    // Helper function to check if a year is a leap year
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Helper function to get the number of days in a month
    int daysInMonth(int month, int year) const {
        if (month == 2) {
            return isLeapYear(year) ? 29 : 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        else {
            return 31;
        }
    }

public:
    // Constructor
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    // Overloading relational operators
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator<=(const Date& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const Date& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Date& other) const {
        return !(*this < other);
    }

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    // Overloading the ++ operator to increment a date by one day
    Date& operator++() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    // Overloading the + operator to add a given number of days
    Date operator+(int days) const {
        Date newDate = *this;
        newDate.day += days;

        while (newDate.day > newDate.daysInMonth(newDate.month, newDate.year)) {
            newDate.day -= newDate.daysInMonth(newDate.month, newDate.year);
            newDate.month++;
            if (newDate.month > 12) {
                newDate.month = 1;
                newDate.year++;
            }
        }

        return newDate;
    }

    // Conversion operator to get the number of days elapsed in the current year
    operator int() const {
        int daysElapsed = day;
        for (int m = 1; m < month; ++m) {
            daysElapsed += daysInMonth(m, year);
        }
        return daysElapsed;
    }
};

// Example usage
int main() {
    Date dt(12, 8, 2024);  // Creating a date object for 12th August 2024

    // Demonstrating the use of relational operators
    Date dt2(1, 1, 2025);
    if (dt < dt2) cout << "dt is earlier than dt2" << endl;

    // Incrementing the date by one day
    ++dt;
    cout << "Next day is: " << dt + 0 << endl;  // Adding 0 days to print the incremented date

    // Adding days to a date
    Date newDate = dt + 5;
    cout << "Date after 5 days: " << newDate + 0 << endl;

    // Conversion from Date to int to get the number of days elapsed in the year
    int days = dt;
    cout << "Days elapsed in the year: " << days <<endl;

    return 0;
}
