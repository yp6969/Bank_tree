/*  this header contains all the function
    that use multiple decleration its necessarily
    for that to know all the typs before*/

#ifndef COMMON_H
#define COMMON_H

#include "bank.h"




void deleteClientFrom_List( Client_tree* clientHead );
void updateNewClientToBranch(Client* client , Branch* branch );
void updateDeleteClient(Client* client);
void loanToClient(Client* client);
void repayClientLoans(Client* client);
int isClientEmpty(Client_tree* clientHead);

int maxBalance();
Client** clientNumberOfBank();
int clientNumberOfBank_REC(Branch_tree* tempHead , int max);
int clientNumberOfBranch_REC (Client_tree* tempHead , int max);
Client** clientNumberWithBiggerLoansThenBalance(Client_tree* head);
void clientNumberWithBiggerLoansThanBalance_REC (Client_tree* clientHead , int* pcount);
#ifdef BANK_AMALIM
Client** clientNumberWithGivenBalance(Client_tree* head );
void printClientAcountNumberAndBalance(Client_tree* clientHead);
#endif

#endif