#include<iostream>
using namespace std;

void fun(int x)  // call by value
{
    x++;
}

void gun(int *p) // call by address
{
    (*p)++;
}

void sun(int &ref)  // call by reference
{
    ref++;
}

int main(int argc, char const *argv[])
{
    int a = 10, b =10, c = 10;
    cout<<"Before call to fun\n"<<a<<"\n";  //10
    fun(a); //fun(10);
    cout<<"After call to fun\n"<<a<<"\n";   //10


    cout<<"Before call to gun\n"<<b<<"\n";  //10
    gun(&b);    //gun(920);
    cout<<"After call to gun\n"<<b<<"\n";   //11


    cout<<"Before call to sun\n"<<c<<"\n";  //10
    sun(c); //sun(c);
    cout<<"After call to sun\n"<<c<<"\n";   //11

    return 0;
}
