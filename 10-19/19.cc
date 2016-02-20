// You are given the following information, but you may prefer to do some research for yourself.
// 
// 1 Jan 1900 was a Monday.
// Thirty days has September,
// April, June and November.
// All the rest have thirty-one,
// Saving February alone,
// Which has twenty-eight, rain or shine.
// And on leap years, twenty-nine.
// A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
// How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

class Date {
  public:
    Date() {initialize();};
    int year;
    int month;
    int day;
    int day_of_week;
    void increment() {
        day++;
        day_of_week++;

        //end of week rollover
        if(day_of_week > 6) 
            day_of_week = 0;

        //end of month rollover
        if(day > max_days[month]) {
            month++;
            day = 1;
        }
        //end of year rollover
        if(month > 11) {
            year++;
            month = 0;
            if (year % 400 == 0)
                max_days[1] = 29;
            else if (year % 100 == 0)
                max_days[1] = 28;
            else if (year % 4 == 0)
                max_days[1] = 29;
            else
                max_days[1] = 28;
        }
    };
  private:
    vector<int> max_days;
    void initialize() {
        max_days.push_back(31);
        max_days.push_back(28);
        max_days.push_back(31);
        max_days.push_back(30);
        max_days.push_back(31);
        max_days.push_back(30);
        max_days.push_back(31);
        max_days.push_back(31);
        max_days.push_back(30);
        max_days.push_back(31);
        max_days.push_back(30);
        max_days.push_back(31);
        year = 1900;
        month = 0;
        day = 1;
        day_of_week = 1;
    };
};

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    Date d;
    int count = 0;
    while(d.year < 1901) { d.increment(); } 
    while(d.year < 2001) {
        if(d.day == 1 && d.day_of_week == 0)
            count++;
        d.increment();
    }
    cout << "Count: " << count << endl;
 
    system_clock::time_point stop = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
    return 0;
}
