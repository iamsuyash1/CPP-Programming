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

UINT ToggleBit(UINT iNo, int iPos)
{
    UINT iMask = 0X00000001;
    if ((iPos<1) || (iPos>32))
    {
        return 0;
    }
    
    iPos = iPos-1;

    UINT iMaskFinal = iMask<<iPos;
    iNo = iNo ^ iMaskFinal;
    return iNo;    
}

int main(int argc, char const *argv[])
{
    UINT iValue = 0;
    int iPos = 0;
    UINT iRet = 0;

    cout<<"Enter the number"<<endl;
    cin>>iValue;

    cout<<"Enter the position to toggle bit"<<endl;
    cin>>iPos;

    iRet = ToggleBit(iValue,iPos);

    cout<<"Number after toggle is : "<<iRet<<endl;

    return 0;
}
