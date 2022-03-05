#include<iostream>
using namespace std;


class Demo
{
    private:
        int i,j;
    public :

        Demo(int x=10, int y = 20)
        {
            i = x;
            j= y;
        }
        
        void Display()
        {
            cout<<i<<"\t"<<j<<"\n";
        }

    friend Demo operator - (Demo, Demo);
};

Demo operator - (Demo op1, Demo op2)
{
    cout<<"Inside plus operator\n";

    return Demo(op1.i - op2.i, op1.j - op2.j);
}

int main(int argc, char const *argv[])
{
    Demo obj1(11,21);
    Demo obj2(7,5);

    Demo ret (0,0);

    ret = obj1 - obj2;  // ret = - (obj1,obj2);
    ret.Display();

    
    return 0;
}
