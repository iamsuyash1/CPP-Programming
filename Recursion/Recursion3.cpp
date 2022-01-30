#include<iostream>
using namespace std;

int SumDigit(int no)
{
    int iSum = 0;
    while (no != 0)
    {
        iSum = iSum + (no%10);
        no = no/10;
    }
    return iSum;
    
}
int SumR(int no)
{
    static int iSum = 0;
    if (no != 0)
    {
        
        iSum = iSum + (no % 10);
        no = no/10;
        SumR(no);
    }
    return iSum;
}

int main(int argc, char const *argv[])
{
    int x = 0, iRet = 0;

    cout<<"Enter the number\n";
    cin>>x;

    iRet = SumR(x);
    cout<<"Summation of digits : "<<iRet<<"\n";
    
    return 0;
}
