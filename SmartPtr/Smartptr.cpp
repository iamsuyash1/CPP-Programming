#include<iostream>
#include<memory>
#include<stdio.h>

using namespace std;

template <class T>

class SmartPtr
{
    private:
        T* sp;
    public:
        explicit SmartPtr(T* a = NULL)
        {
            cout<<"Resources gets allocated"<<endl;
            sp = a;
        }
        ~SmartPtr()
        {
            cout<<"Releases Resources"<<endl;
            delete sp;
        }
        T& operator*()
        {
            cout<<"Inside Operator"<<endl;
            return *sp;
        }
        
};

class B {};

int main(int argc, char const *argv[])
{
    int a = 990;
    int* p = &a;
    SmartPtr<int> spp (new int());
    *spp = 100;

    cout<<"size of ptr : "<<sizeof(spp)<<endl;
    cout<<"size of value : "<<sizeof(*spp)<<endl;
    cout<<*spp<<endl;
    

    return 0;
}
