//
// Created by Alshoki on 11/3/2022.
//

#include "bankAccount.h"
#include "client.h"

bankAccount::bankAccount() : balance(0.0){

}

bankAccount::bankAccount(double value) : balance(value) {

}

void bankAccount::setClient(client<bankAccount> & Person) {
    person = & Person;
}

void bankAccount::setBalance(double value) {
    balance = value;
}

client<bankAccount>& bankAccount::getClient() {
    return *person ;
}

double bankAccount::getBalance() {
    return balance;
}

void bankAccount::withdraw() {
    double drawMoney;
    cout<<"Account ID: " << person->getID()<<endl;
    cout<<"Account Type: Basic\n";
    cout<<"Balance: " << fixed << balance<<" L.E"<<endl;
    cout<<"Please enter the amount to withdraw\n";
    cin>>drawMoney;
    while(balance - drawMoney <0){
        cout<<"Sorry, this is more than what  you can withdraw\n";
        cout<<"Please enter the amount to withdraw\n";
        cin>>drawMoney;
    }
    cout<<"Success , Thank you!\n";
    balance -= drawMoney;
    cout<<"Account ID: " << person->getID()<<endl;
    cout<<"New Balance: " << fixed << balance<<" L.E"<<endl;
}

void bankAccount::deposit() {
    double depositMoney;
    cout<<"Account ID: " << person->getID()<<endl;
    cout<<"Account Type: Basic\n";
    cout<<"Current Balance: "<< fixed  << balance<<" L.E"<<endl;
    cout<<"Please enter the amount to deposit\n";
    cin>>depositMoney;
    cout<<"Success, Thank you!\n";
    balance += depositMoney;
    cout<<"Account ID: " << person->getID()<<endl;
    cout<<"New Balance: " << fixed  << balance<<" L.E"<<endl;
}


//*******************************************************************
// min >=200000 , in > min

savingAccount ::savingAccount():minBalance(1000.0){}

savingAccount ::savingAccount(double initialBalance, double minimumBalance = 1000) {
    minBalance = minimumBalance;
    while (initialBalance < minBalance){
        cout << "Your initial balance is less than minimum balance of saving account, Please renter the initial balance: \n";
        cin >> initialBalance;
    }
    balance = initialBalance;
}

void savingAccount::setMinBalance(double miniBalance) {
    minBalance = miniBalance;
}
double savingAccount ::getMinBalance() {
    return minBalance;
}

void savingAccount::withdraw() {
    double drawMoney;
    cout<<"Account ID: " << savingPerson->getID()<<endl;
    cout<<"Account Type: Saving\n";
    cout<<"Balance: " << fixed << balance<<" L.E"<<endl;
    cout<<"Please enter the amount to withdraw\n";
    cin>>drawMoney;
    while(balance - drawMoney < minBalance){
        cout<<"Sorry, this is more than what  you can withdraw\n";
        cout<<"Please renter the amount to withdraw\n";
        cin>>drawMoney;
    }
    cout<<"Success, Thank you!\n";
    balance -= drawMoney;
    cout<<"Account ID: " << savingPerson->getID()<<endl;
    cout<<"New Balance: "<< fixed  << balance<<" L.E"<<endl;
}

void savingAccount::deposit() {
    double depositMoney;
    cout<<"Account ID: " << savingPerson->getID()<<endl;
    cout<<"Account Type: Saving\n";
    cout<<"Current Balance: " << fixed << balance<<" L.E"<<endl;
    cout<<"Please enter the amount to deposit (greater than or equal 100 L.E)\n";
    cin>>depositMoney;
    while (depositMoney < 100){
        cout<<"Sorry, this is less than what you can deposit \n";
        cout << "Please renter the amount to deposit\n";
        cin>>depositMoney;
    }
    cout<<"Success, Thank you!\n";
    balance += depositMoney;
    cout<<"Account ID: " << savingPerson->getID()<<endl;
    cout<<"New Balance: " << fixed << balance<<" L.E"<<endl;
}

void savingAccount::setClient(client<savingAccount> & Person){
    savingPerson = & Person;
}