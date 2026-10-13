#include <iostream>
#include "week5.h"


using namespace std;

int main(){
    DigitalTime clock, old_clock;
    cout  << "enter the time in 24-hour notaiotn: ";
    cin >> clock;
    old_clock = clock;
    clock.advance(15);

    if (clock == old_clock){
        cout << "Something is wrong!" << endl;
        cout << "You entered: " << old_clock << endl;
        cout << "After advancing 15 minutes, the time is: " << clock << endl;
    }

    clock.advance(2, 15);
    cout << "After advancing 2 hours and 15 minutes, the time is: " << clock << endl;
    return 0;

    
    
}