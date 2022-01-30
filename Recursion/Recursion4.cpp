#include<iostream>
using namespace std;

int Factorial(int no)
{
    static int fact = 1;

    if(no != 1)
    {
        fact = fact * no;
        no--;

        Factorial(no);
    }

    return fact;
    
}
int main(int argc, char const *argv[])
{
    int x = 0, iRet = 0;

    cout<<"enter the number\n";
    cin>>x;

    iRet = Factorial(x);
    cout<<"Factorial is : "<<iRet<<endl;
    return 0;
}
