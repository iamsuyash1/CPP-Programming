#include<stdlib.h>
#include<iostream>
using namespace std;
// Dangling pointer is pointer which still points to the memory location of the deallocated memory.

int main()
{
    int a = 10;
	int *first;
	int *second;

	first = (int*)malloc(sizeof(a));
	if(NULL == first)
	{
		cout<<"Unable to allocate memory"<<endl;
		return 0;
	}

    first = &a;

	// copy the contents of first pointer into second pointer
	// Means first and second pointer pointing to the same memory locations.

	second = first;

	// Deallocate the meory by using first pointer
	free(first);

	// Now second pointer is pointing to such a memory which is not existing
	// Now second pointer is called as Dangling pointer

	// If we tries to access memory locations with the help of second pointer
	// then there is a segmentation fault

	return 0;
}