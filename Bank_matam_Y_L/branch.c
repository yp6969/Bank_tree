#include "branch.h"


/*********************************************************/
/*****               adding branch Tree             ******/

/* hande several function to create properly */
void addNewBranch_t(){
    Branch* tmpBranch  = createNewBranch();
    branchHead = addNewBranchToTree( branchHead , *tmpBranch );
    updateNumberOfBranch( &(bank.numberOfBranch) , ADD , NON );
    printf("\nBranch number %d is created\n\n", tmpBranch->branchId);
    FREE(tmpBranch);
}

/*creating the branch list*/
void createBranchTree(){
    branchHead = NULL;
    return;
}
/* creat new branch */
Branch* createNewBranch(){
    Branch* newBranch = ALLOC (Branch*,1);
    updateBranchParameters( &newBranch );
    return newBranch;
}

/*adding new branch to the branch tree*/
Branch_tree * addNewBranchToTree(Branch_tree* branchHead ,  Branch branch  ) {
    if (!branchHead) {
        Branch_tree *newBranchNode = ALLOC( Branch_tree , 1 );    
        newBranchNode->branch = branch;
        newBranchNode->left = newBranchNode->right = NULL;
        return newBranchNode;
    }
    /*if the branch id is alredy exsist do not add nothing and return the current tree */
    if (branch.branchId == branchHead->branch.branchId){
        printf("\n\tThis branch is already exsist try again/t/n");
        return branchHead;
    }
    else if (branch.branchId > branchHead->branch.branchId) {
        branchHead->right = addNewBranchToTree(branchHead->right , branch); 
    } else if ( branch.branchId < branchHead->branch.branchId ) {
        branchHead->left = addNewBranchToTree( branchHead->left , branch);
    }
    return branchHead;
}

/* check is the client list is empty*/
int isBranchEmpty( Client_tree* clientHead ){
    if(!clientHead) return TRUE;
    return FALSE;
}
/* check is the client list is full*/
int isBranchFull(int numberOfBranchClients){
    if(numberOfBranchClients >= MAX_CLIENT_OF_BRANCH) return TRUE;
    return FALSE;
}

/****************************************************************/
/*                         search branch                        */

Branch* searchBranchById( Branch_tree* branchHead , int  branchId ){
    if( !branchHead) return NULL;

    if(branchHead->branch.branchId > branchId ){
        searchBranchById(branchHead->left , branchId );
    }
    else if(branchHead->branch.branchId < branchId){
        searchBranchById(branchHead->right , branchId );
    }
    else return &branchHead->branch;
}

/*************************************************/
/*  *********     branch data     ***************/

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

void printClientAcountNumberAndBalance(Client_tree* clientHead){
    if(!clientHead) return;
    printClientAcountNumberAndBalance(clientHead->left);
    printf("\nClient account: %d \t Balance: %g \n", clientHead->client.accountNumber , clientHead->client.acountBalance );
    printClientAcountNumberAndBalance(clientHead->right);
    return;
}


//recursive method to find number of appearance of client with account balance that bigger then given balance
int clientNumberWithGivenBalance(Client_tree *clientHead , double Balance) {
    int count = 0 ;
    if(!clientHead) {
        return 0;
    }
    count += clientNumberWithGivenBalance( clientHead -> left , Balance );
    if( clientHead -> client.acountBalance > Balance ) {
        count++;
    }
    count += clientNumberWithGivenBalance( clientHead -> right , Balance );
    return count;
}

//recursive method to find number of appearance of client with account balance that lower then given loan balance
int clientNumberWithBiggerLoansThenBalance( Client_tree *clientHead ) {
    int count = 0 ;
    if(!clientHead) {
        return 0;
    }
    count += clientNumberWithBiggerLoansThenBalance( clientHead -> left );
    if(clientHead -> client.loanBalance > clientHead->client.acountBalance) {
        count++;
    }
    count += clientNumberWithBiggerLoansThenBalance( clientHead -> right );

    return count;

}
