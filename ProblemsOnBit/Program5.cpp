#include<iostream>

using namespace std;
typedef unsigned int UINT;


UINT ToggleNibble(UINT iNo)
{
    UINT iMask = 0XF000000F;
    iNo = iNo ^ iMask;
    return iNo;    
}

int main(int argc, char const *argv[])
{
    UINT iValue = 0;
    UINT iRet = 0;

    cout<<"Enter the number"<<endl;
    cin>>iValue;

    iRet = ToggleNibble(iValue);

    cout<<"Number after toggle nibble is : "<<iRet<<endl;

    return 0;
}
