#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string.h>

using namespace std;

typedef enum{
    ADD = 1,
    BORROW,
    BACK,
    INFORMATION,
} CHOICE;

class Book{
    private:
        char   bookName[20];
        char   authorBook[20];
        uint16_t publishYear;
        uint16_t numberBook;
        uint8_t id;
    public:
        Book(char name[], char author[], uint16_t year, uint16_t number);
        char *getBookName();
        char *getAuthorName();      
        uint16_t getpublishYear();
        uint16_t getNumberBook();
        void setBookName(char name[]);
        void setAuthorName(char author[]);
        void setPublishYear(uint16_t year);
        void setNumberBook(uint16_t number);
};

Book::Book(char name[], char author[], uint16_t year, uint16_t number)
{
    static uint8_t l_id = 100;
    id = l_id;
    l_id++;
    strcpy(bookName, name);
    strcpy(authorBook, author);
    publishYear = year;
    numberBook = number;
}

char *Book::getBookName(){
    return this -> bookName;
}

char  *Book::getAuthorName(){
    return this -> authorBook;
}

uint16_t Book::getpublishYear(){
    return this -> publishYear;
}

uint16_t Book::getNumberBook(){
    return this -> numberBook;
}
void Book::setBookName(char name[]){
    strcpy(bookName, name);
}

void Book::setAuthorName(char author[]){
    strcpy(authorBook, author);
}

void Book::setPublishYear(uint16_t year){
    publishYear = year;
}

void Book::setNumberBook(uint16_t number){
    numberBook = number;
}

class ManageLibrary
{
private:
    vector <Book> BookList;
public:
    ManageLibrary();
    void printInfor();
    void bookBorrow();
    void bookBack();
    void addBook();
};

ManageLibrary::ManageLibrary()
{
    do
    {
        printf(" ---- MANAGE LIBRARY ---- \n");
        printf("press 1 to add books\n");
        printf("Press 2 to borrow books\n");
        printf("press 3 to return the book\n");
        printf("Press 4 to display book information\n");        

        uint8_t key = 0;
        scanf("%hhu", &key);

        switch (key)
        {
        case ADD:
            addBook();
            break;        
        case BORROW:
            bookBorrow();
            break;
        case BACK:
            bookBack();
            break; 
        case INFORMATION:
            printInfor();
            break;                    
        default:
            printf("Your choice: %hhu", &key);
            printf("Invalid input, please try again.\n");
            continue;
        } 
    } while (true);  
}

void ManageLibrary::addBook(){
    char l_name[20];
    char l_author[20];
    uint16_t l_year;
    uint16_t l_number;
    uint8_t key;
    do
    {
        printInfor();
        printf(" ---- ADD BOOK ---- \n");
        printf("Enter the title of the book\n");
        scanf("%s",l_name);
        printf("Enter the author's name\n");
        scanf("%s",l_author);       
        printf("Enter the year of publication\n");
        scanf("%hu", &l_year);
        printf("Enter the number of books\n");
        scanf("%hu", &l_number);

        Book book(l_name, l_author, l_year, l_number);
        BookList.push_back(book);

        printInfor();
        printf("Press 1 to continue adding books\n");
        printf("press 2 to exit");
        scanf("%hhu", &key);
    } while (key == 1);
}

