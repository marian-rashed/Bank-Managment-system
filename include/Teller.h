#ifndef TELLER_H
#define TELLER_H
#include "Customer.h"




class Teller
{
private:
    bool ISAVAILABLE;
    int TellerNum;
    int TimeTellerIsFree;
    int CustomersServed;

public:
    Teller()
    {
        CustomersServed=0;
    }

    void SetIsAvailable(bool isavailable)
    {
        ISAVAILABLE=isavailable;
    }

    bool GetIsAvailable()
    {
        return ISAVAILABLE;
    }


    void SetTellerNum(int tellernum)
    {
        TellerNum=tellernum;
    }

    int GetTellerNum()
    {
        return TellerNum;
    }


    void SetTimeTellerIsFree(int timetellerisfree)
    {
        TimeTellerIsFree=timetellerisfree;
    }

    int GetTimeTellerIsFree()
    {
        return TimeTellerIsFree;
    }


    void IncrementCustomersServed()
    {
        CustomersServed++;
    }

    int GetNumCustomersServed()
    {
        return CustomersServed;
    }

};

#endif // TELLER_H
