#include<iostream>
#include<stdlib.h>

using namespace std;

template <class T>
struct node
{
    node <T> *next;
    T data;
};


///////////////////////////////////////////////////////////////////////////////////
//
//    Class Name  :  SinglyLL [Singly Linear Linked List] 
// 
//    Description :  It is a Generic Singly Linear Linked List Data Structure     
//                              
//    Author      :  Suyash Maruti Saykar
//
//    Date        :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    private:
        node<T>* first;
        int size;      
    
    public:
        SinglyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

///////////////////////////////////////////////////////////////////////////////////
//
//    Constructor :  SinglyLL  
// 
//    Description :  Default Constructor of a class SinglyLL
//                              
//    Author      :  Suyash Maruti Saykar
//
//    Date        :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLL<T>::SinglyLL()
{
    first = NULL;
    size = 0;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  InsertFirst  
// 
//    Description   :  We can insert a first node in the 
//                     SINGLY Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertFirst(T Data)
{
    node<T>* newn = new node<T>;
        
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
//    Function Name :  InsertLast  
// 
//    Description   :  We can insert a last node in the 
//                     SINGLY Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertLast(T Data)
{
    node<T>* newn = new node<T>;
    node<T>* temp = first;

    newn->data = Data;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else 
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
            temp->next = newn;               
    }
    size++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  InsertAtPos  
// 
//    Description   :  We can insert a node at desired position in the 
//                     SINGLY Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T> :: InsertAtPos(T Data, int pos)
{
    node<T>* temp = first;

    if ((pos < 1) || (pos > (size + 1)))
    {
        return;
    }
    if (pos == 1)
    {
        InsertFirst(Data);
    }
    else
    {
        node<T>* newn = new node<T>;
        int iCnt = 1;

        newn->data = Data;
        newn->next = NULL;

        while (iCnt != (pos -1))
        {
            temp = temp->next;
            iCnt++;
        }
        newn->next = temp->next;
        temp->next = newn;            
    }
    size++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  DeleteFirst  
// 
//    Description   :  We can delete a first node of the 
//                     SINGLY Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteFirst()
{
    node<T>* temp = first;
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
        size--;
    }
    else
    {
        first = temp->next;
        delete temp;
        temp = NULL;
        size--;
    }
}


///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  DeleteLast  
// 
//    Description   :  We can delete a last node of the 
//                     SINGLY Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteLast()
{
    node<T>* temp = first;
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
        size--;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;

        size--;            
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  DeleteAtPos  
// 
//    Description   :  We can delete a desired position node of the 
//                     SINGLY Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
    node<T>* temp = first;
    int icnt = 1;

    if ((pos < 1) || (pos > size))
    {
        return;
    }
    else if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == size)
    {
        DeleteLast();
    }
    
    else
    {
        while (icnt != (pos-1))
        {
            temp = temp->next;
            icnt++;
        }
        node<T>* targeted = temp->next;
        temp->next = targeted->next;
        delete targeted;
        targeted = NULL;

        size--;
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Display  
// 
//    Description   :  We can display the SINGLY Linked List 
//                     by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::Display()
{
    node<T>* temp = first;

    while (temp != NULL)
    {
        cout<<(temp->data)<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Count  
// 
//    Description   :  We can count the number of nodes from the SINGLY Linked List 
//                     by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLL<T>::Count()
{
    return size;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
    SinglyLL <float> obj;

    obj.InsertFirst(11);
    obj.InsertFirst(2.14);
    obj.InsertFirst(0.14);
    obj.InsertFirst(111.14);
    obj.InsertFirst(999.14);
    obj.InsertFirst(5555.14);

    obj.Display();
    int iRet = obj.Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    obj.DeleteAtPos(1);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    obj.InsertAtPos(999.14,2);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    obj.DeleteAtPos(6);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    return 0;
}
