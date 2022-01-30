#include<iostream>
using namespace std;

class TestE
{
    public:
        int a;
        explicit TestE( int a )
        {
            this->a = a;
        }
        void print()
        {
            cout<<a<<endl;
        }
        
};
void fun( TestE t)
{
    t.print();
}

int main()
{

    //TestE T = 10;
    TestE T1(20);
    
    //fun(10);
    fun(T1);
    
    return 0;
}