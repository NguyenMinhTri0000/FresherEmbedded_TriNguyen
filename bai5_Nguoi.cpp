#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string.h>

using namespace std;

typedef enum{
    ADD_PERSON = 1,
    CALCULATE_AGE,
    DISPLAY_LIST,
    EXIT_PROGRAM,
}CHOICE;

class Person
{
private:
    char personName[20];
    uint8_t personAge;
    char personAddress[50];
public:
    Person(char name[20], uint8_t age, char address[50]);
    void setName(char name[20]);
    void setAge(uint8_t age);
    void setAddress(char address[50]);
    char *getName();
    uint8_t getAge();
    char *getAddress();
};

Person::Person(char name[20], uint8_t age, char address[50])
{
    strcpy(personName, name);
    personAge = age;
    strcpy(personAddress, address);
}

void Person::setName(char name[20]){
    strcpy(personName, name);
}

void Person::setAge(uint8_t age){
    personAge = age;
}

void Person::setAddress(char address[50]){
    strcpy(personAddress, address);
}

char *Person::getName(){
    return this -> personName;
}

uint8_t Person::getAge(){
    return this -> personAge;
}

char *Person::getAddress(){
    return this -> personAddress;
}

class PersonManager
{
private:
    vector <Person> personList;
public:
    PersonManager(/* args */);
    void calculateAge();
    void addPerson();
    void displayPersonList();
};

PersonManager::PersonManager(/* args */)
{
    uint8_t key;
    do
    {
        printf("PERSON MANAGER\n");
        printf("Press 1 to add a person\n");
        printf("Press 2 to calculate age\n");
        printf("Press 3 to display the person list\n");
        printf("Press 4 to exit program\n");

        scanf("%hhd", &key);

        switch (key)
        {
        case ADD_PERSON:
            addPerson();
            break;
        case CALCULATE_AGE:
            calculateAge();
            break; 
        case DISPLAY_LIST:
            displayPersonList();
            break;
        case EXIT_PROGRAM:
            return;
            break;                                                       
        default:
            printf("You entered %hhd. Please enter a valid choice\n", key);
            break;
        }
    } while (true);
}

void PersonManager::addPerson(){
    char name[20];
    uint8_t age;
    char address[50];
    uint8_t key;
    do
    {
        printf("ADD PERSON\n");
        printf("Enter person name\n");
        scanf("%s", name);
        printf("Enter person age\n");
        scanf("%hhd", &age);
        printf("Enter person address\n");
        scanf("%s", address);

        Person person(name, age, address);
        personList.push_back(person);
        displayPersonList();

        printf("Press 1 to continue adding person\n");
        printf("Press 2 to exit\n");
        scanf("%hhd", &key);
    } while (key == 1);
    
}

void PersonManager::displayPersonList(){
    printf("DISPLAY PERSON LIST\n");
    if(personList.empty()){
        printf("The list is empty.\n");
    }
    else{
        printf("NO.\tName\tAge\tAddress\n");        
        for(uint8_t i; i < personList.size(); i++){
            printf("%hhd\t%s\t%hhd\t%s\n", i+1, personList[i].getName(), personList[i].getAge(), personList[i].getAddress());
        }
    }    
}

void PersonManager::calculateAge(){
    printf("De co tuoi roi ma??");
}

int main(int argc, char const *argv[])
{
    PersonManager pm;
    return 0;
}
