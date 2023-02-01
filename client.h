//
// Created by Alshoki on 11/3/2022.
//

#ifndef UNTITLED10_CLIENT_H
#define UNTITLED10_CLIENT_H


#include "bits/stdc++.h"
class bankAccount;
class savingAccount;

using  namespace std;

template<class T>
class client{
    string name, address , ID = "FCAI-" , telephone;
    T * account;
    bool checkTelephone(string&);
public:
    // constructors
    client();
    client(T& ,string ,string , string);
    client(string,T&,string , string , string);

    //getters and setters
    string getID();
    string getAddress();
    string getName();
    string getTelephone();
    T& getAccount();

    void setName(string);
    void setAddress(string);
    void setTelephone(string);
    void setAccount(T&);

};


#endif //UNTITLED10_CLIENT_H
