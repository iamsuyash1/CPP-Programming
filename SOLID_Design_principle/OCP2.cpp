#include<iostream>
using namespace std;
/*
    This class is open for the extention but closed for the modification
    This class contains abstract method i.e. area()
    And we can implement this method according to the shape.
*/

class Shape
{
    public:
        virtual int area() = 0;
};

class Circle: private Shape
{
    public:
        int area()  {cout<<"This is the area of the Circle \n"; return 0;}
};

class Rectangle : private Shape
{
    public:
        int area()  {cout<<"This is the area of the Rectangle \n"; return 0;}
        
};

int main(int argc, char const *argv[])
{
    Circle c;
    c.area();
    Rectangle r;
    r.area();
    return 0;
}
