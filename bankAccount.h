//
// Created by Alshoki on 11/3/2022.
//

#ifndef UNTITLED10_BANKACCOUNT_H
#define UNTITLED10_BANKACCOUNT_H

#include "bits/stdc++.h"
template <class T> class client;
using  namespace std;
class bankAccount {
protected:
    client<bankAccount> * person = nullptr;

    double balance;
public:
    //constructors
    bankAccount();
    bankAccount(double);

    //getters and setters
    void setBalance(double);
    double getBalance();
    void setClient(client<bankAccount>&);
    client<bankAccount>& getClient();

    virtual void withdraw();
    virtual void deposit();

};

class savingAccount : public bankAccount{
private:
    client<savingAccount> * savingPerson = nullptr;
    double minBalance;
public:
    //constructors
    savingAccount();
    savingAccount(double, double);

    //getters and setters
    double getMinBalance();
    void setMinBalance(double);
    void setClient(client<savingAccount>&);

    void withdraw();
    void deposit();


};

#endif //UNTITLED10_BANKACCOUNT_H
