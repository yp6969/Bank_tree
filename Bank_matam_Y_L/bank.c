#include "bank.h"

/*update all the bank parameters.*/
void updateBankParameters(){
    updateNameOfBank( &bank.nameOfBank ,  ADD );
    updateNumberOfBranch( &bank.numberOfBranch , NON , NON );
    updateNumberOfBankClients( &(bank.numberOfBankClients) , NON , NON );
    updateSumOfAllBankClients( &(bank.sumOfAllBankClients) , NON , NON );
    updateBankProfitOfLastYear( &(bank.profitOfLastYear) , NON , NON );
    updateNumberOfBankActiveLoan( &(bank.numberOfActiveLoans) , NON , NON );
    return;
}
/*creating the branch list with the maximum optional size*/
void inituilizeBank(){
    createBranchList();
    updateBankParameters();
}

void calculateProfitOfLastYear(){
    updateBankProfitOfLastYear( &(bank.profitOfLastYear) , NON , NON);
    return;
}

void printBankParameters(){
    printf("\nname Of Bank: %s \n", bank.nameOfBank );
    printf("Number of branches: %d \n" , bank.numberOfBranch );
    printf("Number of bank client: %d \n" , bank.numberOfBankClients);
    printf("Sum of all bank clients: %g\n " , bank.sumOfAllBankClients);
    printf("Profit of last year: %g \n" , bank.profitOfLastYear);
    printf("Number of active loans: %d \n" , bank.numberOfActiveLoans);
    return;
}