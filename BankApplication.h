//
// Created by Alshoki on 11/5/2022.
//

#ifndef UNTITLED11_BANKAPPLICATION_H
#define UNTITLED11_BANKAPPLICATION_H

#include "client.cpp"

class BankApplication {
private:
    map<string , client<bankAccount>> basic_clients;
    map<string , client<savingAccount>> saving_clients;
    map<string , bankAccount> basic_accounts;
    map<string , savingAccount> saving_accounts;
    static int countID ;
    void loadData();
    void saveData();
    string takeID();
// map id --> client --> account

public:
    BankApplication(){
        loadData();
    }
    void addClient();
    void displayClients();
    void displayMenu();
    void withDraw_choice();
    void deposit_choice();
    void displayBalance();
    void transfer();
    ~BankApplication(){
        saveData();
    }
};

#endif //UNTITLED11_BANKAPPLICATION_H
