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
        while (1) 
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

int CountLeaf(PNODE Head)
{
    static int iCnt = 0;

    if (Head != NULL)
    {
        if ((Head->lchild == NULL) && (Head->rchild == NULL))
        {
            iCnt++;
        }
        
        CountLeaf(Head->lchild);
        CountLeaf(Head->rchild);
    }
    return iCnt;
}

int CountParent(PNODE Head)
{
    static int iCnt = 0;

    if (Head != NULL)
    {
        if ((Head->lchild != NULL) || (Head->rchild != NULL))
        {
            iCnt++;
        }
        
        CountParent(Head->lchild);
        CountParent(Head->rchild);
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

    int iRet = Count(first);
    cout<<"Number of nodes are : "<<iRet<<endl;

    iRet = CountLeaf(first);
    cout<<"Number of Leaf nodes are : "<<iRet<<endl;

    iRet = CountParent(first);
    cout<<"Number of Parent nodes are : "<<iRet<<endl;

    return 0;
}
