#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string.h>

using namespace std;

typedef enum{
    ADD = 1, 
    DEPOSIT, 
    WITHDRAW, 
    BALANCE,
} CHOICE;

class BankAccount{
    private:
        uint16_t  accountNumber;
        char   accountName[20];
        double balance;     //số tiền còn lại
    public:
        BankAccount(char name[], double bal);
        uint16_t getAccountNumber();
        char *getAccountName();      
        double getBalance();
        void setAccountNumber(uint16_t number);
        void setAccountName(char name[]);
        void setBalance(double bal);
};

BankAccount::BankAccount(char name[], double bal){
    static uint8_t l_number = 100;
    accountNumber = l_number;
    l_number++;      
    strcpy(accountName, name);
    balance = bal;
}

uint16_t BankAccount::getAccountNumber(){
    return this -> accountNumber;
}

char  *BankAccount::getAccountName(){
    return this -> accountName;
}

double BankAccount::getBalance(){
    return this -> balance;
}

// Số tài khoản như là ID nên không được set cho nó
// void BankAccount::setAccountNumber(uint16_t number){
//     accountNumber = number;
// }

void BankAccount::setAccountName(char name[]){
    strcpy(accountName, name);
}


void BankAccount::setBalance(double bal){
    balance = bal;
}

class ManageBank
{
private:
    vector <BankAccount> AccountList;
public:
    ManageBank();
    void addAccount();
    void showList();
    void deposit();                 //gửi tiền
    void withdraw();                //rút tiền
    void checkBalance();            //Kiểm tra số dư
};

ManageBank::ManageBank(){
    do
    {
        printf(" ---- BANK ACCOUNT MANAGEMENT ---- \n");
        printf("Press 1 to add account\n");
        printf("Press 2 to deposit money\n");
        printf("Press 3 to withdraw money\n");
        printf("Press 4 to check account balance\n");

    uint8_t key = 0;
    scanf("%hhu", &key);

        switch (key)
        {
        case ADD:
            addAccount();
            break;        
        case DEPOSIT:
            deposit();
            break;
        case WITHDRAW:
            withdraw();
            break; 
        case BALANCE:
            checkBalance();
            break;                               
        default:
            printf("Your choice: %hhu", &key);
            printf("Invalid input, please try again.\n");
            continue;
        } 
    } while (true);
}

void ManageBank::showList(){
    printf(" ---- SHOW ---- \n");
    if(AccountList.empty())
    {
        printf(" Empty list \n");
    }
    else{
        printf("Number\tName\tbalance\n");
        for(uint8_t i = 0; i< AccountList.size(); i++){                                
            printf("%hu\t%s\t%lf\n", AccountList[i].getAccountNumber(), AccountList[i].getAccountName(), AccountList[i].getBalance());
        }
    }
}
void ManageBank::addAccount(){
    uint16_t l_number;
    char l_name[20];
    double l_balance;
    uint8_t key;

    do
    {
        printf(" ---- ADD ACCOUNT ---- \n");
        printf("Enter account name\n");
        scanf("%s",l_name);
        printf("Enter initial balance\n");
        scanf("%lf", &l_balance);

        BankAccount bank(l_name, l_balance);
        AccountList.push_back(bank);

        showList();
        printf("Press 1 to continue adding cars\n");
        printf("press 2 to exit");
        scanf("%hhu", &key);
    } while (key == 1);
}

void ManageBank::deposit(){
    uint8_t key;
    do
    {           
        showList();   
        printf(" ---- DEPOSIT ----- \n");  
        if(AccountList.empty()) {
            printf(" Empty list \n");
            return; 
        }
       
        uint16_t l_number;
        double l_deposit;
        uint8_t check;
        printf("Enter account number\n");
        scanf("%ld", &l_number);

        for(uint8_t i = 0; i < AccountList.size(); i++){
            if(l_number == AccountList[i].getAccountNumber()){
                printf("Enter the amount you want to deposit\n");
                scanf("%lf", &l_deposit);
                AccountList[i].setBalance(AccountList[i].getBalance() + l_deposit);
                showList();                    
                check = 1;
            }
        }
        if(check == 0){
            printf("Card number %ld not found\n", l_number);
        }

        printf("Press 1 to continue deposit the book\n");
        printf("press 2 to exit");
        scanf("%hhu", &key);        
    } while (key == 1);
}

void ManageBank::withdraw(){
    uint8_t key;
    do
    {           
        showList();   
        printf(" ---- WITHDRAW ----- \n");  
        if(AccountList.empty()) {
            printf(" Empty list \n");
            return; 
        }
       
        uint16_t l_number;
        double l_balance;
        uint8_t check;
        printf("Enter account number\n");
        scanf("%ld", &l_number);

        for(uint8_t i = 0; i < AccountList.size(); i++){
            if(l_number == AccountList[i].getAccountNumber()){
                printf("Enter the amount you want to withdraw\n");
                scanf("%lf", &l_balance);
                if(l_balance <= AccountList[i].getBalance()){
                    
                    AccountList[i].setBalance(AccountList[i].getBalance() - l_balance);
                    showList();                    
                }
                else{
                    printf("Insufficient balance\n");
                }
                check = 1;
            }
        }
        if(check == 0){
            printf("Card number %ld not found\n", l_number);
        }

        printf("Press 1 to continue withdraw the book\n");
        printf("press 2 to exit");
        scanf("%hhu", &key);        
    } while (key == 1);
}

void ManageBank::checkBalance(){
    uint8_t button;
    do
    {
        showList();
        uint16_t l_number, find = 0;
        printf("Enter account number\n");
        scanf("%hd", &l_number);

        for(uint8_t i = 0; i< AccountList.size(); i++){ 
            if(AccountList[i].getAccountNumber() == l_number){
                printf("ID\tcolor\tengine\tkm\n");                
                printf("%hu\t%s\t%lf\n", AccountList[i].getAccountNumber(), AccountList[i].getAccountName(), AccountList[i].getBalance());
                find = 1;
            }                              
        }
        if(find == 0){
            printf("Not found id is %hd\n", l_number);
        }     

        printf("Press 1 to continue payment\n");
        printf("press 2 to exit");
        scanf("%hhu", &button); 
    } while (button == 1);
}

int main(int argc, char const *argv[])
{
    ManageBank mb;
    return 0;
}

