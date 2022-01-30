//Doubly Circular Linked List

#include<iostream>
#include<stdlib.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//    Class Name  :  DoublyCircular [Doubly Circular Linked List] 
// 
//    Description :  It is a Generic Doubgly Circular Linked List Data Structure     
//                              
//    Author      :  Suyash Maruti Saykar
//
//    Date        :  17 November 2021
//
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct dcnode
{
    T data;
    struct dcnode<T>* next;
    struct dcnode<T>* prev;

};

template <class T>
class DoublyCircular
{
    private:
        dcnode<T>* first;
        dcnode<T>* last;
        int size;

    public:
        
        DoublyCircular();
        void Display();
        int Count();
        void InsertFirst(T Data);
        void InsertLast(T Data);
        void InsertAtPos(T Data, int pos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
        
};


//////////////////////////////////////////////////////////////////////////////////////////////
// =================== All Method Definations of class DoublyCircular ======================
//////////////////////////////////////////////////////////////////////////////////////////////
//    Constructor :  DoublyCircular  
// 
//    Description :  Default Constructor of a class DoublyCircular
//                              
//    Author      :  Suyash Maruti Saykar
//
//    Date        :  17 November 2021
//
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyCircular<T>::DoublyCircular()
{
    first = NULL;
    last = NULL;
    size = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Display  
// 
//    Description   :  We can display the Doubly Circular Linked List 
//                     by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCircular<T> :: Display()
{
    dcnode<T>* temp = first;
    if ((first == NULL) && (last== NULL))
    {
        return;
    }
    
    for (int i = 1; i <= size; i++)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;    
    }
    cout<<endl;  

}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Count  
// 
//    Description   :  We can count the number of nodes from the Doubly Linked 
//                     Circular Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCircular<T> ::Count()
{
    return size;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  InsertFirst  
// 
//    Description   :  We can insert a first node in the 
//                     Doubly Circular Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCircular<T> :: InsertFirst(T Data)
{
    dcnode<T>* newn = new dcnode<T>;

    newn->data = Data;
    newn->next = NULL;
    newn->prev = NULL;

    if (size == 0)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;
    size++;

}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  InsertLast  
// 
//    Description   :  We can insert a last node in the 
//                     Doubly Circular Linked List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCircular<T> :: InsertLast(T Data)
{
    dcnode<T>* newn = new dcnode<T>;

    newn->data = Data;
    newn->next = NULL;
    newn->prev = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    first->prev = last;
    last->next = first;
    size++;    
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  InsertAtPos  
// 
//    Description   :  We can insert a node at desired position in the 
//                     Doubly Circular Linked List by using this 
//                     function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCircular<T> :: InsertAtPos(T Data, int pos)
{
    if (size == 0)
    {
        InsertFirst(Data);
    }
    else if (pos == size+1)
    {
        InsertLast(Data);
    }
    else
    {
        dcnode<T>* newn = new dcnode<T>;
        newn->data = Data;
        newn->next = NULL;
        newn->prev = NULL;

        dcnode<T>* temp = first;

        int iCnt = 1;

        while (iCnt != (pos-1))
        {
            temp = temp->next;
            iCnt++;    
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp; 
        size++;       
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  DeleteFirst  
// 
//    Description   :  We can delete a first node of the 
//                     Doubly Circular Linked List by using this 
//                     function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCircular<T> :: DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }    

    size--;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  DeleteLast  
// 
//    Description   :  We can delete a last node of the 
//                     Doubly Cicular Linked List by using 
//                     this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCircular<T> :: DeleteLast()
{
    if (size == 0)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;

        first->prev = last;
        last->next = first;
    }

    size--;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  DeleteAtPos  
// 
//    Description   :  We can delete a desired position node of the 
//                     Doubly Circular Linked List by using this 
//                     function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCircular<T> :: DeleteAtPos(int pos)
{
    int iCnt = 1;

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
        dcnode<T>* temp = first;
        while (iCnt != pos-1)
        {
            temp = temp->next;
            iCnt++;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        size--;
        
    } 
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//                                      END OF CLASS
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int main(int argc, char const *argv[])
{
    DoublyCircular<float> dcobj;

    dcobj.InsertFirst(51);
    dcobj.InsertFirst(21);
    dcobj.InsertFirst(11);

    dcobj.InsertLast(101);

    dcobj.Display();
    int iRet = dcobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    dcobj.InsertAtPos(999,2);

    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    dcobj.DeleteAtPos(2);

    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    dcobj.DeleteAtPos(1);

    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    dcobj.DeleteAtPos(3);

    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    dcobj.DeleteLast();

    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    dcobj.DeleteLast();

    dcobj.Display();
    iRet = dcobj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    return 0;
}
