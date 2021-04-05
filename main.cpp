//Sachen Sampath 4/1/2021
#include <iostream>
#include <string>
#include <limits>
#include "transaction.h"
using namespace std;

int main() {
    string message = "Welcome to the transaction-chain application.... \n1) Add a transaction to the chain \n2) Find the balance of a person \n3) Print the chain \n4) Exit. \nWhich operation do you want to make? (1,2,3,4)";
    int input;
    Transaction *head = NULL;
    
    do {
        cout << message << endl;
        cin >> input;
        if(cin.fail() || input > 4) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Wrong operation!" <<endl;
        }
        else if(input == 1) {
            int amount;
            string sender;
            string reciever;
            
            bool valid = false;
            while(valid == false) {
                cout << "Integer amount of money: " <<endl, cin >> amount;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    cout << "Wrong input, try again!" <<endl;
                } else {
                    valid = true;
                }
            }
            cout << "Sender name: " <<endl, cin >> sender;
            cout << "Reciever name: " <<endl, cin >> reciever;

            Transaction *add = new Transaction(amount, sender, reciever);
            add->setPrev(head);
            head = add;
            head->add(amount, sender, reciever);
        }
        else if(input == 2) {
            string personName;
            cout << "Person Name: " <<endl, cin >> personName;
            cout << head->getBalance(personName) <<endl;
        }
        else if(input == 3) {
            head->print();
        }
    }
    while (input != 4);
}
