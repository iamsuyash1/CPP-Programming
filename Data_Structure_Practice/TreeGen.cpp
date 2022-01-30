#include<iostream>
#include<stdlib.h>

using namespace std;

template<class T>
struct tnode
{
    T data;
    struct tnode<T>* lchild;
    struct tnode<T>* rchild;
};

template <class T>
class BST
{
    private:
        tnode<T>* root;
        int size;

    public:
        tnode<T>* temp;

        BST();
        void Insert(T Data);
        bool Search(T Data);
        int Count();
        int CountParentnode(tnode<T>* temp);
        int CountLeafnode(tnode<T>* temp);
        void Inorder(tnode<T>* temp);
        void PreOrder(tnode<T>* temp);
        void PostOrder(tnode<T>* temp);
};

template <class T>
BST<T>::BST()
{
    root = NULL;
    temp = NULL;
    size = 0;
}

template <class T>
void BST<T>:: Insert(T Data)
{
    tnode<T>* temp = root;

    tnode<T>* newn = new tnode<T>;
    newn->data = Data;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if (root == NULL)
    {
        root = newn;  
        this->temp = root;  
        size++;          
    }
    else
    {
        while (1)
        {
            if (temp->data == Data)
            {
                delete newn;
                break;
            }
            else if ( Data < (temp->data) )
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    size++;
                    break;
                }
                temp = temp->lchild;       
            }

            else if ( Data > (temp->data) )
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    size++;
                    break;
                }
                temp = temp->rchild;
            }
        }
    }
}

template <class T>
bool BST<T>:: Search(T Data)
{
    tnode<T>* temp = root;

    if (root == NULL)
    {
        return false;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == Data)
            {
                break;
            }
            else if (Data < temp->data)
            {
                temp = temp->lchild;
            }
            else if (Data > temp->data)
            {
                temp = temp->lchild;                        
            }
        }
    }
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class T>
int BST<T>:: Count()
{
    return size;
}

template <class T>
int BST<T>:: CountParentnode(tnode<T>* temp)
{
    static int iCnt = 0;

    if (temp != NULL)
    {
        if ((temp->lchild != NULL) || (temp->rchild != NULL))
        {
            iCnt++;
        }
        CountParentnode(temp->lchild);
        CountParentnode(temp->rchild);
    }
    return iCnt;

}

template <class T>
int BST<T>:: CountLeafnode(tnode<T>* temp)
{
    static int iCnt = 0;
    if (temp != NULL)
    {
        if ((temp->lchild == NULL) && (temp->rchild == NULL))
        {
            iCnt++;
        }
        CountLeafnode(temp->lchild);
        CountLeafnode(temp->rchild);
    }
    return iCnt;
}

template <class T>
void BST<T>:: Inorder(tnode<T>* temp)
{
    if (temp != NULL)
    {
        Inorder(temp->lchild);
        cout<<temp->data<<endl;
        Inorder(temp->rchild);
    }
}

template <class T>
void BST<T>:: PreOrder(tnode<T>* temp)
{
    if (temp != NULL)
    {
        cout<<temp->data<<endl;
        PreOrder(temp->lchild);
        PreOrder(temp->rchild);
    }
}

template <class T>
void BST<T>:: PostOrder(tnode<T>* temp)
{
    if (temp != NULL)
    {
        PostOrder(temp->lchild);
        PostOrder(temp->rchild);
        cout<<temp->data<<endl;
    } 
}

int main(int argc, char const *argv[])
{
    BST<double> bobj;
    bobj.Insert(51.4443);
    bobj.Insert(21.454);
    bobj.Insert(101);
    bobj.Insert(22);
    bobj.Insert(20);

    int iRet = bobj.CountParentnode(bobj.temp);
    cout<<"Number of nodes are : "<<iRet<<endl;
    
    bobj.Inorder(bobj.temp);

    bool bret = bobj.Search(7);
    if (bret == true)
    {
        cout<<"It is there\n";
    }
    else
    {
        cout<<"Not there\n";
    }
    
    cout<<"INorder\n";
    bobj.Inorder(bobj.temp);
    cout<<"Postorder\n";
    bobj.PostOrder(bobj.temp);
    cout<<"PREorder\n";
    bobj.PreOrder(bobj.temp);

    return 0;
}
