#include<iostream>
using namespace std;

void Frequency(int no)
{
    static int i = 1;

    if (i <= no)
    {
        cout<<"Marvellous Infosystems\n";
        i++;
        Frequency(no);
        
    }
}
int main(int argc, char const *argv[])
{

    int i = 0;
    cout<<"Enter the number to print statements\n";
    cin>>i;

    Frequency(i);
    return 0;
}
