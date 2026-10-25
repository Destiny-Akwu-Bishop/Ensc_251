#include <iostream>
using namespace std;

class DigitalTime{
    public:
        friend bool operator ==(const DigitalTime& time1, const DigitalTime& time2);
        DigitalTime(int theHour, int theMinute);

        DigitalTime();
        void advance(int minutesAdded);
        void advance(int hoursAdded, int minutesAdded);
        friend ostream &operator <<(ostream &out, const DigitalTime &theObject);
        friend istream &operator >>(istream& in, DigitalTime& theObject);
    private:
        int hour;
        int minute;

};