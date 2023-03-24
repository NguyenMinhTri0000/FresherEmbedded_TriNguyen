#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string.h>

using namespace std;

typedef enum{
    ADD = 1,
    PAY,
    CHECKKM,
    INFORMATION,
} CHOICE;

class Car{
    private:
        char   carColor[20];
        char   engineCar[20];
        uint16_t numberKm;
        uint16_t previousKm = 0;        
        uint8_t id;
    public:
        Car(char color[], char engine[], uint16_t km);
        char *getCarColor();
        char *getEngineCar();      
        uint16_t getNumberKm();
        uint8_t getId();
        uint16_t getPreviousKm();
        void setCarColor(char color[]);
        void setEngineCar(char engine[]);
        void setNumberKm(uint16_t km);
        void setPreviousKm(uint16_t p_km);
};

Car::Car(char color[], char engine[], uint16_t km)
{
    static uint8_t l_id = 100;
    id = l_id;
    l_id++;    
    strcpy(carColor, color);
    strcpy(engineCar, engine);
    numberKm = km;
}

uint8_t Car::getId()
{
    return this->id;
}

uint16_t Car::getPreviousKm(){
    return this->previousKm;
}
char *Car::getCarColor(){
    return this -> carColor;
}

char  *Car::getEngineCar(){
    return this -> engineCar;
}

uint16_t Car::getNumberKm(){
    return this -> numberKm;
}


void Car::setCarColor(char color[]){
    strcpy(carColor, color);
}

void Car::setEngineCar(char engine[]){
    strcpy(engineCar, engine);
}

void Car::setNumberKm(uint16_t km){
    numberKm = km;
}

void Car::setPreviousKm(uint16_t p_km){
    previousKm = p_km;
}

class ManageGarage
{
private:
    vector <Car> CarList;
public:
    ManageGarage();
    void printInfor();
    void payMaintenance();
    void checkKm();
    void addCar();
    void increaseKm();      //dùng để mô phỏng trường hppwj. Khi xe đã thanh toán a km đầu, đi thêm b km, thì chỉ cần thanh toán b km, chứ không phải a + b
};

ManageGarage::ManageGarage()
{
    do
    {
        printf(" ---- MANAGE GARAGE ---- \n");
        printf("press 1 to add cars\n");
        printf("Press 2 to pay the maintenance fee\n");
        printf("Press 3 to check the number of km\n");
        printf("Press 4 to display car information\n");   
        printf("Press 5 to simulate more km\n")  ;           

        uint8_t key = 0;
        scanf("%hhu", &key);

        switch (key)
        {
        case ADD:
            addCar();
            break;        
        case PAY:
            payMaintenance();
            break;
        case CHECKKM:
            checkKm();
            break; 
        case INFORMATION:
            printInfor();
            break;          
        case 5:     //Mô phỏng thêm số km
            increaseKm();
            break;                        
        default:
            printf("Your choice: %hhu", &key);
            printf("Invalid input, please try again.\n");
            continue;
        } 
    } while (true);  
}

void ManageGarage::addCar(){
    char l_color[20];
    char l_engine[20];
    uint16_t l_km;
    uint8_t key;
    do
    {
        printInfor();
        printf(" ---- ADD CAR ---- \n");
        printf("Enter car color\n");
        scanf("%s",l_color);
        printf("Enter the engine\n");
        scanf("%s",l_engine);       
        printf("Enter the number of km\n");
        scanf("%hu", &l_km);

        Car car(l_color, l_engine, l_km);
        CarList.push_back(car);

        printInfor();
        printf("Press 1 to continue adding cars\n");
        printf("press 2 to exit");
        scanf("%hhu", &key);
    } while (key == 1);
}

