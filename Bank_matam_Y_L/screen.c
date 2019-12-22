/*********************************************************
manage all the oparation in front of the user
*********************************************************/
#include "screen.h"

/*the main manu of the system to easely navigate*/
void screenSystem(){
    int option ;
    printf("\nHello and welcome to %s's Bank\nwhere your money need to be safe!! :) \n\n", bank.nameOfBank );
    FOREVER {
        printf("******************************************\n");
        printf("\nchose youre option:\n\n ");
        printf(" 1)Bank meneger\n");
        printf(" 2)Branch meneger\n");
        printf(" 3) Client\n");
        printf(" 4)Exit \n");
        printf("******************************************\n");
        scanf("%d",&option);
        getchar();
        switch(option){
            case 1:
                bankMenegerOption();
                continue;

            case 2:
                if(!(bank.numberOfBranch)){
                    printf("\nThere is no branches yet\nPlease creat one in the bank option\n\n" );
                    continue;
                }
                else{
                    branchMenegerOption();
                    continue;
                }

            case 3:
                if(!(bank.numberOfBankClients)){
                    printf("\nThere is no clients yet\nPlease creat one in the bank option\n\n" );
                    continue;
                }
                else{
                    clientOption();
                    continue;
                }
            case 4:
                printf("\nGood Bye!!!\n\n");
                return;

            default: 
                printf("\nwrong choise try again\n");
                continue;
        }
    }
    return;
}

/*menu of the bank meneger option only*/
void bankMenegerOption(){
    int option , cnt_client;
    printf("Hello %s the graitest meneger in the world\nwhat are you willing to do?\n\n" , bank.nameOfBank);
    FOREVER{
        printf("**************************************\n");
        printf(" 1)Print bank information\n");
        printf(" 2)Add new branch\n");
        printf(" 3)Client number of bank\n");
        printf(" 4)Averege number Client of bank\n");
        printf(" 5)Go back \n\n");
        printf("*************************************\n");
        scanf("%d",&option);
        getchar();
        switch(option){
            case 1:
                printBankParameters();
                continue;
            case 2:
                addNewBranch_t();
                continue;
            case 3:
                clientNuberOfBank();
                continue;
            case 4:
                printf("The avereg is : %g " , averageNumberOfAccountsInBranches(branchHead , &cnt_client ));
                continue;
            case 5:
                return;
            default:
                printf("wrong choise try again\n");
        }
    }
    return;
}

/*menu of the branch meneger option only*/
void branchMenegerOption(){
    int option , count = 0 , flag = 0 ;
    Branch* branch;
    /* searching the spucific branch */
    do{
        if(flag) printf(" Wrong branch ID rty again ");
        branch = searchBranchById( branchHead , getBranchId() );
        flag = 1;
    }while(!branch);
    printf("Hello Branch meneger number %d!! \nwhat are you willing to do?\n\n" , branch->branchId);
    FOREVER{
        printf("*************************************************\n");
        printf(" 1)Show Branch deatails\n");
        printf(" 2)Add new client to branch\n");
        printf(" 3)client number with given balance\n");
        printf(" 4)client number with bigger loans then balance \n");
        printf(" 5)Print client acount number and balance \n");
        printf(" 6)Go back\n");
        printf("*************************************************\n");
        scanf("%d",&option);
        getchar();
        switch(option){
            case 1:
                printBranchDetails(branch);
                continue;
            case 2:
                addClientToBranch_t(branch);
                continue;
            case 3:
                printf("The number of clients with the wanted balance is : ");
                printf(" %d \n", clientNumberWithGivenBalance(branch->clientHead , getAcountBalance()));
                continue;
            case 4:
                printf("The number of clients with the wanted balance is : ");
                printf(" %d \n", clientNumberWithBiggerLoansThenBalance(branch->clientHead));
                continue;
            case 5:
                printClientAcountNumberAndBalance(branch->clientHead);
                continue;
            case 6:
                return;
            default:
                printf("wrong choise try again\n");
        }
    }
    return;
}


/*menu of the client option only*/
void clientOption(){
    Branch* branch;
    Client* client;
    int option , flag = 0 ;
    do{
        if(flag) printf(" Wrong branch or client ID try again ");
        branch = searchBranchById( branchHead , getBranchId() );
        client = searchClientById( branch->clientHead , getClientId() );  //////////////////////
        flag = 1;
    }while(!branch || !client );
    /*  chose youre option */
    printf("Hello Client %d!! \nwhat are you willing to do?\n\n", client -> accountNumber);
    FOREVER{
        printf("*************************************\n");
        printf(" 1)See client deatails\n");
        printf(" 2)Deposite money to account\n");
        printf(" 3)Deposite money to save\n");
        printf(" 4)ask for loan \n");
        printf(" 5)Repay loans\n");
        printf(" 6)Go back\n");
        printf("************************************\n");
        scanf("%d",&option);
        getchar();
        switch(option){
            case 1:
                printClientDetails(client);
                 
                continue;
            case 2:
                depositeMoneyToClientAccount(client);
                 
                continue;
            case 3:
                depositeMoneyToSave(client);
                 
                continue;
            case 4:
                loanToClient(client , branch);
                 
                continue;
            case 5:
                repayClientLoans(client , branch);
                 
                continue;
            case 6:
                return;
            default:
                printf("\nwrong choise try again\n");
        }
    }
    return;
}
