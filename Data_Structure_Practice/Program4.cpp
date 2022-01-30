//Doubly Circular Linked List

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;

} NODE, *PNODE;

class DoublyCl
{
    private:
        PNODE first;
        PNODE last;
        int size;

    public:
        
        DoublyCl();
        void Display();
        int Count();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int pos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
        
};

DoublyCl::DoublyCl()
{
    first = NULL;
    last = NULL;
    size = 0;
}

void DoublyCl :: Display()
{
    PNODE temp = first;
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

int DoublyCl ::Count()
{
    return size;
}

void DoublyCl :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
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

void DoublyCl :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
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

void DoublyCl :: InsertAtPos(int no, int pos)
{
    if (size == 0)
    {
        InsertFirst(no);
    }
    else if (pos == size+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        PNODE temp = first;

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

void DoublyCl :: DeleteFirst()
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

void DoublyCl :: DeleteLast()
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

void DoublyCl :: DeleteAtPos(int pos)
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
        PNODE temp = first;
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

int main(int argc, char const *argv[])
{
    DoublyCl obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);

    obj.Display();
    int iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    obj.InsertAtPos(999,2);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    obj.DeleteAtPos(2);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    obj.DeleteAtPos(1);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    obj.DeleteAtPos(3);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<endl;
    cout<<endl;

    return 0;
}
