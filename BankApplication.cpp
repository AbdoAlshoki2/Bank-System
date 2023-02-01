
// Created by Alshoki on 11/5/2022.
//

#include "BankApplication.h"

int BankApplication :: countID = 0 ;

void BankApplication::loadData() {
    ifstream file;
    string line ;
    string data[6];
    file.open("Bank Data.txt",ios::in);
    if(file.peek() != ifstream::traits_type::eof()) {
        getline(file, line);
        countID = stoi(line);
    }
    getline(file,line);
    while(!file.eof()){
        for (int i = 0; i < 6; ++i) {
            getline(file,line);
            data[i] = line;
        }
        getline(file,line);
        if(data[4] == "basic"){
            bankAccount temp_acc(stod(data[5]));
            client<bankAccount> temp_basic(data[0],temp_acc,data[1],data[2],data[3]);
            basic_clients[data[0]] = temp_basic;
            basic_accounts[data[0]] = temp_acc;
            basic_clients[data[0]].setAccount(basic_accounts[data[0]]);
            basic_accounts[data[0]].setClient(basic_clients[data[0]]);
        }
        else{
            stringstream word ;
            word<<data[5];
            string balance , minimum_balance ;
            word >> balance ;
            word >> minimum_balance ;
            savingAccount temp_acc(atof(balance.c_str()) , atof(minimum_balance.c_str()));
            client<savingAccount> temp_basic(data[0],temp_acc,data[1],data[2],data[3]);
            saving_clients[data[0]] = temp_basic;
            saving_accounts[data[0]] = temp_acc;
            saving_clients[data[0]].setAccount(saving_accounts[data[0]]);
            saving_accounts[data[0]].setClient(saving_clients[data[0]]);
        }
    }
    file.close();

}

void BankApplication ::saveData() {
    fstream file;
    file.open("Bank Data.txt", ios::out);

    file << countID;
    file << "\n\n";
    for (int i = 1; i <= countID; ++i) {
        string header = "FCAI-" + to_string(i);
        if (basic_clients.count(header)) {
            file << basic_clients[header].getID() << endl
                 << basic_clients[header].getName() << endl
                 << basic_clients[header].getAddress() << endl
                 << basic_clients[header].getTelephone() << endl
                 << "basic" << endl
                 << fixed<<basic_accounts[header].getBalance() << endl;

        } else {
            file << saving_clients[header].getID() << endl
                 << saving_clients[header].getName() << endl
                 << saving_clients[header].getAddress() << endl
                 << saving_clients[header].getTelephone() << endl
                 << "saving" << endl
                 << fixed<< saving_accounts[header].getBalance() << " " << fixed<< saving_accounts[header].getMinBalance() << endl;
        }
        if(i != countID)file<<"\n";
    }
}
//functions:

void BankApplication ::  displayMenu(){
    string choice ;

    cout << "Welcome to FCAI Banking Application \n"
            "1. Create a New Account \n"
            "2. List Clients and Accounts \n"
            "3. Withdraw Money \n"
            "4. Deposit Money\n"
            "5. Display account balance \n"
            "6. Transferring \n";

    cin >> choice ;

    if(choice == "1"){
        addClient();
    }
    else if (choice == "2") {
        displayClients();
    }
    else if (choice == "3") {
        withDraw_choice();
    }
    else if (choice == "4") {
        deposit_choice();
    }
    else if (choice == "5"){
        displayBalance();
    }
    else if(choice == "6"){
        transfer();
    }
    else {
        cout << "Wrong choice\n\n";
        displayMenu();
    }
}

void BankApplication ::  addClient(){
    string name , address , phone , type ;
    double balance ;
    cout<<"Please enter your name:" << endl;
    cin.clear();
    cin.sync();
    getline(cin,name);
    cout <<"Please enter your address:" << endl;
    getline(cin,address);
    cout <<"Please enter your phone:" << endl;
    cin >> phone;
    cout << "Please choose your account type : 1) Basic     2) saving" << endl;
    cin >> type;

    if(type == "1"){
        cout<<"Please enter your balance: \n";
        cin>>balance;
        bankAccount temp(balance);
        client<bankAccount> temp1("FCAI-"+ to_string(++countID) , temp, name, address, phone);
        basic_clients[temp1.getID()] = temp1;
        basic_accounts[temp1.getID()] = temp;
        basic_clients[temp1.getID()].setAccount(basic_accounts[temp1.getID()]);
        basic_accounts[temp1.getID()].setClient(basic_clients[temp1.getID()]);
        cout<< "A Basic account was created with ID " << temp1.getID() << " and Starting Balance "<< fixed<<balance <<"L.E.\n\n";
    }
    else if(type == "2"){
        cout<<"Please enter your balance: \n";
        cin>>balance;
        savingAccount temp(balance);
        client<savingAccount> temp1("FCAI-"+ to_string(++countID) , temp,name,address,phone);
        saving_clients[temp1.getID()] = temp1;
        saving_accounts[temp1.getID()] = temp;
        saving_clients[temp1.getID()].setAccount(saving_accounts[temp1.getID()]);
        saving_accounts[temp1.getID()].setClient(saving_clients[temp1.getID()]);
        cout<< "A Saving account was created with ID " << temp1.getID() << " and Starting Balance "<<fixed<< temp.getBalance() <<"L.E.\n\n";

    }
    else {

        cout << "wrong choice\n";
    }
}