void ManageGarage::checkKm(){
    uint8_t button;
    do
    {
        printInfor();
        uint8_t l_id, find = 0;
        printf("Enter vehicle id \n");
        scanf("%hhd", &l_id);

        for(uint8_t i = 0; i< CarList.size(); i++){ 
            if(CarList[i].getId() == l_id){
                printf("ID\tcolor\tengine\tkm\n");                
                printf("%hhu\t%s\t%s\t%hu\n", CarList[i].getId(), CarList[i].getCarColor(), CarList[i].getEngineCar(), CarList[i].getNumberKm());
                find = 1;
            }                              
        }
        if(find == 0){
            printf("Not found id is %hhd\n", l_id);
        }     

        printf("Press 1 to continue payment\n");
        printf("press 2 to exit");
        scanf("%hhu", &button); 
    } while (button == 1);
}

void ManageGarage::payMaintenance(){
    uint8_t button;
    do
    {
        printInfor();
        uint8_t l_id, find = 0;
        printf("Enter vehicle id \n");
        scanf("%hhd", &l_id);

        for(uint8_t i = 0; i< CarList.size(); i++){ 
            if(CarList[i].getId() == l_id){
                uint32_t fee;
                fee = (CarList[i].getNumberKm() - CarList[i].getPreviousKm())*10000;    //giả sử 1 km là tốn 10.000

                //Hiển thị phí ra
                printf("ID\tcolor\tengine\tkm\tkmprevious\tfee\n");                
                printf("%hhu\t%s\t%s\t%hu\t%hu\t\t%u\n", CarList[i].getId(), CarList[i].getCarColor(), CarList[i].getEngineCar(), CarList[i].getNumberKm(), CarList[i].getPreviousKm(), fee);
                
                uint8_t key;
                printf("Press 1 to confirm payment\n");    
                printf("Press 2 to cancel\n");
                scanf("%hhd", &key);
                if(key == 1){
                    printf("Payment success\n");
                    CarList[i].setPreviousKm(CarList[i].getNumberKm());                
                    fee = 0;
                }
                else{
                    printf("Payment canceled\n");
                    fee = 0;                
                }

                //Hiển thị phí ra
                printf("ID\tcolor\tengine\tkm\tkmprevious\tfee\n");                
                printf("%hhu\t%s\t%s\t%hu\t%hu\t\t%u\n", CarList[i].getId(), CarList[i].getCarColor(), CarList[i].getEngineCar(), CarList[i].getNumberKm(), CarList[i].getPreviousKm(), fee);

                find = 1;
            }                              
        }
        if(find == 0){
            printf("Not found id is %hhd\n", l_id);
        } 

        printf("Press 1 to continue payment\n");
        printf("press 2 to exit");
        scanf("%hhu", &button); 
    } while (button == 1);
}

void ManageGarage::printInfor(){
    printf(" ---- SHOW ---- \n");
    if(CarList.empty())
    {
        printf(" Empty list \n");
    }
    else{
        printf("ID\tcolor\tengine\tkm\tkm_previous\n");
        for(uint8_t i = 0; i< CarList.size(); i++){                                
            printf("%hhu\t%s\t%s\t%hu\t%hu\n", CarList[i].getId(), CarList[i].getCarColor(), CarList[i].getEngineCar(), CarList[i].getNumberKm(), CarList[i].getPreviousKm());
        }
    }
}

void ManageGarage::increaseKm(){
   uint8_t button;
    do
    {
        printInfor();
        uint8_t l_id, find = 0;
        printf("Enter vehicle id \n");
        scanf("%hhd", &l_id);

        for(uint8_t i = 0; i< CarList.size(); i++){ 
            if(CarList[i].getId() == l_id){
                uint16_t newKm;
                printf("Enter the number of kilometers you want to increase\n");
                scanf("%hd", &newKm);
                CarList[i].setNumberKm(CarList[i].getNumberKm()+ newKm);
                printInfor();
                find = 1;
            }                              
        }
        if(find == 0){
            printf("Not found id is %hhd\n", l_id);
        } 

        printf("Press 1 to continue payment\n");
        printf("press 2 to exit");
        scanf("%hhu", &button); 
    } while (button == 1);
    
}
int main(int argc, char const *argv[])
{
    ManageGarage ml;
    return 0;
}
