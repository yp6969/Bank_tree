#ifndef CLIENT_H
#define CLIENT_H

#include "updates.h"

#define FOREVER while(1)

#define TRUE 1
#define FALSE 0


/*  functions that handle the client tree data*/

void createBranchClientTree( Client_tree* clientHead );
void addNewClientToBranch( Client_tree** clientHead , Branch* branch );


Client* searchClientById_List(Client_tree* clientHead ,  int tempId , int isInput);
int isClientEmpty( Client_tree* clientHead );


/*function's manage all client changes*/
void updateClientParameters(Client** client);/*general*/
void depositeMoneyToClientAccount(Client* client);
void depositeMoneyToSave(Client* client);
int chekLoanRequest(double authorizedException , double deposit , double loanBalance);
void zeroClient(Client* client);
void printClientDetails(Client* client);

#endif
