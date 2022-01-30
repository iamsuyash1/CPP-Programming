#include<iostream>
using namespace std;

template<class T>

void swap(T *p, T *q)
{
    T temp = 0;

    temp = *p;
    *p = *q;
    *q = temp;
}

int main(int argc, char const *argv[])
{
    
    float x = 0, y = 0;

    cout<<"Enter first number\n";
    cin>>x;

    cout<<"Enter second number\n";
    cin>>y;

    swap(&x,&y);

    cout<<"Value of x becomes : "<<x<<endl;
    cout<<"Value of y becomes : "<<y<<endl;

    return 0;
}
