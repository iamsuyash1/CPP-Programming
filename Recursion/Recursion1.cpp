#include<iostream>
using namespace std;

void Frequency()
{
    static int i = 1;

    if (i<= 4)
    {
        cout<<"Marvellous Infosystems\n";
        i++;
        Frequency();
    }
}
int main(int argc, char const *argv[])
{
    Frequency();
    return 0;
}
