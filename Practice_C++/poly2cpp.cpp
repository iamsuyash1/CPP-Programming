#include<iostream>
using namespace std;

class Base
{
    public:
        int x,y;

};
class Derived : public Base
{
    public:
        int i,j;    
};

int main(int argc, char const *argv[])
{
    char ch = 'A';
    int no =11;

    char *cp1 = &ch;                     // No casting
    int *ip1 = &no;                     // No casting

    char *cp2 =(char *) &no;            // up
    //int *ip2 =(int *) &ch;            // down

    Base * bp1 = new Base();            // No casting
    Derived * dp1 = new Derived();      // No casting

    Base * bp2 = new Derived();         // up casting
    //Derived * dp2 = new Base();       // down casting (Invalid)
    
    return 0;
}
