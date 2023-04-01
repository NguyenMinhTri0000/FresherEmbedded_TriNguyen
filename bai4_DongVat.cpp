#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string.h>

using namespace std;

typedef enum{
    ADD_ANIMAL = 1,
    CALCULATE_BMI,
    COMPARE_AGE,
    COMPARE_WEIGHT,
    DISPLAY_LIST,
    EXIT_PROGRAM,
}CHOICE;

class Animal
{
private:
    char animalName[20];
    uint8_t animalAge;
    uint8_t animalWeight;
    uint8_t animalHeight;
public:
    Animal(char name[20], uint8_t age, uint8_t height,  uint8_t weight);
    void setName(char name[20]);
    void setAge(uint8_t age);
    void setWeight(uint8_t weight);
    void setHeight(uint8_t height);
    char *getName();
    uint8_t getAge();
    uint8_t getWeight();
    uint8_t getHeight();
};

Animal::Animal(char name[20], uint8_t age, uint8_t height,  uint8_t weight)
{
    strcpy(animalName, name);
    animalAge = age;
    animalWeight = weight;
    animalHeight = height;
}

void Animal::setName(char name[20]){
    strcpy(animalName, name);
}

void Animal::setAge(uint8_t age){
    animalAge = age;
}

void Animal::setWeight(uint8_t weight){
    animalWeight = weight;
}

void Animal::setHeight(uint8_t height){
    animalHeight = height;
}

char *Animal::getName(){
    return this -> animalName;
}

uint8_t Animal::getAge(){
    return this -> animalAge;
}

uint8_t Animal::getWeight(){
    return this -> animalWeight;
}

uint8_t Animal::getHeight(){
    return this -> animalHeight;
}

class AnimalManager
{
private:
    vector <Animal> animalList;
public:
    AnimalManager(/* args */);
    void calculateBMI();
    void compareAge();
    void compareWeight();
    void addAnimal();
    void displayAnimalList();
};

AnimalManager::AnimalManager(/* args */)
{
    uint8_t key;
    do
    {
        printf("ANIMAL MANAGER\n");
        printf("Press 1 to add an animal\n");
        printf("Press 2 to calculate BMI\n");
        printf("Press 3 to compare by age\n");
        printf("Press 4 to compare by weight\n");
        printf("Press 5 to display the animal list\n");
        printf("Press 6 to exit program\n");

        scanf("%hhd", &key);

        switch (key)
        {
        case ADD_ANIMAL:
            addAnimal();
            break;
        case CALCULATE_BMI:
            calculateBMI();
            break; 
        case COMPARE_AGE:
            compareAge();
            break;
        case COMPARE_WEIGHT:
            compareWeight();
            break;
        case DISPLAY_LIST:
            displayAnimalList();
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

void AnimalManager::addAnimal(){
    char name[20]; // Using string type would make it harder to read directly
    uint8_t age;
    uint8_t weight;
    uint8_t key;
    uint8_t height;
    do
    {
        printf("ADD ANIMAL\n");
        printf("Enter animal name\n");
        scanf("%s", name);
        printf("Enter animal age\n");
        scanf("%hhd", &age);
        printf("Enter animal height in m\n");
        scanf("%hhd", &height);          
        printf("Enter animal weight in kg\n");
        scanf("%hhd", &weight);
    
        Animal animal(name, age, height, weight);
        animalList.push_back(animal);
        displayAnimalList();

        printf("Press 1 to continue adding animals\n");
        printf("Press 2 to exit\n");
        scanf("%hhd", &key);
    } while (key == 1);
    
}

void AnimalManager::displayAnimalList(){
    printf("DISPLAY ANIMAL LIST\n");
    if(animalList.empty()){
        printf("The list is empty.\n");
    }
    else{
        printf("NO.\tName\tAge\tHeight\tWeight\n");        
        for(uint8_t i = 0; i < animalList.size(); i++){
            printf("%hhd\t%s\t%hhd\t%hhd\t%hhd\n", i+1, animalList[i].getName(), animalList[i].getAge(), animalList[i].getHeight(), animalList[i].getWeight());
        }
    }
}

//TAI SAO TINH BMI XONG THI MẤT HẾT CẢ DANH SÁCH
void AnimalManager::calculateBMI(){
    printf("CALCULATE BMI\n");
    uint8_t key;
    char name[20];
    double BMI;
    bool found;
    do
    {
        found = false;   
        displayAnimalList();
        printf("Enter the name of the animal to calculate BMI\n");
        scanf("%s", name);
        for(uint8_t i; i < animalList.size(); i++){
            if(strcmp(animalList[i].getName(), name)==0){
                double temp = (double) (animalList[i].getHeight()*animalList[i].getHeight());
                BMI = (double) (animalList[i].getWeight())/temp;
                printf("BMI of %s is %lf\n",name, BMI);
                found = true;
                break;
            }
        }

        if(!found){
            printf("No animal with name %s found.\n", name);        
        }
        printf("Press 1 to continue calculating BMI\n");
        printf("Press 2 to exit\n");
        scanf("%hhd", &key);
    } while (key == 1);
}


void AnimalManager::compareWeight(){
    printf("COMPARE WEIGHT\n");
    for(uint8_t i = 0; i < animalList.size() - 1; i++){
        for (uint8_t j = i + 1; j < animalList.size(); j++) {
            if (animalList[i].getWeight() > animalList[j].getWeight()) {
                swap(animalList[i], animalList[j]);                
            }
        }
    }
    displayAnimalList();
}

void AnimalManager::compareAge(){
    printf("COMPARE AGE\n");
    for(uint8_t i = 0; i < animalList.size() - 1; i++){
        for (uint8_t j = i + 1; j < animalList.size(); j++) {
            if (animalList[i].getAge() > animalList[j].getAge()) {
                swap(animalList[i], animalList[j]);                
            }
        }
    }
    displayAnimalList();    
}

int main(int argc, char const *argv[])
{
    AnimalManager ql;
    return 0;
}
