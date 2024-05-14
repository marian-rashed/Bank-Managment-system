#ifndef BANK_H
#define BANK_H
#include "Teller.h"
#include "Customer.h"
#include <iostream>
#include <queue>
#include<ctime>

using namespace std;

struct CompareByArrivalTime
{
    bool operator()(const Customer &c1, const Customer &c2) const
    {
            return c1.GetArrivalTime() > c2.GetArrivalTime();
    }
};



class Bank
{
    priority_queue<Customer, vector<Customer>, CompareByArrivalTime> CustomerQueue;

    Teller Tellers[3];
    float totalwaitingtime=0;
    float totalservicetime=0;
    float tellerutilization=0;

public:
    Bank()
    {
        for(int i=0; i<3; i++)
        {
            Tellers[i].SetIsAvailable(true);
            Tellers[i].SetTellerNum(i+1);
        }
    }

    void Enqueue(const Customer &customer)
    {
        CustomerQueue.push(customer);
        cout<<"customer added successfully \n";
        cout<<"--------------------------------------"<<endl;
    }

    void DisplayCustomer()
    {
        priority_queue<Customer, vector<Customer>, CompareByArrivalTime> tempQueue = CustomerQueue;

        while(!tempQueue.empty())
        {
            Customer Customer=tempQueue.top();
            cout<<"Customer id: "<<Customer.GetId()<<endl;
            cout<<"Customer name: "<<Customer.GetName()<<endl;
            cout<<"Customer arrival time: "<<Customer.GetArrivalTime()<<endl;
            cout<<"Customer service time: "<<Customer.GetServiceTime()<<endl;
            cout<<"Customer not special: "<<Customer.GetIsSpecial()<<endl;
            tempQueue.pop();
            cout<<"\n";
        }
    }

    void Dequeue()
    {
        if(!CustomerQueue.empty())
        {
            CustomerQueue.pop();
        }
        else
        {
            cout<<"Queue Is Empty";
        }
    }



public:

    int CheckTellerAvailability()
    {
        for (int i = 0; i < 3; i++)
        {
            if (Tellers[i].GetIsAvailable())
            {
                return i;

            }
        }
        return -1;
    }


    void AssignCustomerToAvailableTeller()
    {
        int numofcustomer=0;
        cout<<"Customers Details:"<<endl;
        cout<<"-----------------"<<endl;
        while(!CustomerQueue.empty())
        {

            int availableTellerIndex =CheckTellerAvailability();
            if(availableTellerIndex != -1)
            {
                Customer c1=CustomerQueue.top();
                Teller &currentteller=Tellers[availableTellerIndex];
                c1.SetWaitingTime(0);
                c1.SetLeavingtime(c1.GetArrivalTime() + c1.GetServiceTime());
                Tellers[availableTellerIndex].SetIsAvailable(0);
                currentteller.SetTimeTellerIsFree(c1.GetLeavingtime());
                CustomerQueue.pop();
                totalwaitingtime +=c1.GetWaitingTime();
                totalservicetime +=c1.GetServiceTime();
                cout<<"Customer\tTeller \t\tWaiting Time \t\tLeaving Time"<<endl;
                cout<<c1.GetId()<<"\t\t"<<availableTellerIndex +1<<"\t\t"<<c1.GetWaitingTime()<<"\t\t\t"<<c1.GetLeavingtime()<<endl;

                numofcustomer +=1;
                currentteller.IncrementCustomersServed();
            }
            else
            {
                int Min=Tellers[0].GetTimeTellerIsFree();
                int indexoffreeteller=0;
                for(int i=0; i<3; i++)
                {
                    if(Tellers[i].GetTimeTellerIsFree() < Min)
                    {
                        Min=Tellers[i].GetTimeTellerIsFree();
                        indexoffreeteller=i;

                    }

                }

                Customer c1=CustomerQueue.top();
                Teller &currentteller=Tellers[indexoffreeteller];
                c1.SetWaitingTime(currentteller.GetTimeTellerIsFree()-c1.GetArrivalTime());
                c1.SetLeavingtime(c1.GetArrivalTime() + c1.GetServiceTime()+c1.GetWaitingTime());
                Tellers[indexoffreeteller].SetIsAvailable(0);
                currentteller.SetTimeTellerIsFree(c1.GetLeavingtime());
                CustomerQueue.pop();
                totalwaitingtime +=c1.GetWaitingTime();
                totalservicetime +=c1.GetServiceTime();
                cout<<"Customer\tTeller \t\tWaiting Time \t\tLeaving Time"<<endl;
                cout<<c1.GetId()<<"\t\t"<<indexoffreeteller +1<<"\t\t"<<c1.GetWaitingTime()<<"\t\t\t"<<c1.GetLeavingtime()<<endl;
                numofcustomer +=1;
                currentteller.IncrementCustomersServed();

            }
        }

        cout<<"Tellers Details:"<<endl;
        cout<<"----------------"<<endl;
        for (int i = 0; i < 3; i++)
        {
            cout<<"Teller\t\t Percentage for teller utilization"<<endl;
            cout << i + 1 << "\t\t  " <<(static_cast<float>(Tellers[i].GetNumCustomersServed()) / numofcustomer) * 100 <<"%"<< endl;

        }



        cout<<"Calculate Average:"<<endl;
        cout<<"------------------"<<endl;
        cout<<"Average of waiting time:"<<totalwaitingtime / numofcustomer <<endl;
        cout<<"Average of service time:"<<totalservicetime / numofcustomer <<endl;

    }


};

#endif // BANK_H
