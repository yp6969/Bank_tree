/**************************************************
all the client function!!
***************************************************/
#include "client.h"


/*************************************************/

/*  *********     client tree     ***************/


/*creating the branch list*/
void createBranchClientTree(Client_tree* clientHead){
    clientHead = NULL;
    return;
}
//////////////////////////////////////////////////////////////////////////
/*adding new branch to the branch tree
if the head is null so get the information from the standard input*/
void addNewClientToBranch(Client_tree** clientHead , Branch* branch){
    Client_tree* newClient = ALLOC(Client_tree,1);
    updateNewClientToBranch( &newClient->client , branch );
    newClient->next = *clientHead;
    *clientHead = newClient;
    return;
}


// we look for the proper leaf to add it to and then add it.
Client_tree * add_(Client_tree * clientHead , int ) {
    if (!t) {
        Tree *p = ALLOC(Tree,1);    
        p->value = i;
        p->left = p->right = NULL;
        return p;
    }
    if (i > t->value) {
        t->right = tree_add(t->right, i); 
    } else if (i < t->value) {
        t->left = tree_add(t->left, i);
    } else {
        // value is already there, we don't add it.
    }
    return t;
}
////////////////////////////////////////////////////////////////////


Client* searchClientById_List(Client_tree* clientHead ,  int tempId , int isInput){
    int clientId;
    Client_tree* temp = clientHead;
    if(isInput) clientId = getClientId();
    else clientId = tempId;
    while( temp ){
        if(((temp->client).clientId) == clientId) return &temp->client;
        else temp = temp->next;
    }
    printf("\nClient not found! maybe try again\n");
    return NULL;
}


/* check is the client list is empty*/
int isClientEmpty( Client_tree* clientHead ){
    if(!clientHead) return TRUE;
    return FALSE;
}

/*************************************************/

/*  *********     client data     ***************/

/*updates all the client parameters.*/
void updateClientParameters(Client** client ){
    updateFirstNameOfClient( &(*client) -> firstNameOfClient);
    updateLastNameOfClient( &(*client) -> lastNameOfClient);
    updateNameOfBank( &(*client) -> nameOfBank , NON );
    updateClientId( &(*client) -> clientId);
    updateBranchId( &(*client) -> branchId);
    updateAccountNumber( &((*client) -> accountNumber));
    updateAuthorizedException(&((*client) -> authorizedException ));
    updateAccountBalance( &((*client) -> acountBalance) , NON , NON);
    updateLoanBalance( &((*client) -> loanBalance) , NON , NON);
    updateSaveBalance( &((*client) -> saveBlance) , NON , NON);
    return;
}

/*deposit money to client account*/
void depositeMoneyToClientAccount(Client* client){
    double deposit;
    printf("\nHow much do you want to deposite ? :\n" );
    deposit = getDpositeMoney();
    updateAccountBalance(&client->acountBalance , deposit , NON );
    return;
}

/*deposit money to client save*/
void depositeMoneyToSave(Client* client){
    double deposit;
    printf("\nHow much do you want to deposite to your save ? :\n" );
    deposit = getSaveBlance();
    updateSaveBalance(&client->saveBlance , deposit , NON );
    updateAccountBalance(&client->acountBalance , -deposit , NON);
    return;
}

/*  checking the loane request for client */
int chekLoanRequest(double authorizedException , double deposite , double loanBalance){
    if( (loanBalance + deposite) > authorizedException ) return FAILD;
    return SUCCESS;
}

/*ziro all the parameters of the client*/
void zeroClient(Client* client){
    Client temp = {0};
    *client = temp ;
    return;
}

/*Print the parameters of the client*/
void printClientDetails(Client* client){
    printf("\nname Of Client: %s %s\n", client -> firstNameOfClient , client -> lastNameOfClient );
    printf("client Id: %d \n" ,(int)client -> clientId );
    printf("branch Id: %d \n" , client -> branchId);
    printf("account Number: %d\n " , client -> accountNumber);
    printf("authorized Exception: %g \n" , client -> authorizedException);
    printf("acount Balance: %g \n" , client -> acountBalance);
    printf("loan Balance: %g \n" , client -> loanBalance);
    printf("save Blance: %g \n" , client -> saveBlance);
    return;
}
