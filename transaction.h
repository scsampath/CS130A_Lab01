#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction
{
public :
    Transaction();
    
    Transaction(int amount, string sender, string reciever);
    
    void add(int amount, string sender, string reciever);

    void setPrev(Transaction *prev);
    void setNonce();
    void setHash(string hash);
    
    Transaction* getPrev();
    int getAmount();
    string getSender();
    string getReciever();
    string getNonce();
    string getHash();

    int getBalance(string person);
    
    void print();

private :
    Transaction *prev; //points previous transaction
    int amount ; //amount of money that has been transferred
    string sender; //sender of money
    string reciever; //reciever of money
    string nonce; //random string that will be use to simulate PoW
    string hash; //hash of content of previous transaction
};


#endif