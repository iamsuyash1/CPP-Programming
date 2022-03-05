#include<iostream>
using namespace std;

class Arithmatic
{
    public:
        int x, y; 
    Arithmatic ()
    {
        x=0;
        y=0;        
    }  
    Arithmatic (int i, int j)
    {
        x = i;
        y = j;
    }  
    int Addition()
    {
        int x = 0;
        x = (this->x) + (this->y);
        return x;
    }
    int Substraction()
    {
        int x = 0;
        x = this->x - y;
        return x;
    }
};
int main(int argc, char const *argv[])
{
    int m=0,n=0;
    int ret=0;
    
    cout<<"Enter the two numbers\n";
    cin>>m>>n;
    
    Arithmatic *obj = new Arithmatic(m,n);
    
    cout<<obj->x<<endl<<obj->y<<endl;

    ret = obj->Addition();
    cout<<"Addition is :"<<ret<<endl;
    
    ret = obj->Substraction();
    cout<<"Substraction is :"<<ret<<endl;
        
    return 0;
}


