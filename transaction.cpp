#include "transaction.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/sha.h>

#include <cstdlib> // f o r rand ( )
#include <iostream> // f o r t ime ( )

// adapted from: https://stackoverflow.com/questions/2262386/generate-sha256-with-openssl-and-c/10632725
// string SHA256(const string str)
// {
//     unsigned char hash[SHA256_DIGEST_LENGTH];
//     SHA256_CTX sha256;
//     SHA256_Init(&sha256);
//     SHA256_Update(&sha256, str.c_str(), str.size());
//     SHA256_Final(hash, &sha256);
//     stringstream ss;
//     for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
//     {
//         ss << hex << setw(2) << setfill('0') << (int)hash[i];
//     }
//     return ss.str();
// }

char randChar() {
    return char(rand() % 26 + 'a');
}

Transaction::Transaction() {
    
}

Transaction::Transaction(int amount, string sender, string reciever) {
    this->amount = amount;
    this->sender = sender;
    this->reciever = reciever;
}

void Transaction::add(int amount, string sender, string reciever){
    if(this->prev == NULL){
        this->hash = "NULL";
        this->nonce = randChar();
    } else {
        // string shaHash = "";
        // string prevNonce = "";
        // srand(time(NULL));
        // do{
        //     prevNonce = randChar();
        //     shaHash = SHA256(to_string(this->prev->amount) + this->prev->sender + this->prev->reciever + this->prev->hash + prevNonce);
        // } while (shaHash[shaHash.length() - 1] != '0');
        // this->hash = shaHash;
        // this->prev->nonce = prevNonce;
        // this->nonce = randChar();
    }
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
    cout << "Nonce: " << this->nonce <<endl;
    cout << "Hash: " << this->hash <<endl;
}

