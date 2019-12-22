#ifndef BRANCH_H
#define BRANCH_H

#include "client.h"
#define BANK_AMALIM 

/*  functions that handle the tree data*/

void addNewBranch_t();
void createBranchTree();
Branch* createNewBranch();
Branch_tree * addNewBranchToTree(Branch_tree* branchHead , Branch branch );
int isBranchEmpty(Client_tree* clientHead);
int isBranchFull(int numberOfBranchClients);

/******************************************************************/

Branch* searchBranchById(Branch_tree* branchHead , int branchId );


/****************************************************************/


/* function's is manage all branch changes*/
void updateBranchParameters(Branch* branch);/*general*/
double calculateBranchProfitOfLastYear(Branch* branch);
void printBranchDetails(Branch* branch);
void printClientAcountNumberAndBalance(Client_tree* clientHead);
int clientNumberWithGivenBalance(Client_tree *clientHead , double Balance);
int clientNumberWithBiggerLoansThenBalance( Client_tree *clientHead );

#endif
