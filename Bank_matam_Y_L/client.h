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
Client* createNewClient(int btanchId);

/* searching clients */
void findClient(D_Llinked_List* list );
void findClientInBankByAcountBalance(D_Llinked_List* list ,Branch_tree* branchHead ,  int acountBalance );
void findClientInBranchByAcountBalance(D_Llinked_List* list , Client_tree* clientHead , int acountBalance);
Client* searchClientByIdInBank(Branch_tree* branchHead ,  int clientId );
Client* searchClientById( Client_tree* clientHead , int clientId );
void addNode(D_Llinked_List* list , Client* newClient );


/*function's manage all client changes*/
void updateClientParameters(Client** client , int branchId);/*general*/
void depositeMoneyToClientAccount(Client* client);
void depositeMoneyToSave(Client* client);
void loanToClient(Client* client , Branch* branch);
void repayClientLoans(Client* client , Branch* branch);
int chekLoanRequest(double authorizedException , double deposit , double loanBalance);
void printClientDetails(Client* client);
void printClientId(Client_tree* clientHead );


#endif
