//Singly Circular List

#include<iostream>
#include<stdlib.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////
//
//    Class Name  :  SinglyCircular [Singly Circular Linked List] 
// 
//    Description :  It is a Generic Singly Circular Linked List Data Structure     
//                              
//    Author      :  Suyash Maruti Saykar
//
//    Date        :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////

template <class T>
struct scnode
{
    T data;
    struct scnode<T>* next;

};

template <class T>
class SinglyCircular
{
    private:
        scnode<T>* first;
        scnode<T>* last;
        int size;

    public:
        SinglyCircular();
        void Display();
        int Count();
        void InsertFirst(T Data);
        void InsertLast(T Data);
        void InsertAtPos(T, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        
};


///////////////////////////////////////////////////////////////////////////////////
//
//    Constructor :  SinglyCircular  
// 
//    Description :  Default Constructor of a class SinglyCircular
//                              
//    Author      :  Suyash Maruti Saykar
//
//    Date        :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyCircular<T>::SinglyCircular()
{
    first = NULL;
    last = NULL;
    size = 0;
}


///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Display  
// 
//    Description   :  We can display the SINGLY Circular Linked List 
//                     by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>        
void SinglyCircular<T>:: Display()
{
    scnode<T>* temp = first;

    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    do
    {
        cout<<"|"<<(temp->data)<<"|"<<"->";
        temp = temp->next;

    } while (temp != last->next);

    cout<<endl;   
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Count  
// 
//    Description   :  We can count the number of nodes from the SINGLY Linked 
//                     Circular List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCircular<T>:: Count()
{
    return size;
}


///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  InsertFirst  
// 
//    Description   :  We can insert a first node in the 
//                     SINGLY Circular List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircular<T>:: InsertFirst(T Data)
{
    scnode<T>* newn = NULL;
    newn = new scnode<T>;

    newn->data = Data;
    newn->next = NULL;

    if ((first == NULL) && (last == NULL))
    {

        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;                
    }

    last->next = first;
    size++;
}


///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  InsertLast  
// 
//    Description   :  We can insert a last node in the 
//                     SINGLY Circular List by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircular<T>:: InsertLast(T Data)
{
    scnode<T>* newn = new scnode<T>;

    newn->data = Data;
    newn->next = NULL;

    if (size == 0)
    {
        return;
    }
    else
    {
        last->next = newn;
        last = newn;
    }

    last->next = first;
    size++;            
}


///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  InsertAtPos  
// 
//    Description   :  We can insert a node at desired position in the 
//                     SINGLY Circular Linked List by using this 
//                     function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircular<T>:: InsertAtPos(T Data, int ipos)
{
    if ((ipos < 1) || (ipos > (size+1)))
    {
        return;
    }
            
    if (ipos == 1 )
    {
        InsertFirst(Data);
    }
    else if (ipos == (size+1))
    {
        InsertLast(Data);
    }
    else
    {
        scnode<T>* temp = first;
        int iCnt = 0;

        scnode<T>* newn = new scnode<T>;
        newn->data = Data;
        newn->next = NULL;

        while (iCnt != (ipos))
        {
            iCnt++;
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        size++;
    }           
            
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  DeleteFirst  
// 
//    Description   :  We can delete a first node of the 
//                     SINGLY Circular Linked List by using this 
//                     function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircular<T>:: DeleteFirst()
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
        first = first->next;
        delete last->next;
        last->next = first;
    }

    size--;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  DeleteLast  
// 
//    Description   :  We can delete a last node of the 
//                     SINGLY Cicular Linked List by using 
//                     this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircular<T>:: DeleteLast()
{
    scnode<T>* temp = first;

    if (size == 0)
    {
        return;
    }
    if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        while (temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;

        last->next = first;
    }
    size--;
}


///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  DeleteAtPos  
// 
//    Description   :  We can delete a desired position node of the 
//                     SINGLY Circular Linked List by using this 
//                     function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircular<T>:: DeleteAtPos(int ipos)
{
    if ((ipos < 1) || (ipos > size))
    {
        return;
    }
    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == size)
    {
        DeleteLast();
    }
    else
    {
        scnode<T>* temp = first;
        int iCnt = 1;

        while (iCnt != ipos-1)
        {
            temp = temp->next;
            iCnt++;
        }
                
        scnode<T>* targeted = temp->next;
        temp->next = targeted->next;
        delete targeted;
        targeted = NULL;

        size--;                
    }     
}

int main(int argc, char const *argv[])
{
    SinglyCircular <float> scobj;

    scobj.InsertFirst(51);
    scobj.InsertFirst(21);
    scobj.InsertFirst(11);
    scobj.Display();
    scobj.InsertLast(101);    
    scobj.Display();
    scobj.DeleteFirst();
    scobj.DeleteLast();
    scobj.Display();
    scobj.InsertAtPos(333,2);
    scobj.Display();
    
    int scRet = scobj.Count();
    cout<<"Count is : "<<scRet<<endl;
    cout<<"+++++++++++++++++++++++++++++++++"<<endl;


    scobj.DeleteAtPos(2);
    scobj.Display();
    
    scRet = scobj.Count();
    cout<<"Count is : "<<scRet<<endl;


    return 0;
}
