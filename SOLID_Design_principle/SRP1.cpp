// Single Responsibility Principle

#include<iostream>
using namespace std;


// This class is just dealing with the Bank Account
class BankAccount
{
    public:
        void credit()
        {cout<<"Your account is credited by AMOUNT"<<endl;}

        void Debit()
        {cout<<"Your account is debited by AMOUNT"<<endl;}
};


//  This class is dealing with the sending update to the user
//  If the sentMail() method is in the Bank class, 
//  then whenever we want to change the way of sending update to the user, 
//  we have to do changes in the Bank class and this is a violation of single responsibility principle

class UpdateMessage
{
    public:
        void sentMail()
        {
            cout<<"Sending mail..."<<"\n";
        }
};