#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;

} NODE, *PNODE;

class Tree
{
    private:
        PNODE first;
        int size;

    public:
        
        Tree()
        {
            first = NULL;
            size = 0;
        }

        void InsertNode(int Data)
        {
            PNODE newn = new NODE;

            newn->data = Data;
            newn->lchild = NULL;
            newn->rchild = NULL;

            PNODE temp = first;

            if (first == NULL)
            {
                first = newn;
            }
            
            while (1)
            {
                if (temp->data == Data)
                {
                    delete newn;
                    break;
                }
                else if (Data < temp->data)
                {
                    if (temp->lchild != NULL)
                    {
                        
                    }
                    
                }
                
                
            }
            
            
            
        }
};