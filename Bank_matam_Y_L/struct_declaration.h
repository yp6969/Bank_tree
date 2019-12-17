#ifndef SRTUCT_DECLARATION_H
#define SRTUCT_DECLARATION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


/*declatation of all the struct*/

/************************************************/
/*     ********    client data      *********   */

typedef struct {
    char *firstNameOfClient;
    char *lastNameOfClient;
    char *nameOfBank;
    int clientId;
    int branchId;
    int accountNumber;
    double authorizedException;
    double acountBalance;
    double loanBalance;
    double saveBlance;
}Client;

typedef struct Client_tree_t{
    Client client;
    struct Client_tree_t* left;
    struct Client_tree_t* right;
}Client_tree;



/*************************************************/
/*    ******       branch data        *******   */

typedef struct Branch_t{
    char* nameOfBank; 
    char* branchName;
    int branchId;
    int numberOfBranchClients;
    double sumOfAllBranchClients;
    double branchProfitOfLastYear;
    int numberOfBranchLoans;
    int openHour;
    int closeHour;
    Client_tree* clientHead;
} Branch;


typedef struct Branch_tree_t{
    Branch branch;
    struct Branch_tree_t* left;
    struct Branch_tree_t* right;
}Branch_tree;

Branch_tree* branchHead;



/*******************************************/
/*   ******     Bank data     ********    */

typedef struct Bank_t{
    char* nameOfBank;
    int numberOfBranch;
    int numberOfBankClients;
    double sumOfAllBankClients;
    double profitOfLastYear;
    int numberOfActiveLoans;
} Bank;

 Bank bank;



#endif
