#include<iostream>
using namespace std;

int SumI(int Arr[], int iSize)
{
    int static iSum = 0;
    static int i = 0;
    
    if(i < iSize)
    {
        iSum = iSum + Arr[i];
        i++;

        SumI(Arr,iSize);
    }
    
    return iSum;
}

int main()
{
    int iLength = 0, i = 0, iRet = 0;
    int *p = NULL;
    
    cout<<"Enter number of elements\n";
    cin>>iLength;
    
    p = new int[iLength];
    
    cout<<"Enter the elements\n";
    
    for(i = 0; i < iLength; i++)
    {
        cin>>p[i];
    }

    iRet = SumI(p,iLength);
    cout<<"Addition is : "<<iRet<<"\n";
    
    delete []p;
    
    return 0;
}
