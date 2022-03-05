#include<iostream>
using namespace std;

class Demo
{
    public:
        int i,j;

        Demo(int x=10, int y = 20)
        {
            i = x;
            j= y;
        }
};

Demo operator + (Demo op1, Demo op2)
{
    cout<<"Inside plus operator\n";

    return Demo(op1.i + op2.i, op1.j + op2.j);
}

int main(int argc, char const *argv[])
{
    Demo obj1(11,21);
    Demo obj2(7,5);

    Demo ret (0,0);

    ret = obj1 + obj2;  // ret = + (obj1,obj2);

    cout<<ret.i<<"\t"<<ret.j<<"\n";
    return 0;
}
