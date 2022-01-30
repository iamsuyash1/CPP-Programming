// SINGLY Linear Linked List

#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;

} NODE, *PNODE;

class SinglyLL
{
    private:

        PNODE first;
        int size;

    public :
        SinglyLL()
        {
            first = NULL;
            size = 0;
        }

    void InsertFirst(int no)
    {
        PNODE newn = new NODE;
        
        newn->data = no;
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
    void InsertLast(int no)
    {
        PNODE newn = new NODE;
        PNODE temp = first;

        newn->data = no;
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

    void InsertAtPos(int no, int ipos)
    {
        PNODE temp = first;

        if ((ipos < 1) || (ipos > (size + 1)))
        {
            return;
        }
        if (ipos == 1)
        {
            InsertFirst(no);
        }
        else
        {
            PNODE newn = new NODE;
            int iCnt = 1;

            newn->data = no;
            newn->next = NULL;
            
            while (iCnt != (ipos -1))
            {
                temp = temp->next;
                iCnt++;
            }
            newn->next = temp->next;
            temp->next = newn;            
        }
        size++;        
    }

    void DeleteFirst()
    {
        PNODE temp = first;
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

    void DeleteLast()
    {
        PNODE temp = first;
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

    void DeleteAtPos(int ipos)
    {
        PNODE temp = first;
        int icnt = 1;

        if ((ipos < 1) || (ipos > size))
        {
            return;
        }
        else if (ipos == 1)
        {
            DeleteFirst();
            size--;
        }
        else
        {
            while (icnt != (ipos-1))
            {
                temp = temp->next;
                icnt++;
            }
            PNODE targeted = temp->next;
            temp->next = targeted->next;
            delete targeted;
            targeted = NULL;

            size--;
        }
    }

    void Display()
    {
        PNODE temp = first;

        while (temp->next != NULL)
        {
            cout<<(temp->data)<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
        
    }   
    int Count()
    {
        return size;
    }     

    static void CreateObj()
    {
        SinglyLL obj;
        int iRet = 0; 

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.InsertLast(101);

        obj.DeleteAtPos(2);
        obj.Display();

        iRet = obj.Count();
        cout<<"Number of elements are : "<<iRet<<endl;
    }
};

int main(int argc, char const *argv[])
{
    //SinglyLL obj;
    //int iRet = 0;

    SinglyLL::CreateObj();    

    

    return 0;
}

