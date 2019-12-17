#include "branch.h"


/* ***************   Branch Tree  *******************   */

/*creating the branch list*/
void createBranchList(){
    branchHead = NULL;
    return;
}


/*searching branch by id in the branch list if not found return null*/
Branch* searchBranchById_List(int tempId , int isInput){ 
    int branchId;
    Branch_tree* temp = branchHead;
    if(isInput) branchId = getBranchId();
    else branchId = tempId;
    while( temp ){
        if(((temp->branch).branchId) == branchId) return &temp->branch;
        else temp = temp->next;
    }
    printf("\nBranch not found! maybe try again\n");
    return NULL;
}

/* quest if the list is empty*/
int isBranchEmpty(){
    if(!branchHead) return TRUE;
    return FALSE;
}
























/******************************************************/
/*****                   branch                 ******/
 
/*adding new branch to the branch list*/
void addNewBranchToList(){
    Branch_list *newBranch = ALLOC(Branch_list,1);
    updateNewBranch(&newBranch->branch);
    createBranchClientList(newBranch->branch.clientHead);
    newBranch->next = branchHead;
    branchHead = newBranch;
    return;
}


/* Given a reference (pointer to pointer) to the head of a list 
   and a branchId, deletes the first occurrence of branchId in linked list */
void deleteBranchFrom_List(){
    int branchId = getBranchId();
    Branch_list *temp = branchHead, *prev; 
    /* If head node itself holds the branchId to be deleted */
    if (temp != NULL && temp->branch.branchId == branchId) 
    {   branchHead = temp->next;  /* Changed head */
        updateDeleteBranch(&temp->branch);
        FREE(temp->branch.branchName); /*FREE branch name*/
        FREE(temp);    /* FREE old head*/
        temp = NULL;         
        printf("\n\nBranch is deleted!!\n\n");
        return; 
    } 
    /* Search for the branchId to be deleted, keep track of the 
     previous node as we need to change 'prev->next' */
    while (temp != NULL && temp->branch.branchId != branchId) { 
        prev = temp; 
        temp = temp->next; 
    } 
    /* If branchId was not present in linked list */
    if (temp == NULL){
        printf("\n\tbranch not found\n\n");
        return;
    }
    /*Unlink the node from linked list*/ 
    prev->next = temp->next;
    updateDeleteBranch(&temp->branch);
    printf("\n\nBranch is deleted!!\n\n");
    FREE(temp);  /* FREE memory */
    return;
}

void deleteAllBranchs(){
    Branch_list* temp = branchHead , *prev;
    while(temp){
        deleteAllBranchClients(&temp->branch.clientHead);
        prev = temp;
        temp = temp->next;
        FREE(prev);
    }
}

void deleteAllBranchClients(Client_list** clientHead){
    if(!*clientHead) return;
    deleteAllBranchClients( &(*clientHead)->next );
    FREE( (*clientHead)->client.firstNameOfClient );
    FREE( (*clientHead)->client.lastNameOfClient );
    FREE(*clientHead);
    *clientHead = NULL;
    return;
}


/*adding new branch to the global branch list*/
void updateNewBranch(Branch *branch){
    updateBranchParameters( branch );
    updateNumberOfBranch( &(bank.numberOfBranch) , ADD , NON );
    printf("\nBranch number %d is created\n\n", branch->branchId);
    return;
}

/*update the bank of the deletion*/
void updateDeleteBranch(Branch* branch){
    updateNumberOfBranch( &(bank.numberOfBranch) , DELETE , NON);
    updateNumberOfBankClients( &(bank.numberOfBankClients) , -(branch -> numberOfBranchClients), NON);
    updateSumOfAllBankClients( &(bank.sumOfAllBankClients) , -(branch -> sumOfAllBranchClients), NON);
    if(branch->clientHead) deleteAllBranchClients(&(branch->clientHead));
    return;
}

/* quest if the branch list is full*/
int isBranchFull(){
    if(bank.numberOfBranch >= MAX_BRANCHS) return TRUE;
    return FALSE;
}



















/*************************************************/

/*  *********     branch data     ***************/

/*creating the Branch client list from the global arrays*/
void createBranchClientList(Client_tree* clientHead){
    clientHead = NULL;
}

/*updates all the branches parameters
flag means NON for 1 delete for -1.*/
void updateBranchParameters(Branch* branch){
    updateNameOfBank(&branch->nameOfBank , NON );
    updateNameOfBranch(&branch->branchName);
    updateBranchId( &branch->branchId );
    updateNumberOfBranchClients( &(branch->numberOfBranchClients) , NON , NON );
    updateSumOfAllBranchClients( &(branch->sumOfAllBranchClients) , NON , NON);
    updateBranchProfitOfLastYear( &(branch->branchProfitOfLastYear) , NON , NON );
    updateNumberOfBranchLoans( &(branch->numberOfBranchLoans) , NON , NON);
    updateOpenHour( &(branch->openHour) );
    updateCloseHour( &(branch->closeHour) );
    return;
}

/*calculate the branch profit of the last year*/
double calculateBranchProfitOfLastYear(Branch* branch){
    return NON;
}


/*print all the branch parameters*/
void printBranchDetails(Branch* branch){
    printf("\nBeanch ID: %d\n", branch -> branchId);
    printf("Number of branch clients: %d \n" ,branch -> numberOfBranchClients);
    printf("Sum of all branch clients: %g \n" ,branch -> sumOfAllBranchClients);
    printf("profit of last year : %g\n " , branch -> branchProfitOfLastYear);
    printf("Number of branch loans: %d \n" ,branch -> numberOfBranchLoans);
    printf("Open hour: %d \n" , branch -> openHour);
    printf("Close hour: %d \n" , branch -> closeHour);
    return;
}
