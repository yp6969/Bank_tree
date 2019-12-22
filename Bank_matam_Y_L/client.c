#include "client.h"


/*************************************************/
/*  *********    adding client tree     ***************/
void addClientToBranch_t(Branch* branch){
    Client* tempClient  = createNewClient();
    branch->clientHead = addNewClientToBranch(branch->clientHead , *tempClient );
    updateNewClientToBranch( branch  , *tempClient );
    FREE(tempClient);
}

/*creating the branch list*/
void createBranchClientTree(Client_tree* clientHead){
    clientHead = NULL;
    return;
}

Client* createNewClient(){
    Client* newClient = ALLOC (Client , 1 );
    updateClientParameters( &newClient );
    return newClient;
} 

/*adding new branch to the branch tree*/
Client_tree * addNewClientToBranch(Client_tree * clientHead , Client client  ) {
    if (!clientHead) {
        Client_tree *newClientNode = ALLOC( Client_tree , 1 );    
        newClientNode->client = client;
        newClientNode->left = newClientNode->right = NULL;
        return newClientNode;
    }
    /*if the branch id is alredy exsist do not add nothing and return the current tree */
    if (client.clientId == clientHead->client.clientId){
        printf("\n\tThis client is already exsist try again/t/n");
        return clientHead;
    }
    else if (client.clientId > clientHead->client.clientId) {
        clientHead->right = addNewClientToBranch(clientHead->right, client); 
    } else if ( client.clientId < clientHead->client.clientId ) {
        clientHead->left = addNewClientToBranch(clientHead->left, client);
    } 
    return clientHead;
}

//////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
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


Node* findClientInBranch(Node* list , Client_tree* clientHead , int acountBalance){
    if(!clientHead) return NULL;
    else if (clientHead->client.acountBalance == acountBalance ) return addNode( list , clientHead->client );
    else if ( clientHead->client.acountBalance > acountBalance ){
        list = findClientInBranch( list , clientHead->left , acountBalance );
    }
    else if( clientHead->client.acountBalance < acountBalance ){
        list = findClientInBranch( list , clientHead->right , acountBalance );
    }
    return list;
}

//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


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

/*update the branch with the new client in the bank*/
void updateNewClientToBranch( Branch *branch  , Client tempClient ){
    updateNumberOfBranchClients( &(branch -> numberOfBranchClients) , ADD , NON );
    updateSumOfAllBranchClients( &(branch -> sumOfAllBranchClients) , (tempClient.acountBalance) , NON);
    updateNumberOfBankClients( &(bank.numberOfBankClients) , ADD , NON );
    updateSumOfAllBankClients( &(bank.sumOfAllBankClients) , (tempClient.acountBalance) , NON);
    printf("\nClient number %d is created!!!!!!\n\n",tempClient.accountNumber);
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

/*gives loan to client*/
void loanToClient(Client* client , Branch* branch){
    int flag = 0;
    double deposit;
    Branch* branch = searchBranchById_List( client->branchId , NON );
    do{
        if(flag) printf("\n\nyou pass the authorized Exception try again!\n\n");
        flag = 1;
        printf("\nHow much do you want to loan ? :\n" );
        deposit = getLoanBalance();
    }while ( !chekLoanRequest(client -> authorizedException , deposit , client -> loanBalance) );
    updateLoanBalance(&client->loanBalance , deposit , NON );
    updateNumberOfBranchLoans(&(branch -> numberOfBranchLoans) , ADD , NON);
    updateNumberOfBankActiveLoan(&(bank.numberOfActiveLoans) , ADD , NON);
    return;
}

/*repay client loans*/
void repayClientLoans(Client* client , Branch* branch ){
    Branch* branch = searchBranchById_List(client->branchId , NON );
    double deposit;
    printf("\nHow much do you want to repay your loan ? :\n\n" );
    deposit = getDpositeMoney();
    updateLoanBalance(&client->loanBalance , -deposit , NON );
    updateAccountBalance(&client->acountBalance , -deposit , NON);
    updateNumberOfBranchLoans(&(branch-> numberOfBranchLoans) , DELETE , NON);
    updateNumberOfBankActiveLoan(&bank.numberOfActiveLoans , DELETE , NON);
    return;
}

/*  checking the loane request for client */
int chekLoanRequest(double authorizedException , double deposite , double loanBalance){
    if( (loanBalance + deposite) > authorizedException ) return FAILD;
    return SUCCESS;
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
