#include <iostream>
using namespace std;

class Array
{
private:
    int *ptr;
    int size;
public:
    Array(int no = 5)
    {
        cout<<"Constructor\n";
        size = no;
        ptr = new int[size];
    }
    
    Array(Array &ref)
    {
        cout<<"Copy constructor\n";
        size = ref.size;
        ptr = new int[size];    // ptr = ref.ptr;
        int iCnt = 0;
        for(iCnt = 0; iCnt < size; iCnt++)
        {
            ptr[iCnt] = ref.ptr[iCnt];
        }
    }
    
    ~Array()
    {
        cout<<"Destructor\n";
        delete []ptr;
    }
    void Accept()
    {
        int iCnt = 0;
        cout<<"Enter the elements\n";
        //          1           2           3
        for(iCnt = 0; iCnt < size; iCnt++)
        {
            cin>>ptr[iCnt]; // 4
        }
    }
    void Display()
    {
        cout<<"Elements are\n";
        int iCnt = 0;
        for(iCnt = 0; iCnt < size; iCnt++)
        {
            cout<<ptr[iCnt]<<"\n";
        }
    }
    int Addition()
    {
        int iSum = 0, iCnt = 0;
        for(iCnt = 0;iCnt < size ;iCnt++)
        {
            iSum = iSum + ptr[iCnt];
        }
        return iSum;
    }
};

int main()
{
    cout<<"Inside main\n";
    int value = 0;
    cout<<"Enter number of elements\n";
    cin>>value;
    Array *obj = NULL;
    obj = new Array(value);
    obj->Accept();
    obj->Display();
    delete obj;
    Array obj1(2);
    obj1.Accept();
    obj1.Display();
    Array obj2(obj1);
    return 0;
}
