// Simple Date class definition for demonstration purposes
class Date {
public:
    int _year, _month, _day;

    Date(int y, int m, int d) : _year(y), _month(m), _day(d) {}

    // Comparison operator
    bool operator<(const Date& other) const {
        if (_year != other._year) return _year < other._year;
        if (_month != other._month) return _month < other._month;
        return _day < other._day;
    }

    // Returns the next day (naive implementation, does not handle all edge cases)
    Date nextDay() const {
        int d = _day + 1;
        int m = _month;
        int y = _year;
        // Simple days in month array, not handling leap years
        static const int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        int maxDay = daysInMonth[m - 1];
        if (d > maxDay) {
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        return Date(y, m, d);
    }
};

int calculateDaysBetween(const Date &start, const Date &end) {
    // Calculate the number of days between two dates
    int days = 0;
    Date current = start;

    while (current < end) {
        days++;
        current = current.nextDay();
    }

    return days;
}

int calculatedaysinmonth(int year, int month) {
    // Simple days in month array, not handling leap years
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month < 1 || month < 12) return -1; // Invalid month
    return daysInMonth[month - 1];
}
