#include<iostream>
#include<stdio.h>

using namespace std;

int CountCap(char *str)
{
    static int iCnt = 0;

    if (*str != '\0')
    {
        if ((*str>= 'A' && (*str <= 'Z')))
        {
            iCnt++;
        }
        
        str++;

        CountCap(str);
    }
    return iCnt;
}

int main(int argc, char const *argv[])
{
    char Arr[20];
    int iRet = 0;

    cout<<"Enter the string\n";
    scanf("%[^'\n']s",Arr);

    iRet = CountCap(Arr);
    cout<<"Count of Capital letter is : "<<iRet<<endl;
    return 0;
}
