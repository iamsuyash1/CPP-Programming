#include<iostream>

using namespace std;
typedef unsigned int UINT;


void DisplayByte(UINT iNo)
{   
    UINT Byte1 = iNo & 0X000000FF;

    UINT Byte2 = iNo & 0X0000FF00;
    Byte2 = Byte2>>8;

    UINT Byte3 = iNo & 0X00FF0000;
    Byte3 = Byte3>>16;

    UINT Byte4 = iNo & 0XFF000000;
    Byte4 = Byte4>>24;

    cout<<"Byte1 = "<<Byte1<<endl;
    cout<<"Byte2 = "<<Byte2<<endl;
    cout<<"Byte3 = "<<Byte3<<endl;
    cout<<"Byte4 = "<<Byte4<<endl;
}

int main(int argc, char const *argv[])
{
    UINT iValue = 0;
    

    cout<<"Enter the number"<<endl;
    cin>>iValue;

    DisplayByte(iValue);


    return 0;
}
