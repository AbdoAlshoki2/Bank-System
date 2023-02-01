//
// Created by Alshoki on 11/3/2022.
//

#include "client.h"
#include "bankAccount.cpp"

template<class T>bool client<T>::checkTelephone(string& checkMobile)
{
    regex mobileFormat("(010|011|012|015)[0-9]+");
    return regex_match(checkMobile,mobileFormat);
}
template<class T> client<T>::client(){
    account = nullptr;
}

template<class T> client<T>::client(string id,T& Account, string Name, string Address, string Telephone):
ID(id) , account(&Account) , name(Name) , address(Address)
{
    while(!checkTelephone(Telephone) || Telephone.size() != 11){
        cout<<"Invalid Phone Number\n";
        cin>>Telephone;
    }
    telephone = Telephone;
}

template<class T> string client<T>::getID() {
    return ID;
}
template<class T> string client<T>::getName() {
    return name;
}
template<class T> string client<T>::getAddress(){
    return address;
}
template<class T> T& client<T>::getAccount() {
    return *account;
}
template<class T> string client<T>::getTelephone() {
    return  telephone;
}


template<class T> void client<T>::setAddress(string Address) {
    address = Address;
}
template<class T> void client<T>::setName(string Name) {
    name = Name;
}
template<class T> void client<T>::setTelephone(string Telephone) {
    while(!checkTelephone(Telephone)){
        cout<<"Invalid Phone Number\n";
        cin>>Telephone;
    }
    telephone = Telephone;
}
template<class T> void client<T>::setAccount(T& Account) {
    account = &Account ;
}
