#include<iostream>
using namespace std;

/*
    =>  Liskov Substitution Principle : Parent class should be replaceable by child class

    =>  Here are two classes, 1) Square and 2) Rectangle
        Both class have a functionality to find the area of the particular shape.

    =>  Here we can see, if we don't inherit the Square class still 
        we can find the area of the square using the functionality of the Rectangle class.
*/

class Square
{
    public:
        int side;
        Square(){side = 0;}
        Square(int a){side = a;}
        int areaSquare(){cout<<"Parent : Area of the square\n"; return side*side;}
};

class Rectangle
{
    public:
        int length, breadth;
        Rectangle(int l) 
        {
            cout<<"Works for SQUARE area\n";
            length = l;
            breadth = l;
        }
        Rectangle(int l , int b )
        {
           cout<<"Works for RECTANGLE area\n";
           length = l;
           breadth = b;
        }
        int areaRectangle(){ cout<<"Child :\n"; return length*breadth;}
};

int main()
{
    cout<<"============================================================"<<endl;

    Rectangle R1 (10);                  // First constructor will get called
    cout<<"Side: "<<R1.length<<"\n";
    cout<<"Side: "<<R1.breadth<<"\n";
    cout<<"Area of the square : "<<R1.areaRectangle()<<endl;
    cout<<endl;
    cout<<"============================================================"<<endl;
    
    Rectangle R2 (10,20);               // Second constructor will get called
    cout<<"Length: "<<R2.length<<"\n";
    cout<<"Breadth: "<<R2.breadth<<"\n";
    cout<<"Area of the rectangle : "<<R2.areaRectangle()<<endl;
}