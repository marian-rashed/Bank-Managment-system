#include <iostream>
#include "Bank.h"
#include "Teller.h"
#include "Customer.h"
using namespace std;

int main()
{
    Bank bank;
    int CustomerNum;
    int CustomerId;
    string CustomerName;
    int ArrivalTime;
    int ServiceTime;
    bool IsSpecial;
    cout<<"Enter Number Of Customer: \n";
    cin>>CustomerNum;

    for(int i=0; i<CustomerNum; i++)
    {

        Customer customer;
        cout<<"Enter id of customer "<<i+1<<endl;
        cin>>CustomerId;
        customer.SetId(CustomerId);

        cout<<"Enter name of customer "<<i+1<<endl;
        cin>>CustomerName;
        customer.SetName(CustomerName);

        cout<<"Enter Arrivaltime of customer "<<i+1<<endl;
        cin>>ArrivalTime;
        customer.SetArrivalTime(ArrivalTime);

        cout<<"Enter Servicetime of customer "<<i+1<<endl;
        cin>>ServiceTime;
        customer.SetServiceTime(ServiceTime);

        cout<<"Enter Isspecial of customer "<<i+1<<"(0 for special or 1 for normal)"<<endl;
        cin>>IsSpecial;
        customer.SetIsSpecial(IsSpecial);

        bank.Enqueue(customer);
    }


    bank.AssignCustomerToAvailableTeller();


    return 0;
}
