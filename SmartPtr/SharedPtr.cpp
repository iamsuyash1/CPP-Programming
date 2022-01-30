#include<iostream>
#include<memory>
#include<stdio.h>

using namespace std;


int main(int argc, char const *argv[])
{
    shared_ptr<int> sp = make_shared<int>();

    *sp = 100;

    shared_ptr<int> sp1 = make_shared<int>();
    sp1 = sp;

    cout<<"Owner Count is : "<<sp.use_count()<<endl;
    

    return 0;
}
