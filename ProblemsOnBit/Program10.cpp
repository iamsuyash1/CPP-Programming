#include<iostream>

using namespace std;
typedef unsigned int UINT;


UINT SwapByte(UINT iNo)
{  
    return ((iNo & 0X00FFFF00) | (iNo << 24) | (iNo >> 24));
}

int main(int argc, char const *argv[])
{
    UINT iValue = 0;    //INput : 4278190335 output is same
    UINT iRet = 0;

    cout<<"Enter the number"<<endl;
    cin>>iValue;

    iRet = SwapByte(iValue);

    cout<<"Data is : "<<iRet<<endl;
    return 0;
}
