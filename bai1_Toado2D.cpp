#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <vector>
#include <string.h>

using namespace std;

typedef enum{
    ADD =1,
    DISTANCE,
    TRIANGLEAREA,
}CHOICE;

class Coordinate {
private:
    char name[2];
    uint8_t x;
    uint8_t y;
public:
    Coordinate(char name[2], uint8_t x, uint8_t y);
    uint8_t getX();
    void setX(uint8_t x);
    uint8_t getY();
    void setY(uint8_t y);
    char *getName();
    void setName(char l_name[2]);

};

Coordinate::Coordinate(char l_name[2], uint8_t l_x, uint8_t l_y) {
    x = l_x;
    y = l_y;
    strcpy(name, l_name);    
}

uint8_t Coordinate::getX() {
    return this->x;
}

void Coordinate::setX(uint8_t x) {
    this->x = x;
}

uint8_t Coordinate::getY() {
    return this->y;
}

void Coordinate::setY(uint8_t y) {
    this->y = y;
}

char *Coordinate::getName() {
    return this->name;
}

void Coordinate::setName(char l_name[2]) {
    strcpy(name, l_name);
}

class SpatialOperations {
private:
    vector <Coordinate>  ListPoint;
    Coordinate Check(char l_name[2]);
public:
    void addPoint();
    void distance();
    void triangleArea();
    void show();
    SpatialOperations();
};
 
SpatialOperations::SpatialOperations(){
    do
    {
    printf("Press 1 to add point\n");
    printf("Press 2 to calculate distance\n");
    printf("Press 3 to calculate triangle area\n");

    uint8_t key = 0;
    scanf("%hhu", &key);

        switch (key)
        {
        case ADD:
            addPoint();
            break;        
        case DISTANCE:
            distance();
            break;
        case TRIANGLEAREA:
            triangleArea();
            break;                              
        default:
            printf("Your choice: %hhu", &key);
            printf("Invalid input, please try again.\n");
            continue;
        } 
    } while (true);    
}

Coordinate SpatialOperations::Check(char l_name[2]){
    uint8_t key;
    // do
    // {
        for(uint8_t i = 0; i < ListPoint.size(); i++){
            if(strcmp(ListPoint[i].getName(), l_name)==0){            
                return ListPoint[i];
            }  
            key = 1;
        }
    //     if(key == 1) printf("Point %s could not be found. Please re-enter", l_name);
    // } while (key == 1);
}

void SpatialOperations::addPoint(){
    uint8_t l_x;
    char l_name[2];
    uint8_t l_y;
    uint8_t key;

    do
    {
        printf(" ---- ADD POINT ---- \n");
        printf("Enter point name\n");
        scanf("%s",l_name);
        printf("input x coordinates\n");
        scanf("%hhd", &l_x);
        printf("input y coordinates\n");
        scanf("%hhd", &l_y);

        Coordinate point(l_name, l_x, l_y);
        ListPoint.push_back(point);

        show();
        printf("Press 1 to continue adding point\n");
        printf("press 2 to exit");
        scanf("%hhu", &key);
    } while (key == 1);
}

void SpatialOperations::distance(){
uint8_t key;
    do
    {           
        char namePoint1[2];
        char namePoint2[2];   

        printf("enter the first point name\n");
        scanf("%s", namePoint1);
        printf("enter the second point name\n");
        scanf("%s", namePoint2); 
    
        double dx = Check(namePoint1).getX() - Check(namePoint2).getX();
        double dy = Check(namePoint1).getY() - Check(namePoint2).getY();
        
        printf("Ket qua: %lf\n", sqrt(dx*dx + dy*dy));

        printf("Press 1 to continue withdraw the book\n");
        printf("press 2 to exit");
        scanf("%hhu", &key);        
    } while (key == 1);
}

    void SpatialOperations::triangleArea(){
    //     char namePoint1[2];
    //     char namePoint2[2]; 
    //     char namePoint3[2];           

    //     printf("enter the first point name\n");
    //     scanf("%s", namePoint1);
    //     printf("enter the second point name\n");
    //     scanf("%s", namePoint2); 
    //     printf("enter the third point name\n");
    //     scanf("%s", namePoint3);    

    // printf("Ket qua %s", fabs(0.5 * (Check(namePoint1).getX * (Check(namePoint2).getY - Check(namePoint3).y) + Check(namePoint2).getX * (Check(namePoint3).getY - Check(namePoint1).getY) + Check(namePoint3).getX * (Check(namePoint1).getY - Check(namePoint2).getY))));            
    }

void SpatialOperations::show(){
    printf(" ---- SHOW ---- \n");
    if(ListPoint.empty())
    {
        printf(" Empty list \n");
    }
    else{
        printf("Point\tx\ty\n");
        for(uint8_t i = 0; i< ListPoint.size(); i++){                                
            printf("%s\t%hhu\t%hhu\n", ListPoint[i].getName(), ListPoint[i].getX(), ListPoint[i].getY());
        }
    }
}
    // double SpatialOperations::distance(Coordinate c1, Coordinate c2) {
    //     double dx = c1.getX() - c2.getX();
    //     double dy = c1.getY() - c2.getY();
    //     return sqrt(dx*dx + dy*dy);
    // }

    // double SpatialOperations::triangleArea(Coordinate c1, Coordinate c2, Coordinate c3) {
    //     double a = distance(c1, c2);
    //     double b = distance(c2, c3);
    //     double c = distance(c3, c1);
    //     double p = (a + b + c) / 2;
    //     return sqrt(p * (p-a) * (p-b) * (p-c));
    // }
int main(int argc, char const *argv[]) {

    SpatialOperations sp;

    return 0;
}
