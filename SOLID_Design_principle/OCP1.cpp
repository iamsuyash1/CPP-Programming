// Open for extention, Closed for modification
#include<iostream>
using namespace std;
//    This is a Array class which is responsible to create array.

class Array
{
    protected:
        int *Arr, size;

    public:
        Array (int size)
        {
            //cout<<"Inside Array: "<<endl;
            this->size = size;
            Arr = new int[this->size];
        }
        virtual int Addition(){return 0;}
        void Accept()
        {
            cout<<"Enter the element"<<endl;

            for(int i = 0; i < this->size; i++)
            {
                cin>>this->Arr[i];
            }
        }
        virtual ~Array ()
        {
            delete [] Arr;
        }
};

// Arithmatic class contains various arithmatic operations. 
// To perform these Arithmatic operations on Array, 
// We can extend Arithmatic class with Array

class Arithmatic : public Array
{
    public: 
        //int a, b;
        Arithmatic( int  asize, int p = 0, int q = 0): Array(asize)
        {
            //a = p;
            //b = q;
            //cout<<"inside Arith"<<endl;
        }
        int Addition()
        {
            int sum = 0;
            for(int i = 0; i < size; i++ )
            {
                sum = sum + Arr[i];
            }
            return sum;
        }

        int Substraction(){return 0;}
        int Multiplication(){return 0;}
        ~Arithmatic(){}
};

int main(int argc, char const *argv[])
{   
    Array *A = new Arithmatic(5);
    A->Accept();
    cout<<"Size of object : "<<sizeof(*A)<<endl;

    int ret = A->Addition();
    cout<<"Addition is : "<<ret<<endl;    
    
    return 0;
}
