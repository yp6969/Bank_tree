#include "common.h"





/*******************************************************************/
/*                            client                               */






/*adding client to specsiphic branch*/
void updateNewClientToBranch(Client* client , Branch* branch ){
    updateClientParameters(&client);
    updateNumberOfBranchClients( &(branch -> numberOfBranchClients) , ADD , NON );
    updateNumberOfBankClients( &(bank.numberOfBankClients) , ADD , NON );
    updateSumOfAllBankClients( &(bank.sumOfAllBankClients) , (client -> acountBalance) , NON);
    updateSumOfAllBranchClients( &(branch -> sumOfAllBranchClients) , (client -> acountBalance) , NON);
    printf("\nClient number %d is created!!!!!!\n\n",client->accountNumber);
    return;
}


/*updates the bank and the branch for the changes*/
void updateDeleteClient(Client* client){
    Branch* branch = searchBranchById_List( client->branchId , NON );
    updateNumberOfBranchClients( &(branch -> numberOfBranchClients) , DELETE , NON);
    updateNumberOfBankClients( &(bank.numberOfBankClients) , DELETE , NON);
    updateSumOfAllBankClients( &(bank.sumOfAllBankClients) , -(client -> acountBalance), NON);
    updateSumOfAllBranchClients( &(branch -> sumOfAllBranchClients) , -(client -> acountBalance) , NON);
}

/*gives loan to client*/
void loanToClient(Client* client){
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
void repayClientLoans(Client* client){
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

/*check if the client list is full*/
int isClientFull(Client* client){
    Branch* branch = searchBranchById_List( client->clientId , NON );
    if(branch->numberOfBranchClients >= MAX_CLIENT_OF_BRANCH ) return TRUE;
    return FALSE;
}

/*finds the maximum balance of all clients in the bank*/
int maxBalance(){
    int max = 0;
    Branch_list* tempBranchHead = branchHead;
    Client_list* tempClientHead;
    while(tempBranchHead){
        tempClientHead = tempBranchHead->branch.clientHead;
        while(tempClientHead){
            if(tempClientHead->client.acountBalance > max ){
                max = tempClientHead->client.acountBalance;
            }
            tempClientHead = tempClientHead->next;
        }
        tempBranchHead = tempBranchHead->next;
    }
    return max;
}

/*return array of all the richest clients in the bank*/
Client** clientNumberOfBank(int max){
    int i = 0 , j ;
    Client* highestClient[MAX_CLIENT_OF_BANK] , **temp ;
    Branch_list* tempBranchHead = branchHead;
    Client_list* tempClientHead;
    while(tempBranchHead){
        tempClientHead = tempBranchHead->branch.clientHead;
        while(tempClientHead){
            if(tempClientHead->client.acountBalance == max ){
                highestClient[i] = &tempClientHead->client;
            }
            tempClientHead = tempClientHead->next;
        }
        tempBranchHead = tempBranchHead->next;
    }
    temp = ALLOC(Client* , i );/*NEED TO BE FREEE*/
    for(j=0 ; j < i ; j++){
        temp[j] = highestClient[j];
    }
    return temp;
}

/*return the number of all the richest clients in the bank*/
int clientNumberOfBank_REC(Branch_list* tempHead , int max){
    int a , b;
    if(!tempHead) return 0;
    a = clientNumberOfBank_REC( tempHead->next , max );
    b = clientNumberOfBranch_REC( tempHead->branch.clientHead , max );
    return a + b ;
}

/*return the number of all the rechest clients in the branch*/
int clientNumberOfBranch_REC (Client_list* tempHead , int max){
    int a ; 
    if(!tempHead) return 0; 
    a = clientNumberOfBranch_REC( tempHead->next , max );
    if(tempHead->client.acountBalance == max )
        return a+1;
    return 0;
}


/* return all the clients with bigger loan balance then the current balance */
Client** clientNumberWithBiggerLoansThenBalance(Client_list* head){
    int i = 0 , j ;
    Client* temp[MAX_CLIENT_OF_BRANCH] , **client;
    while(head){
        if(head->client.acountBalance < head->client.loanBalance ){
            temp[i] = &head->client;
            i++; 
        }
        head = head->next;
    }
    client = ALLOC(Client* , i );/*NEED TO BE FREEE*/
    for(j=0 ; j < i ; j++){
        client[j] = temp[j];
    }
    return client;
}


void clientNumberWithBiggerLoansThanBalance_REC (Client_list* clientHead , int* pcount) {
    int accountBalance;
    int loanBalance;
    if(!clientHead){
        printf("there is no clients yet Soryyyyy\n\n");
        return;
    }
    accountBalance = clientHead -> client.acountBalance;
    loanBalance = clientHead -> client.loanBalance;
    if(clientHead -> next == NULL) {
        if(accountBalance < loanBalance){
            *pcount += 1;
            return;
        }
    } 
    else clientNumberWithBiggerLoansThanBalance_REC(clientHead -> next , pcount);

    if(accountBalance < loanBalance){
      *pcount += 1;
    }
    return;
}


#ifdef BANK_AMALIM
Client** clientNumberWithGivenBalance(Client_list* head ){
    int balance , i = 0 , j ;
    Client* temp[MAX_CLIENT_OF_BRANCH] , **client;
    printf("Please enter wanted balance");
    scanf("%d",&balance);
    getchar();
    while(head){
        if(head->client.acountBalance > balance ){
            temp[i] = &head->client;
            i++;  
        }
        head = head->next;
    }
    client = ALLOC(Client* , i );/*NEED TO BE FREEE*/
    for(j=0 ; j < i ; j++){
        client[j] = temp[j];
    }
    return client;
}

void printClientAcountNumberAndBalance(Client_list* clientHead){
    if(!clientHead) return;
    printClientAcountNumberAndBalance(clientHead->next);
    printf("\nClient account: %d \t Balance: %g \n", clientHead->client.accountNumber , clientHead->client.acountBalance );
    return;
}
#endif
