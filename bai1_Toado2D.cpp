#include <stdio.h>
#include <stdint.h>
#include <math.h>

class Coordinates{
    private:
        uint8_t coordinateX;
        uint8_t coordinateY;
    public:
        Coordinates( uint8_t x = 0,  uint8_t y = 0);
        void setCoordinateX( uint8_t x);
        void setCoordinateY( uint8_t y);
        uint8_t getCoordinateX();
        uint8_t getCoordinateY();
};

Coordinates::Coordinates( uint8_t x,  uint8_t y){
    // printf("%d, %d", x, y);
    coordinateX = x;
    coordinateY = y;
}

uint8_t Coordinates::getCoordinateX() 
{
    return this->coordinateX;
}

uint8_t Coordinates::getCoordinateY() {
    return this->coordinateY;
}

void Coordinates::setCoordinateX(uint8_t x) {
    coordinateX = x;
}

void Coordinates::setCoordinateY( uint8_t y) {
    coordinateY = y;
}

class SpaceMath{
    private:
        Coordinates firstPoint;
        Coordinates secondPoint;
        Coordinates thirdPoint;
        bool isDistance;
    public:
        SpaceMath(const Coordinates first, const Coordinates second, const Coordinates third);
        SpaceMath(const Coordinates first, const Coordinates second);
        void setfirstPoint(const Coordinates fisrt);
        void setsecondPoint(const Coordinates second);
        void setthirdPoint(const Coordinates third);

        double distance();
        double trinagleArea();
};

SpaceMath::SpaceMath(const Coordinates first, const Coordinates second, const Coordinates third)
{
    isDistance = false;
    firstPoint = first;
    secondPoint = second;
    thirdPoint = third;
}

SpaceMath::SpaceMath(const Coordinates first, const Coordinates second)
{
    isDistance = true;
    firstPoint = first;
    secondPoint = second;
}

void SpaceMath::setfirstPoint(const Coordinates first){
    firstPoint = first;
}

void SpaceMath::setsecondPoint(const Coordinates second){
    secondPoint = second;
}

void SpaceMath::setthirdPoint(const Coordinates third)
{
    if(!isDistance){
        thirdPoint = third;
    }
    else{
        printf("Chuong trinh khoang cach chi can 2 diem");
    }
}

double SpaceMath::distance(){
    double dist;
    if(isDistance){
        double dx = firstPoint.getCoordinateX() - secondPoint.getCoordinateX();
        double dy = firstPoint.getCoordinateY() - secondPoint.getCoordinateY();
        dist = sqrt(dx*dx + dy*dy);
    }
    return dist;
}

double SpaceMath::trinagleArea(){
    double area;
    if(!isDistance){ 
        double a = firstPoint.getCoordinateX()*secondPoint.getCoordinateY() + secondPoint.getCoordinateX()*thirdPoint.getCoordinateY() + thirdPoint.getCoordinateX()*firstPoint.getCoordinateY();
        double b = firstPoint.getCoordinateY()*secondPoint.getCoordinateX() + secondPoint.getCoordinateY()*thirdPoint.getCoordinateX() + thirdPoint.getCoordinateY()*firstPoint.getCoordinateX();
        area = 0.5 * (a - b);   //Trời ơi để 1/2 làm nó cứ là không hoài
        if(area<0)  area = area * (-1);    
    }
    return area;   
}


int main(int argc, char const *argv[])
{
    Coordinates first, second, third;
    uint8_t temp;

//Đoạn dưới này làm tạm thôi, rãnh làm gọn lại và hợp lí hơn
    NhapToaDo:
    printf("Nhap vao toa do X diem thu nhat\n");
    scanf("%hhd", &temp);
    first.setCoordinateX(temp);
    printf("Nhap vao toa do Y diem thu nhat\n");
    scanf("%hhd", &temp);
    first.setCoordinateY(temp);     

    printf("Nhap vao toa do X diem thu hai\n");
    scanf("%hhd", &temp);
    second.setCoordinateX(temp);
    printf("Nhap vao toa do Y diem thu hai\n");
    scanf("%hhd", &temp);
    second.setCoordinateY(temp); 

    printf("Nhap vao toa do X diem thu ba\n");
    scanf("%hhd", &temp);
    third.setCoordinateX(temp);
    printf("Nhap vao toa do Y diem thu ba\n");
    scanf("%hhd", &temp);
    third.setCoordinateY(temp); 

    printf("Diem A: %d, %d\n", first.getCoordinateX(), first.getCoordinateY())   ;
    printf("Diem B: %d, %d\n", second.getCoordinateX(), second.getCoordinateY())   ;      
    printf("Diem C: %d, %d\n", third.getCoordinateX(), third.getCoordinateY())   ; 

    do
    {
        printf("Nhan 1 de tinh khoang cach tu 2 diem\n");            
        printf("Nhan 2 de tinh dien tich tam giac\n");
        printf("Nhan 3 de thay doi toa do\n");
        uint8_t key;
        scanf("%hhd", &key);

        // switch (key)
        // {
        // case 1:
        //     SpaceMath a(first, second);
        //     break;
        // case 2:
        //     SpaceMath b(first, second, third);
        //     break;        
        // default:
        //     break;
        // }

        if(key == 1) {
            SpaceMath sm(first, second);
            printf("Khoang cach: %lf\n", sm.distance());
        }
        else if(key == 2){
            SpaceMath sm2(first, second, third);
            printf("Dien Tich: %lf\n", sm2.trinagleArea());            
        }
        else goto NhapToaDo;
    } while (true);
    

    return 0;
}