void ManageLibrary::bookBorrow(){
    uint8_t key;
    uint8_t stop;
    do
    {           
        printInfor();   
        printf(" ---- BORROW ----- \n");  

        if(BookList.empty()) {
            printf(" Empty list \n");
            return; 
        }
       
        char l_bookName[20];
        char l_authorName[20];
        uint16_t l_number;
        printf("Enter the title of the book\n");
        scanf("%s", l_bookName);

        for(uint8_t i = 0; i < BookList.size(); i++){
            if(strcmp(BookList[i].getBookName(), l_bookName)==0){
                for(uint8_t j = i + 1; j < BookList.size(); j++){
                   if(strcmp(BookList[i].getBookName(), BookList[j].getBookName())==0) {
                    printf("Same book title\n");
                    stop = 1;

                    printf("Enter the author's name\n");
                    scanf("%s", &l_authorName); 
                    if(strcmp(BookList[i].getAuthorName(), l_authorName)==0){   
                        printf("Enter the number of books to borrow: \n");
                        scanf("%hu", &l_number);
                        if(l_number <= BookList[i].getNumberBook()){
                            BookList[i].setNumberBook(BookList[i].getNumberBook() - l_number);     
                            printf(" Lent finish\n");
                            printInfor(); 
                        }
                        else{
                            printf("Library has only %hd books named %s\n", BookList[i].getNumberBook(), l_bookName);
                        }
                        printInfor();   
                    }
                    else if(strcmp(BookList[j].getAuthorName(), l_authorName)==0){   
                        printf("Enter the number of books to borrow");
                        scanf("%hu", &l_number);
                        if(l_number <= BookList[j].getNumberBook()){
                            BookList[j].setNumberBook(BookList[j].getNumberBook() - l_number);     
                            printf(" Lent finish\n");
                            printInfor(); 
                        }
                        else{
                            printf("Library has only %hd books named %s\n", BookList[j].getNumberBook(), l_bookName);
                        }
                    }  
                   }
                }

                if(stop == 1) {     //Dừng vòng for ngoài của i
                    break;
                }
                else{               //stop =0 tức là không có sách trùng tên
                    stop = 1;
                    printf("Enter the number of books to borrow");
                    scanf("%hu", &l_number);
                    if(l_number <= BookList[i].getNumberBook()){
                        BookList[i].setNumberBook(BookList[i].getNumberBook() - l_number);     //
                        printf(" Lent finish\n");
                        printInfor(); 
                    }
                    else{
                        printf("Library has only %hd books named %s\n", BookList[i].getNumberBook(), l_bookName);
                    }
                    break;
                }
            }

        }
        if(stop == 0){
                    printf("Couldn't find a book named %s\n", l_bookName);  
        } 

        printf("Press 1 to continue borrowing the book\n");
        printf("press 2 to exit");
        scanf("%hhu", &key);        
    } while (key == 1);
}

void ManageLibrary::bookBack(){
    uint8_t key;
    do
    {           
        printInfor();   
        printf(" ---- RETURN ----- \n");  

        if(BookList.empty()) {
            printf(" Empty list \n");
            return; 
        }
       
        char l_bookName[20];
        char l_authorName[20];
        uint16_t l_number;
        uint8_t stop  = 0;
        printf("Enter the title of the book\n");
        scanf("%s", l_bookName);

        for(uint8_t i = 0; i < BookList.size(); i++){
            if(strcmp(BookList[i].getBookName(), l_bookName)==0){
                for(uint8_t j = i + 1; j < BookList.size(); j++){
                   if(strcmp(BookList[i].getBookName(), BookList[j].getBookName())==0) {
                    printf("Same book title\n");
                    stop = 1;

                    printf("Enter the author's name\n");
                    scanf("%s", &l_authorName); 
                    if(strcmp(BookList[i].getAuthorName(), l_authorName)==0){   
                        printf("Enter the number of books to return");
                        scanf("%hu", &l_number);
                        BookList[i].setNumberBook(BookList[i].getNumberBook() + l_number);     //
                        printf("Return finish\n");
                        printInfor();   
                    }
                    else if(strcmp(BookList[j].getAuthorName(), l_authorName)==0){   
                        printf("Enter the number of books to return");
                        scanf("%hu", &l_number);
                        BookList[j].setNumberBook(BookList[j].getNumberBook() + l_number);     //
                        printf("Return finish\n");
                        printInfor(); 
                    }  
                   }
                }

                if(stop == 1) {     //Dừng vòng for ngoài của i
                    break;
                }
                else{               //stop =0 tức là không có sách trùng tên
                    stop = 1;
                    printf("Enter the number of books to return");
                    scanf("%hu", &l_number);
                    BookList[i].setNumberBook(BookList[i].getNumberBook() + l_number);     
                    printf("Return finish\n");
                    printInfor(); 
                    break;
                }
            }

        }
        if(stop == 0){
                    printf("Couldn't find a book named %s\n", l_bookName);  
        }        

        printf("Press 1 to continue returning the book\n");
        printf("press 2 to exit");        
        scanf("%hhu", &key);        
    } while (key == 1);
}

void ManageLibrary::printInfor(){
    printf(" ---- SHOW ---- \n");
    if(BookList.empty())
    {
        printf(" Empty list \n");
    }
    else{
        printf("\tname\tauthor\tyear\tnumber\n");
        for(uint8_t i = 0; i< BookList.size(); i++){                                
            printf("%hhu\t%s\t%s\t%hu\t%hu\n", i + 1, BookList[i].getBookName(), BookList[i].getAuthorName(), BookList[i].getpublishYear(), BookList[i].getNumberBook());
        }
    }
}

int main(int argc, char const *argv[])
{
    ManageLibrary ml;
    return 0;
}
