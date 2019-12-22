#ifndef CLIENT_H
#define CLIENT_H

#include "updates.h"

#define FOREVER while(1)
#define TRUE 1
#define FALSE 0


/*  functions that handle the client tree data*/
void addClientToBranch_t(Branch* branch);
void createBranchClientTree( Client_tree* clientHead );
Client_tree * addNewClientToBranch(Client_tree * clientHead , Client client ) ;
void updateNewClientToBranch( Branch *branch  , Client tempClient );
Client* createNewClient();

////////////////////
Client* searchClientById_List(Client_tree* clientHead ,  int tempId , int isInput);
Node* findClientInBranch(Node* list , Client_tree* clientHead , int acountBalance);
/////////////////////////


int isClientEmpty( Client_tree* clientHead );


/*function's manage all client changes*/
void updateClientParameters(Client** client);/*general*/
void depositeMoneyToClientAccount(Client* client);
void depositeMoneyToSave(Client* client);
void loanToClient(Client* client , Branch* branch);
void repayClientLoans(Client* client , Branch* branch);
int chekLoanRequest(double authorizedException , double deposit , double loanBalance);
void printClientDetails(Client* client);


#endif
