#include<iostream>
#include<stdlib.h>
#include<stdbool.h>

using namespace std;

typedef struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;

} NODE,*PNODE,**PPNODE;


void Insert(PPNODE Head, int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;
    

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        PNODE temp = *Head;
        while (1)   //Unconditional Loop        for(; ;)
        {
            if (temp->data == no)
            {
                cout<<"Duplicate node\n";

                delete newn;
                break;
            }
            else if (temp->data > no)
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if (temp->data < no)
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }  
        }
    }    
}

bool Serach(PNODE Head, int no)
{
    bool flag = false;
    if (Head == NULL)
    {
        return false;
    }
    else
    {    
        while (Head != NULL)
        {
            if (Head->data == no) //node sapadla;
            {
                flag = true;        
                break;    
            }
            else if (no > (Head->data))
            {
                Head = Head->rchild;   
            }
            else if (no < (Head->data))
            {
                Head = Head->lchild;                
            }
        }
        return flag;
    } 
}

int Count(PNODE Head)
{
    static int iCnt = 0;

    if (Head != NULL)
    {
        iCnt++;
        Count(Head->lchild);
        Count(Head->rchild);
    }
    return iCnt;
    
}

int main(int argc, char const *argv[])
{
    PNODE first = NULL;
    int no = 0;
    Insert(&first,51);
    Insert(&first,21);
    Insert(&first,101);

    cout<<"Enter Number to search\n";
    cin>>no;

    /*
    bool bret = false;
    bret = Serach(first,no);
    if (bret == true)
    {
        cout<<"Data is there\n";
    }
    else
    {
        cout<<"Data is not there\n";
    }
    */

    int iRet = Count(first);
    cout<<"Number of nodes are : "<<iRet<<endl;

    return 0;
}
