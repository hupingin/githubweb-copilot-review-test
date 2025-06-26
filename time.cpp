#include <ctime>

long calculateMillisecondsBetweenDates(int year1, int month1, int day1,
    int year2, int month2, int day2) {
    // Convert the first date to milliseconds since epoch
    struct tm time1 = {0};
    time1.tm_year = year1 - 1900; // tm_year is years since 1900
    time1.tm_mon = month1 - 1;    // tm_mon is 0-11
    time1.tm_mday = day1;
    time_t epoch1 = mktime(&time1);
    if (epoch1 == (time_t)(-1)) {
        // Error converting first date
        return -1;
    }

    // Convert the second date to milliseconds since epoch
    struct tm time2 = {0};
    time2.tm_year = year2 - 1900;
    time2.tm_mon = month2 - 1;
    time2.tm_mday = day2;
    time_t epoch2 = mktime(&time2);
    if (epoch2 == (time_t)(-1)) {
        // Error converting second date
        return -1;
    }

    // Calculate the difference in milliseconds
    return static_cast<long>(difftime(epoch2, epoch1) * 1000);
}

int calculateDaysBetweenDates(int year1, int month1, int day1,
    int year2, int month2, int day2) {
    //TODO
}