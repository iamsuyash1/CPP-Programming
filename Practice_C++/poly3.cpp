#include<iostream>
using namespace std;

class Base
{
    public:
        int x,y;
    virtual void fun()                              //1000              
    {   cout<<"Base fun\n";}
    virtual void gun()                              //2000                  
    {   cout<<"Base gun\n";}
    virtual void sun()                            //3000                   
    {   cout<<"Base sun\n";}  
};
class Derived : public Base
{
    public:
        int i,j;
    void gun()                            //4000           
    {   cout<<"Derived gun\n";}
    virtual void run()                            //6000 
    {cout<<"Derived run\n";}
    void add()                            //7000
    {cout<<"Derived run\n";}
};

int main(int argc, char const *argv[])
{
    cout<<"Size of base : "<<sizeof(Base)<<endl; //(+8 due to vptr(virtual pointer))
    cout<<"Size of derived : "<<sizeof(Derived)<<endl;
    Base *bp = new Derived();
    bp->fun();                           //CALL 1000           
    bp->gun();  //4000 //(CALL 2000 - will get called if virtual is not used at line no. 10)
    bp->sun();  //3000
    return 0;
}
