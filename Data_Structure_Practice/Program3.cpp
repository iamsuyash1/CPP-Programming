//Singly Circular List

#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node
{
    int data;
    struct node* next;
} NODE, *PNODE;

class SinglyCircular
{
    private:
        PNODE first;
        PNODE last;
        int size;

    public:
        SinglyCircular()
        {
            first = NULL;
            last = NULL;
            size = 0;
        }
        ~SinglyCircular()
        {}
        
        void Display()
        {
            PNODE temp = first;

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

        int Count()
        {
            return size;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn->data = no;
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

        void InsertLast(int no)
        {
            PNODE newn = new NODE;

            newn->data = no;
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

        void InsertAtPos(int no, int ipos)
        {
            if ((ipos < 1) || (ipos > (size+1)))
            {
                return;
            }
            
            if (ipos == 1 )
            {
                InsertFirst(no);
            }
            else if (ipos == (size+1))
            {
                InsertLast(no);
            }
            else
            {
                PNODE temp = first;
                int iCnt = 0;

                PNODE newn = new NODE;
                newn->data = no;
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

        void DeleteFirst()
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

        void DeleteLast()
        {
            PNODE temp = first;

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

        void DeleteAtPos(int ipos)
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
                PNODE temp = first;
                int iCnt = 1;

                while (iCnt != ipos-1)
                {
                    temp = temp->next;
                    iCnt++;
                }
                
                PNODE targeted = temp->next;
                temp->next = targeted->next;
                delete targeted;
                targeted = NULL;

                size--;
                
            }     
        }
};

int main(int argc, char const *argv[])
{
    SinglyCircular obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    obj.InsertLast(101);    
    obj.Display();
    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();
    obj.InsertAtPos(333,2);
    obj.Display();
    
    int iRet = obj.Count();
    cout<<"Count is : "<<iRet<<endl;
    cout<<"+++++++++++++++++++++++++++++++++"<<endl;


    obj.DeleteAtPos(2);
    obj.Display();
    
    iRet = obj.Count();
    cout<<"Count is : "<<iRet<<endl;


    return 0;
}
