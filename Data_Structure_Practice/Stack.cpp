// Stack

#include<iostream>
#include<stdlib.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
//
//    Class Name  :  Stack 
// 
//    Description :  It is a Generic Stack Data Structure     
//                              
//    Author      :  Suyash Maruti Saykar
//
//    Date        :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
 struct stnode
{
    T data;
    struct stnode<T>* next;

};

template <class T>
class Stack
{
    private:
        stnode<T>* first = NULL;
        int size;

    public:
        Stack();
        void push(T Data);   
        T pop();   
        void Display();
        int Count();
};

///////////////////////////////////////////////////////////////////////////////////
//
//    Constructor :  Stack 
// 
//    Description :  Default Constructor of a class Stack     
//                              
//    Author      :  Suyash Maruti Saykar
//
//    Date        :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
Stack<T>::Stack()
{
    first = NULL;
    size = 0;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  push  
// 
//    Description   :  We can insert a node in the 
//                     Stack by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>:: push(T Data)   
{
    stnode<T>* newn = new stnode<T>;
    newn->data = Data;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    size++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  pop  
// 
//    Description   :  We can delete a node from the 
//                     Stack and return the deleted data 
//                     by using this function (Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T>:: pop()   
{
    T Data;
    stnode<T>* temp = first;

    if (first == NULL)
    {
        cout<<"Stack is empty\n";

        return -1;
    }
    if (first->next == NULL)
    {
        Data = first->data;
        delete first;
        first = NULL;
    }
    else
    {
        Data = first->data;
        first = first->next;
        delete temp;
        temp = NULL;
    }
            
    size--;
    return Data;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Display  
// 
//    Description   :  We can Display the data from the 
//                     Stack by using this function (Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>:: Display()
{
    stnode<T>* temp = first;

    if (first == NULL)
    {
        return;
    }
    while (temp->next != NULL)
    {
        cout<<"|"<<temp->data<<"|\n";
        temp = temp->next;
    }            
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Count  
// 
//    Description   :  We can Count the elements from the 
//                     Stack by using this function (Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T>:: Count()
{
    return size;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[])
{
    Stack<char> stobj;

    stobj.push('a');
    stobj.push('s');
    stobj.push('o');
    stobj.push('Y');

    cout<<"Elements of stack:\n";
    stobj.Display();

    char iret = stobj.pop();
    cout<<"Popped element is:"<<iret<<endl;

    cout<<"Elements of stack:\n";
    stobj.Display();

    return 0;
}

