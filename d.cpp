#include <iostream>

using namespace std;

struct Data {
    double time[10];
    int distance;
};

Data my_best;
int main(){
my_best.distance = 20;

cout << "Enter ten times (in seconds):\n";
for (int i = 0; i < 10; i++){
    cin >> my_best.time[i];
}
}