// Interface Segregation Principle 
#include <iostream>
using namespace std;

/*
    =>  According to this principle, we have to avoid unnecessary 
        implementation of the methods which are in the interface.

    =>  The concept of interface is in Java programming. 
        And According to the concept of interface, it contains the abstract methods.
        And the class which implements that interface will responsible to write a 
        concrete method for all the abstract methods in itsself.

    =>  In C++, there is a concept of pure virtual which help us to create class like interface.

    =>  Here in the class LivingBeings, 5 abstract methods are declared.

*/
class LivingBeings
{
    public:
        virtual void flay() = 0;
        virtual void swim() = 0;
        virtual void walk() = 0;
        virtual void eat() = 0;
        virtual void sleep() = 0;
};

class Bird : public LivingBeings    // class Bird inherits the abstract class Living beings
{
    public:
        void fly(){cout<<"Can fly"<<endl;}
};

int main()
{
    //Bird b;
    //b.flay();
}