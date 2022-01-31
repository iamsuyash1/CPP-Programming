#include<iostream>
using namespace std;
/*
    This class is only responsible to create a array
    If we write a arithmatic operatio methods in this class, 
    As per the requirement of the arithmatic operations, 
    we will have to make changes in this class.

*/

class Array
{
    public:
        int *Arr, size;

        Array (int size = 0)
        {
            this->size = size;
            Arr = new int[this->size];
        }

        void Accept()
        {
            cout<<"Enter the element"<<endl;

            for(int i = 0; i < size; i++)
            {
                cin>>Arr[i];
            }
        }
        ~Array ()
        {
            delete [] Arr;
        }
};

// This class have a responsibility to perform arithmatic operations on array
class Arithmatic
{
    public: 
        int *Brr;
        int size;
        Arithmatic(int size = 0, int* ptr = NULL )
        {
            Brr = ptr;
            this->size = size;
        }
        int Addition()
        {
            int sum = 0;

            for(int i = 0; i < size; i++ )
            {
                sum = sum + Brr[i];
            }
            return sum;
        }
        int Substraction(){return 0;}
        int Multiplication(){return 0;}
};

int main(int argc, char const *argv[])
{
    Array a;
    a.size = 5;
    Arithmatic b(a.size, a.Arr);
    a.Accept();  
    int ret = b.Addition();
    cout<<"Addition is : "<<ret<<endl;
    
    return 0;
}
