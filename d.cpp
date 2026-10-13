#include <iostream> 
#include <string>


class Person{
    private:
        std:: string first;
        std:: string last;

    



    public:
        void setFirstName(std:: string firstName){first = firstName;}
        
        void setLastName(std:: string lastName){last = lastName;}
        void printFullName() {std:: cout << first << " "<< last << std::endl;}
};

int main(){
    Person p;
    p.setFirstName("Caleb");
    p.setLastName("Curry");

    p.printFullName();

    Person p2;
    p2.setFirstName("John");
    p2.setLastName( "Doe");
    p2.printFullName();

    return 0;
}