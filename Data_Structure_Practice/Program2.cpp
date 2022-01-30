// Doubly Linear Linked List Data Structure

#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;

} NODE, *PNODE;

class DoublyLL
{
    private:
        PNODE first;
        int size;

    public:

        DoublyLL()
        {
            first = NULL;
            size = 0;
        }

        void InsertFirst(int Data)
        {
            PNODE newn = new NODE;

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

        void InsertLast(int Data)
        {
            PNODE newn = new NODE;

            newn->data = Data;
            newn->prev = NULL;
            newn->next = NULL;

            if (first == NULL)
            {
                first = newn;
            }
            else             
            {
                PNODE temp = first;

                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
                newn->prev = temp;
            }
            size++;
        }

        void InsertAtPos(int Data, int pos)
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
                PNODE newn = new NODE;
                newn->prev = NULL;
                newn->next = NULL;
                newn->data = Data;

                PNODE temp = first;

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


        void DeleteFirst()
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
                PNODE temp = first;

                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->prev->next = NULL;
                delete temp;
            }
            size--;            
        }

        void DeleteAtPos(int pos)
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
                PNODE temp = first;
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

        int Count()
        {
            return size;
        }

        void Display()
        {
            PNODE temp = first;

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
};

int main(int argc, char const *argv[])
{
    
    DoublyLL dobj;

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