void BankApplication :: displayClients(){
    int endCounter = basic_clients.size() + saving_clients.size() ;
    cout<<"*************************************************\n";

    for (int i = 1; i <= endCounter ; ++i) {
        string header = "FCAI-" + to_string(i);
        if (basic_clients.count(header)){
            cout << "Account ID: " << basic_clients[header].getID() << endl
                 << "Account Type: Basic" << endl
                 << "Name: "       << basic_clients[header].getName() << endl
                 << "Address: "    << basic_clients[header].getAddress() << endl
                 << "Telephone: "  << basic_clients[header].getTelephone() << endl
                 << "Balance: "    <<fixed <<basic_accounts[header].getBalance() << endl ;
            cout <<"*************************************************\n";
        }
        else{
            cout << "Account ID: " << saving_clients[header].getID() << endl
                 << "Account Type: Saving" << endl
                 << "Name: "       << saving_clients[header].getName() << endl
                 << "Address: "    << saving_clients[header].getAddress() << endl
                 << "Telephone: "  << saving_clients[header].getTelephone() << endl
                 << "Balance: "    << fixed<< saving_accounts[header].getBalance() << endl ;
            cout <<"*************************************************\n";
        }

    }

}

void BankApplication :: withDraw_choice(){
    string ID = takeID();

   if(basic_clients.count(ID)){
       basic_accounts[ID].withdraw();
    }
   else if (saving_clients.count(ID)){
       saving_accounts[ID].withdraw();
   }
   else {
       cout << "Wrong ID, Account not found.\n";
   }
}

void BankApplication :: deposit_choice(){
    string ID = takeID();

    if(basic_clients.count(ID)){
        basic_accounts[ID].deposit();
    }
    else if (saving_clients.count(ID)){
        saving_accounts[ID].deposit();
    }
    else {
        cout << "Wrong ID, Account not found.\n";
    }
}
void BankApplication::displayBalance() {
    string ID = takeID();
    if(basic_clients.count(ID)){
        cout<< "Your Basic account with ID " << ID << " has Current Balance of: "<<fixed<< basic_accounts[ID].getBalance() <<"L.E.\n\n";
    }
    else if (saving_clients.count(ID)){
        cout<< "Your Saving account with ID " << ID << " has Current Balance of: "<<fixed<< saving_accounts[ID].getBalance() <<"L.E.\n\n";
    }
    else {
        cout << "Wrong ID, Account not found.\n";
    }
}

string BankApplication::takeID() {
    string ID;
    cout << "Please enter your ID\n";
    cin >> ID;
    for_each(ID.begin(), ID.end() , [](char& i ) { i = toupper(i) ; });
    return ID;
}

void BankApplication::transfer() {
    cout << "Sender, ";
    string ID_1 = takeID();
    if(basic_clients.count(ID_1) || saving_clients.count(ID_1)){
        string ID_2;
        cout << "Please enter receiver ID\n";
        cin >> ID_2;
        for_each(ID_2.begin(), ID_2.end() , [](char& i ) { i = toupper(i) ; });
        if(basic_clients.count(ID_2) || saving_clients.count(ID_2)){
            double money;
            cout << "Enter the amount of the money to transfer: \n";
            cin >> money;
            if(basic_clients.count(ID_1) && basic_accounts[ID_1].getBalance() >= money){
                if(basic_clients.count(ID_2)){
                    basic_accounts[ID_1].setBalance(basic_accounts[ID_1].getBalance() - money);
                    basic_accounts[ID_2].setBalance(basic_accounts[ID_2].getBalance() + money);
                }
                else{
                    basic_accounts[ID_1].setBalance(basic_accounts[ID_1].getBalance() - money);
                    saving_accounts[ID_2].setBalance(saving_accounts[ID_2].getBalance() + money);
                }
                cout <<"Successfully transferred, your current balance : " << basic_accounts[ID_1].getBalance() <<"L.E.\n\n";
            }
            else if(saving_clients.count(ID_1) && saving_accounts[ID_1].getBalance() - saving_accounts[ID_1].getMinBalance()  >= money){
                if(basic_clients.count(ID_2)){
                    saving_accounts[ID_1].setBalance(saving_accounts[ID_1].getBalance() - money);
                    basic_accounts[ID_2].setBalance(basic_accounts[ID_2].getBalance() + money);
                }
                else{
                    saving_accounts[ID_1].setBalance(saving_accounts[ID_1].getBalance() - money);
                    saving_accounts[ID_2].setBalance(saving_accounts[ID_2].getBalance() + money);
                }
                cout <<"Successfully transferred, your current balance : " << saving_accounts[ID_1].getBalance() <<"L.E.\n\n";
            }
            else{
                cout << "Failed to transfer .. please check IDs and balance and try again \n";
            }
        }
        else {
            cout << "Wrong ID, Account not found.\n";
        }
    }
    else {
        cout << "Wrong ID, Account not found.\n";
    }
}
