#include<iostream>

using namespace std;
typedef unsigned int UINT;

UINT SwapByte(UINT iNo)
{   
    UINT iMask = 0X00FFFF00;
    UINT iTemp = iNo & iMask;

    UINT Byte1 = iNo << 24;
    UINT Byte4 = iNo >> 24;

    UINT iResult = iTemp | Byte1 | Byte4;

    return iResult;
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
