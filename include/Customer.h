#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
using namespace std;

class Customer
{
private:
    int ID;
    string NAME;
    int ARRIVALTIME;
    int SERVICETIME;
    int WAITINGTIME;
    int LEAVINGTIME;
    bool ISSPESIAL;

public:

    Customer(){}
    Customer(int id,string name,int arrivaltime,int servicetime,bool isspecial)
    {
        SetId(id);
        SetName(name);
        SetArrivalTime(arrivaltime);
        SetServiceTime(servicetime);
        SetIsSpecial(isspecial);
    }
    void SetId(int id)
    {
        ID=id;
    }

    int GetId()
    {
        return ID;
    }


    void SetName(string name)
    {
        NAME=name;
    }

    string GetName()
    {
        return NAME;
    }

    void SetArrivalTime(int arrivaltime)
    {
        ARRIVALTIME=arrivaltime;
    }

    int GetArrivalTime() const
    {
        return ARRIVALTIME;
    }


    void SetServiceTime(int servicetime)
    {
        SERVICETIME=servicetime;
    }

    int GetServiceTime()
    {
        return SERVICETIME;
    }


    void SetWaitingTime(int WaitingTime)
    {
        WAITINGTIME=WaitingTime;
    }

    int GetWaitingTime()
    {
        return WAITINGTIME;
    }


    void SetLeavingtime(int Leavingtime)
    {
        LEAVINGTIME=Leavingtime;
    }

    int GetLeavingtime()
    {
        return LEAVINGTIME;
    }



    void SetIsSpecial(bool isspecial)
    {
        ISSPESIAL=isspecial;
    }

    int GetIsSpecial()const
    {
        return ISSPESIAL;
    }

};

#endif // CUSTOMER_H
