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

UINT ToggleBit(UINT iNo, int iPos1, int iPos2)
{
    UINT iMask1 = 0X00000001;
    UINT iMask2 = 0X00000001;

    if ((iPos1<1) || (iPos1>32) || (iPos2<1) || (iPos2>32))
    {
        return 0;
    }
    
    iPos1 = iPos1-1;
    iPos2 = iPos2-1;
    iMask1 = iMask1<<iPos1;
    iMask2 = iMask2<<iPos2;
    
    UINT iMaskFinal = iMask1 | iMask2;
    iNo = iNo ^ iMaskFinal;
    return iNo;    
}

int main(int argc, char const *argv[])
{
    UINT iValue = 0;
    int iPos1 = 0; int iPos2 = 0;
    UINT iRet = 0;

    cout<<"Enter the number"<<endl;
    cin>>iValue;

    cout<<"Enter the 1st position to toggle bit"<<endl;
    cin>>iPos1;

    cout<<"Enter the 2nd position to toggle bit"<<endl;
    cin>>iPos2;

    iRet = ToggleBit(iValue,iPos1,iPos2);

    cout<<"Number after toggle is : "<<iRet<<endl;

    return 0;
}
