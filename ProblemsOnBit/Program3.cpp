#include<iostream>

using namespace std;
typedef unsigned int UINT;

/*
    op1     op2     &       |       ^

    1       0       0       1       1
    0       0       0       0       0  
    1       1       1       1       0
    0       1       0       1       1
*/

UINT CountBit(UINT iNo)
{
    UINT iMask = 0X00000001;
    UINT iResult = 0;
    int iCnt = 0;
    for (int i = 0; i < 32; i++)
    {
        iResult = iNo & iMask;
        if (iResult == iMask)
        {
            iCnt++;
        }
        iMask = iMask<<1;
    }
    return iCnt;       
}

int main(int argc, char const *argv[])
{
    UINT iValue = 0;
    int iRet = 0;

    cout<<"Enter the number"<<endl;
    cin>>iValue;

    iRet = CountBit(iValue);

    cout<<"Number of ON bit is : "<<iRet<<endl;

    return 0;
}
