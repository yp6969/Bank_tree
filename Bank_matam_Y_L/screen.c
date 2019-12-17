/*********************************************************
manage all the oparation in front of the user
*********************************************************/
#include "screen.h"

/*the main manu of the system to easely navigate*/
void screenSystem(){
    int option ;
    printf("\nHello and welcome to %s's Bank\nwhere your money need to be safe!! :) \n\n", bank.nameOfBank );
    FOREVER {
        printf("\nchose youre option:\n\n  1)Bank meneger \t 2)Branch meneger \t 3) Client \t 4)Exit \n");
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
    int option , max = maxBalance();
    Branch_list* tempHead = branchHead;
    Client** richestClients = NULL;
    int richestClients_REC = 0;
    printf("Hello %s the graitest meneger in the world\nwhat are you willing to do?\n\n" , bank.nameOfBank);
    FOREVER{
        printf("********************************\n");
        printf("1)Add new branch  \t 2)Delete Branch \t 3)Delete client \n\n");
        printf("4)richesr clients \t5)richest clients REC \n\n");
        printf("6)Print bank information \t7)Go back \n\n");
        printf("********************************\n");
        scanf("%d",&option);
        getchar();
        switch(option){
            case 1:
                addNewBranchToList();
                 
                continue;
            case 2:
                if(!(bank.numberOfBranch)){
                    printf("\nThere is no branch yet\nPlease creat one if you want to delete\n\n" );
                    continue;
                }
                else deleteBranchFrom_List();/*get the branch from the input*/
                continue;
            case 3:
                if( !bank.numberOfBankClients || !bank.numberOfBranch ){
                    printf("\nThere is no clients yet\nPlease creat Branch and client\nif you want to delete one\n\n" );
                    continue;
                }
                else deleteClientFrom_List( NULL );/*get the branch from the input*/
                continue;
            case 4:
                richestClients = clientNumberOfBank();
                continue;
            case 5:
                richestClients_REC = clientNumberOfBank_REC(tempHead , max );
                continue;
            case 6:
                printBankParameters();
                continue;
            case 7:
                return;
            default:
                printf("wrong choise try again\n");
        }
    }
    return;
}

/*menu of the branch meneger option only*/
void branchMenegerOption(){
    int option , count = 0 ;
    Branch* branch = searchBranchById_List( NON , ADD );
    Client** clientArr;
    if(!branch) return;
    printf("Hello Branch meneger number %d!! \nwhat are you willing to do?\n\n" , branch->branchId);
    FOREVER{
        printf("********************************\n");
        printf("1)Add new client to branch \t 2)Delete client \n\n 3)Show Branch deatails \t 4)clients with bigger loans then balance\n\n");
        printf("5) clients with bigger loans then balance_REC \t 6)Go back\n\n");
        #ifdef BANK_AMALIM
        printf("7)print branch clients balances \t 8)client with givven balance\n\n");
        #endif
        printf("********************************\n");
        scanf("%d",&option);
        getchar();
        switch(option){
            case 1:
                addNewClientToList( &branch->clientHead  , branch );
                continue;
            case 2:
                if(!(branch->numberOfBranchClients)){
                    printf("\nThere is no clients yet\nPlease creat one if you want to delete\n\n");
                    continue;
                }
                else deleteClientFrom_List(branch->clientHead);
                 
                continue;
            case 3:
                printBranchDetails(branch);
                 
                continue;
            case 4:
                clientArr = clientNumberWithBiggerLoansThenBalance(branch->clientHead);

                continue;
            case 5:
                clientNumberWithBiggerLoansThanBalance_REC( branch->clientHead , &count);
                printf("\n\n  sdsads  %d  \n\n",count);
                continue;
            case 6:
                return;
            /****************************************************/    
            /*   just if the bank whas paid extra cash*/    
            #ifdef BANK_AMALIM

            case 7:
                printClientAcountNumberAndBalance(branch->clientHead);
                 
                continue;
            case 8:
                clientNumberWithGivenBalance(branch->clientHead);
                 
                continue;
            #endif
            /*********************************************************/

            default:
                printf("wrong choise try again\n");
        }
    }
    return;
}


/*menu of the client option only*/
void clientOption(){
    Branch* branch = searchBranchById_List( NON , ADD );
    Client* client;
    int option ;
    if( !branch ) return;
    client = searchClientById_List( branch->clientHead , NON , ADD);
    if(!client) return;
    printf("Hello Client %d!! \nwhat are you willing to do?\n\n", client -> accountNumber);
    FOREVER{
        printf("*************************************\n");
        printf("1)See client deatails \t\t2)Deposite money to account \n\n");
        printf("3)Deposite money to save\t4)ask for loan \n\n5)Repay loans \t\t\t6)Go back\n\n");
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
                loanToClient(client);
                 
                continue;
            case 5:
                repayClientLoans(client);
                 
                continue;
            case 6:
                return;
            default:
                printf("\nwrong choise try again\n");
        }
    }
    return;
}
