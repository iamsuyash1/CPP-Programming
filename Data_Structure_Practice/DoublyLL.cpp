// Doubly Linear Linked List Data Structure

#include<iostream>
#include<stdlib.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////
//
//    Class Name  :  DoublyLL [Doubly Linear Linked List] 
// 
//    Description :  It is a Generic Doubly Linear Linked List Data Structure     
//                              
//    Author      :  Suyash Maruti Saykar
//
//    Date        :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
struct dnode
{
    int data;
    struct dnode<T>* next;
    struct dnode<T>* prev;

};

template <class T>
class DoublyLL
{
    private:
        dnode<T>* first;
        int size;

    public:

        DoublyLL();
        void InsertFirst (T);
        void InsertLast (T);
        void InsertAtPos (T, int);

        void DeleteFirst ();
        void DeleteLast ();
        void DeleteAtPos (int);
        
        int Count ();
        void Display ();
};


///////////////////////////////////////////////////////////////////////////////////
//
//    Constructor :  DoublyLL  
// 
//    Description :  Default Constructor of a class DoublyLL
//                              
//    Author      :  Suyash Maruti Saykar
//
//    Date        :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    size = 0;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  InsertFirst  
// 
//    Description   :  We can insert a first node in the 
//                     DOUBLY Linear Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>::InsertFirst(T Data)
{
    dnode<T>* newn = new dnode<T>;

    newn->data = Data;
    newn->prev = NULL;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    }
    size++; 
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  InsertLast  
// 
//    Description   :  We can insert a last node in the 
//                     Doubly linear Linked List by using this 
//                     function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>:: InsertLast(T Data)
{
    dnode<T>* newn = new dnode<T>;

    newn->data = Data;
    newn->prev = NULL;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else             
    {
        dnode<T>* temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
            temp->next = newn;
            newn->prev = temp;
    }
        size++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  InsertAtPos  
// 
//    Description   :  We can insert a node at desired position in the 
//                     Doubly Linear Linked List by using this function
//                     (Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void InsertAtPos(T Data, int pos)
{
    if ((pos < 1) || (pos > size+1))
    {
        return;
    }
            
    if (pos == 1)
    {
        InsertFirst(Data);
    }
    else if (pos == size+1)
    {
        InsertLast(Data);
    }
    else
    {
        dnode<T>* newn = new dnode<T>*;
        newn->prev = NULL;
        newn->next = NULL;
        newn->data = Data;

        dnode<T>* temp = first;

        for (int i = 1; i < (pos-1); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        size++;
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  DeleteFirst  
// 
//    Description   :  We can delete a first node of the 
//                     Doubly Linear Linked List by using this function
//                     (Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>:: DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
            
    size--;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  DeleteLast  
// 
//    Description   :  We can delete a last node of the 
//                     Doubly Linear Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void DeleteLast()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        dnode<T>* temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
    size--;            
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  DeleteAtPos  
// 
//    Description   :  We can delete a desired position node of the 
//                     Doubly Linear Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>:: DeleteAtPos(int pos)
{
    if (first == NULL)
    {
        return;
    }
    else if ((pos < 1) || (pos > size))
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
        dnode<T>* temp = first;
        for (int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        size--;                       
    }           
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Count  
// 
//    Description   :  We can count the number of nodes from the Doubly linear 
//                     Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLL<T>:: Count()
{
    return size;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Display  
// 
//    Description   :  We can display the Doubly Linear Linked List 
//                     by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>:: Display()
{
    dnode<T>* temp = first;

    if (size == 0)
    {
        return;
    }

    while (temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL\n";            
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//                                      END OF CLASS
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int main(int argc, char const *argv[])
{
    DoublyLL <float> dobj;

    dobj.InsertFirst(11);
    dobj.InsertFirst(2.14);
    dobj.InsertFirst(88.14);
    dobj.InsertFirst(111.14);
    dobj.InsertFirst(999.14);
    dobj.InsertFirst(5555.14);

    dobj.Display();
    int iRet = dobj.Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    dobj.DeleteAtPos(2);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    dobj.InsertAtPos(999.14,1);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of Elements are :"<<iRet<<endl;


    dobj.DeleteAtPos(6);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    return 0;
}
