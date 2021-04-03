#include "transaction.h"
#include <iostream>

Transaction::Transaction() {
    
}

Transaction::Transaction(int amount, string sender, string reciever) {
    this->amount = amount;
    this->sender = sender;
    this->reciever = reciever;
}

void Transaction::add(int amount, string sender, string reciever){
    
}

void Transaction::setPrev(Transaction *prev){
    this->prev = prev;
}

void Transaction::setHash(string hash){
    this->hash = hash;
}

Transaction* Transaction::getPrev(){
    return this->prev;
}

int Transaction::getAmount() {
    return this->amount;
}

string Transaction::getSender() {
    return this->sender;
}

string Transaction::getReciever() {
    return this->reciever;

}

string Transaction::getNonce() {
    return this->nonce;

}

string Transaction::getHash() {
    return this->hash;

}

int Transaction::getBalance(string person){
    Transaction *current = this;
    int balance = 50;
    while(current != NULL) {
        if(current->sender == person){
            balance -= current->amount;
        }
        else if(current->reciever == person){
            balance += current->amount;
        }
        current = current->prev;
    }
    return balance;

}
void Transaction::print(){
    if (this == NULL)
    {
        return;
    }
    this->prev->print();
    cout << "Amount: " << this->amount <<endl;
    cout << "Sender: " << this->sender <<endl;
    cout << "Reciever: " << this->reciever <<endl;
}

