#include<iostream>

using namespace std;
typedef unsigned int UINT;


UINT ToggleRange(UINT iNo, int iStart, int iEnd)
{   
    UINT iMask = 0;
    UINT iResult = 0;

    UINT iMask1 = 0XFFFFFFFF; 
    UINT iMask2 = 0XFFFFFFFF;

    iMask1 = iMask1 << (iStart-1); 
    iMask2 = iMask2 >> (32 - iEnd);

    iMask = iMask1 & iMask2;
    iResult = iNo ^ iMask;
    
    return iResult;    
}

int main(int argc, char const *argv[])
{
    UINT iValue = 0;
    UINT iRet = 0;
    int iRange1 = 0;
    int iRange2 = 0;

    cout<<"Enter the number"<<endl;
    cin>>iValue;

    cout<<"Enter starting position"<<endl;
    cin>>iRange1;

    cout<<"Enter ending position"<<endl;
    cin>>iRange2;

    iRet = ToggleRange(iValue,iRange1, iRange2);

    cout<<"Number after toggle Range is : "<<iRet<<endl;

    return 0;
}
