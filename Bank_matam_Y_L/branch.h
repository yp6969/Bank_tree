#ifndef BRANCH_H
#define BRANCH_H

#include "client.h"

#define BANK_AMALIM 

/*  functions that handle the tree data*/
void createBranchList();
Branch* searchBranchById_List(int tempId , int isInput);
int isBranchEmpty();





void addNewBranchToList();
void deleteBranchFrom_List();
void deleteAllBranchs();
void deleteAllBranchClients(Client_tree** clientHead);
void updateNewBranch(Branch *branch);
void updateDeleteBranch(Branch* branch);
int isBranchFull();





/* function's is manage all branch changes*/
void createBranchClientList(Client_tree* clientHead);
void updateBranchParameters(Branch* branch);/*general*/
double calculateBranchProfitOfLastYear(Branch* branch);
void printBranchDetails(Branch* branch);

#endif
