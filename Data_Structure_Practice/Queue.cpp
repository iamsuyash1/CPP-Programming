// Queue Data Structure

#include<iostream>
using namespace std;

template <class T>
struct qnode
{
    T data;
    struct qnode<T>* next;
};

///////////////////////////////////////////////////////////////////////////////////
//
//    Class Name  :  Queue 
// 
//    Description :  It is a Generic Queue Data Structure     
//                              
//    Author      :  Suyash Maruti Saykar
//
//    Date        :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
class Queue     
{
private:
    qnode<T>* first;
    int size;
    
public:
    Queue();
    void Enqueue(T DATA);  
    T Dequeue();
    void Display();
    int Count();
};

///////////////////////////////////////////////////////////////////////////////////
//
//    Constructor :  Queue 
// 
//    Description :  Default Constructor of a class Queue     
//                              
//    Author      :  Suyash Maruti Saykar
//
//    Date        :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
Queue<T>::Queue()
{
    first = NULL;
    size = 0;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Enqueue  
// 
//    Description   :  We can insert a node in the 
//                     Queue by using this function(Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
void Queue<T>:: Enqueue(T DATA)  
{
    qnode<T>* newn = new qnode<T>;
    newn->data = DATA;
    newn -> next = NULL;
    
    if(size == 0)   
    {
        first = newn;
    }
    else
    {
        qnode<T>* temp = first;
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
    }
    size++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Dequeue  
// 
//    Description   :  We can delete a node from the 
//                     Queue and return the deleted data 
//                     by using this function (Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>    
T Queue<T>:: Dequeue()   
{
    T DelData;
    qnode<T>* temp = first;
            
    if(size == 0)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
               
    if(size == 1)
    {
        DelData = first->data;
        delete first;
        first = NULL;
    }
    else
    {
        DelData = first->data;
        first = first -> next;
        delete temp;
    }
               
    size--;
    return DelData;
        
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Display  
// 
//    Description   :  We can Display the data from the 
//                     Queue by using this function (Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>    
void Queue<T>:: Display()
{
    qnode<T>* temp = first;

    for(int i = 1 ; i <= size; i++, temp = temp->next)
    {
        cout<<"|"<<temp->data<<"|-> ";
    }
    cout<<"\n";
}


///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :  Count  
// 
//    Description   :  We can Count the elements from the 
//                     Queue by using this function (Generic Function).     
//                              
//    Author        :  Suyash Maruti Saykar
//
//    Date          :  17 November 2021
//
///////////////////////////////////////////////////////////////////////////////////
template <class T>
int Queue<T>:: Count()
{
    return size;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    Queue<float> qobj; 
    
    qobj.Enqueue(11);
    qobj.Enqueue(21);
    qobj.Enqueue(5.31);
    qobj.Enqueue(101);
    
    cout<<"Elements of Queue :\n";
    
    qobj.Display();
    int iret = qobj.Count();     
    cout<<"Size of queue is : "<<iret<<"\n"; 

    iret = qobj.Dequeue();
    cout<<"Removed element from queue"<<iret<<"\n";  
    
    cout<<"Elements from queue : \n";
    qobj.Display();          
    iret = qobj.Count();     
    
    cout<<"Size of queue is : "<<iret<<"\n"; 
    
    return 0;
}