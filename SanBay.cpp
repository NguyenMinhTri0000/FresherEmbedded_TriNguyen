#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string.h>

using namespace std;

typedef enum{
    ADD_FLIGHT = 1,
    DEL_FLIGHT,
    SEARCH_BY_DESTINATION,
    SEARCH_BY_ID,
    BOOK_TICKET,
    CANCAL_TICKET,
    VIEW,
    EXIT,
}CHOICE;


class Booking
{
private:
    uint8_t idBooking;
    char customerName[20];   
    uint16_t seatNumber;
public:
    Booking(char customerName[20], uint16_t seatNumber);
    void setSeatNumber(uint16_t seatNumber);
    void setcustomerName(char customerName[20]);
    uint16_t getSeatNumber();
    char *getCustomerName();
    uint8_t getIdBooking();
};

Booking::Booking(char customerName[20], uint16_t seatNumber)
{
    static uint8_t idBooking = 1;
    Booking::idBooking = idBooking;
    idBooking ++;

    strcpy(Booking::customerName, customerName);
    Booking::seatNumber = seatNumber;
}

void Booking::setSeatNumber(uint16_t seatNumber){
    Booking::seatNumber = seatNumber;
}

void Booking::setcustomerName(char customerName[20]){
    strcpy(Booking::customerName, customerName);    
}

uint8_t Booking::getIdBooking(){
    return this->idBooking;
}

uint16_t Booking::getSeatNumber(){
    return this -> seatNumber;
}

char *Booking::getCustomerName(){
    return this -> customerName;
}

class Flight
{
private:
    uint8_t idFlight;
    char origin[40];
    char destination[40];
    uint8_t departureTime;
    uint8_t arrivalTime;
    uint16_t availableSeats;
public:
    vector <Booking> ListBooking;
    Flight(char origin[40], char destination[40], uint8_t departureTime, uint8_t arrivalTime, uint16_t availableSeats);
    void setOrigin(char origin[40]);
    void setDestination(char destination[40]);
    void setDepartureTime(uint8_t departureTime);
    void setArrivalTime(uint8_t arrivalTime);
    void setAvailableSeats(uint16_t availableSeats);

    uint8_t getIdFlight();
    char *getOrigin();
    char *getDestination();
    uint8_t getDepartureTime();
    uint8_t getArrivalTime();
    uint16_t getAvailableSeats();
};

Flight::Flight(char origin[40], char destination[40], uint8_t departureTime, uint8_t arrivalTime, uint16_t availableSeats)
{
    static uint8_t id = 100;
    idFlight = id;
    id++;
    strcpy(Flight::origin, origin);
    strcpy(Flight::destination, destination);
    Flight::departureTime = departureTime;
    Flight::arrivalTime = arrivalTime;
    Flight::availableSeats = availableSeats;    
}

void Flight::setOrigin(char origin[40]){
    strcpy(Flight::origin, origin);
}

void Flight::setDestination(char destination[40]){
    strcpy(Flight::destination, destination);
}

void Flight::setDepartureTime(uint8_t departureTime){
    Flight::departureTime = departureTime;    
}

void Flight::setArrivalTime(uint8_t arrivalTime){
    Flight::arrivalTime = arrivalTime;
}

void Flight::setAvailableSeats(uint16_t availableSeats){
    Flight::availableSeats = availableSeats;  
}

uint8_t Flight::getIdFlight(){
    return this->idFlight;
}

char * Flight::getOrigin(){
    return this -> origin;
}

char *Flight::getDestination(){
    return this -> destination;
}

uint8_t Flight::getDepartureTime(){
    return this ->departureTime;
}

uint8_t Flight::getArrivalTime(){
    return this -> arrivalTime;
}

uint16_t Flight::getAvailableSeats(){
    return this -> availableSeats;
}

class Airline
{
private:
    vector <Flight> ListFlight;
    // vector <Booking> ListBooking;
public:
    Airline(/* args */);
    void addFlight();
    void removeFlight();
    void searchFlights();
    void getFlightDetails();
    void bookFlight();
    void cancelBooking();
    void viewBookings();
};

Airline::Airline(/* args */)
{
    uint8_t key;
    do
    {
        printf("MENU\n");
        printf("Press 1 to add a flight\n");
        printf("Press 2 to delete a flight\n");
        printf("Press 3 to search for a flight by destination\n");
        printf("Press 4 to search for a flight by ID\n");
        printf("Press 5 to book a flight ticket\n");
        printf("Press 6 to cancel a flight ticket\n");
        printf("Press 7 to see the list of flights\n");
        printf("Press 8 to exit the program\n");
        scanf("%hhd", &key);

        switch (key)
        {
            case ADD_FLIGHT:
                addFlight();
                break;
            case DEL_FLIGHT:
                removeFlight();
                break;
            case SEARCH_BY_DESTINATION:
                searchFlights();
                break;
            case SEARCH_BY_ID:
                getFlightDetails();
                break;
            case BOOK_TICKET:
                bookFlight();
                break;
            case CANCAL_TICKET:
                cancelBooking();
                break;
            case VIEW:
                viewBookings();
                break;                
            case EXIT:
                return;
                break;                                            
            default:
                printf("You have just entered %hhd\n. Please enter again\n", key);
                break;
        }
    } while (true);
}

void Airline::addFlight(){
    printf("-ADD_FLIGHT-\n");
    uint8_t key;
    char l_origin[40];
    char l_destination[40];
    uint8_t l_departureTime;
    uint8_t l_arrivalTime;
    uint16_t l_availableSeats;    
    do
    {
        printf("Enter the origin\n");
        scanf("%s", l_origin);
        printf("Enter the destination\n");
        scanf("%s", l_destination);        
        printf("Enter the departure time\n");
        scanf("%hhd", &l_departureTime);        
        printf("Enter the arrival time\n");
        scanf("%hhd", &l_arrivalTime);  
        printf("Enter the available seats\n");
        scanf("%hd", &l_availableSeats);  

        Flight flight(l_origin, l_destination, l_departureTime, l_arrivalTime, l_availableSeats);
        ListFlight.push_back(flight);

        viewBookings();

        printf("Press 1 to continue adding a flight\n");
        printf("Press 2 to exit\n");
        scanf("%hhd", &key);
    } while (key == 1);
}

void Airline::removeFlight(){
    printf("-DEL_FLIGHT-\n");
    uint8_t key;
    do
    {
        viewBookings();        
        uint8_t l_id;
        bool found = false;     

        printf("Enter the ID of the flight you want to delete: \n");
        scanf("%hhd", &l_id);

        for (uint8_t i = 0; i < ListFlight.size(); i++)
        {
            if(ListFlight[i].getIdFlight() == l_id){
                ListFlight.erase(ListFlight.begin() + i);
                found = true;
                break;
            }
        }   
        if(!found) printf("Could not find id %hhd", l_id);

        viewBookings();

        printf("Press 1 to continue removing a flight\n");
        printf("Press 2 to exit \n");
        scanf("%hhd", &key);
    } while (key == 1);    
}

void Airline::searchFlights(){
    printf("-SEARCH_BY_DESTINATION-\n");
    uint8_t key;
    do
    {
        viewBookings();        
        char l_destination[40];
        bool found = false;     

        printf("Enter the destination of the flight you want to delete: \n");
        scanf("%s", l_destination);

        for (uint8_t i = 0; i < ListFlight.size(); i++)
        {
            if(strcmp(ListFlight[i].getDestination(), l_destination)==0){                
                printf("THIS IS A FLIGHT WITH ID %hhd\n", ListFlight[i].getIdFlight());
                printf("THIS IS THE LIST OF CUSTOMERS\n");
                printf("No.\tID\tName\tSeat Number\n");
                for(uint8_t j = 0; j < ListFlight[i].ListBooking.size(); j++){
                    printf("%hhd\t%hhd\t%s\t%hd", j + 1, ListFlight[i].ListBooking[j].getIdBooking(), ListFlight[i].ListBooking[j].getCustomerName(), ListFlight[i].ListBooking[j].getSeatNumber());
                }
                found = true;
                break;
            }
        }   
        if(!found) printf("Could not find destination %s", l_destination);

        printf("Press 1 to continue searching by destination\n");
        printf("Press 2 to exit\n");
        scanf("%hhd", &key);
    } while (key == 1);    
}

void Airline::getFlightDetails(){
    printf("-SEARCH_BY_ID-\n");
    uint8_t key;
    do
    {
        viewBookings();        
        uint8_t l_id;
        bool found = false;     

        printf("Enter the ID of the flight you want to detail: \n");
        scanf("%hhd", &l_id);

        for (uint8_t i = 0; i < ListFlight.size(); i++)
        {
            if(ListFlight[i].getIdFlight() == l_id){
                printf("This is a flight to %s", ListFlight[i].getDestination());
                printf("THIS IS THE LIST OF CUSTOMERS\n");
                printf("No.\tID\tName\tSeat Number \n");
                for(uint8_t j = 0; j < ListFlight[i].ListBooking.size(); j++){
                    printf("%hhd\t%hhd\t%s\t%hd\n", j + 1, ListFlight[i].ListBooking[j].getIdBooking(), ListFlight[i].ListBooking[j].getCustomerName(), ListFlight[i].ListBooking[j].getSeatNumber());
                }
                found = true;
                break;
            }
        }   
        if(!found) printf("Could not find id %hhd", l_id);

        printf("Press 1 to continue searching by id\n");
        printf("Press 2 to exit\n");
        scanf("%hhd", &key);
    } while (key == 1);     
}

void Airline::bookFlight(){
    printf("-BOOK_TICKET-\n");
    uint8_t key;
    do
    {
        viewBookings();        
        uint8_t l_id;
        char name[20];
        uint16_t l_seatNumber;
        bool found = false;     
        bool check = false;
        printf("Enter the ID of the flight you want to detail: \n");
        scanf("%hhd", &l_id);

        for (uint8_t i = 0; i < ListFlight.size(); i++)
        {
            if(ListFlight[i].getIdFlight() == l_id){
                printf("Enter customer name: \n");
                scanf("%s", name);
                do
                {
                    printf("Enter seat number: \n");
                    scanf("%hd", &l_seatNumber);
                    if (l_seatNumber < ListFlight[i].getAvailableSeats())  {

                        check = true;
                        break;
                    }
                    else{
                        printf("Seat number must be less than %hd\n", ListFlight[i].getAvailableSeats());
                    }                    
                } while (!check);

                Booking listbooking(name, l_seatNumber);
                ListFlight[i].ListBooking.push_back(listbooking);
                //Phải thêm cái ghế đó nó bị chiếm ch, không cho đặt thêm
                ListFlight[i].setAvailableSeats(ListFlight[i].getAvailableSeats() - 1);     //Số ghế giảm đi một
                found = true;
                break;
            }
        }   
        if(!found) printf("Could not find id %hhd\n", l_id);

        printf("Press 1 to continue booking a ticket\n");
        printf("Press 2 to exit\n");
        scanf("%hhd", &key);
    } while (key == 1);     
}

void Airline::cancelBooking(){
    printf("-CANCEL_TICKET-\n");
    uint8_t key;
    do
    {
        viewBookings();        
        uint8_t l_id;
        uint8_t l_idBooking;
        bool found = false;       

        printf("Enter the ID of the flight you want to detail: \n");
        scanf("%hhd", &l_id);

        for (uint8_t i = 0; i < ListFlight.size(); i++)
        {
            //Tìm ID chuyến bay
            if(ListFlight[i].getIdFlight() == l_id){
                printf("Enter customer id booking: \n");
                scanf("%hhd", &l_idBooking);
                for (uint8_t j = 0; j < ListFlight[i].ListBooking.size(); j++){
                    //Tìm Id của khách hàng trong chuyến bay đó
                    if(ListFlight[i].ListBooking[j].getIdBooking() == l_idBooking){
                        //Xóa khách tại tại vị tri j của chuyến bay i
                        ListFlight[i].ListBooking.erase(ListFlight[i].ListBooking.begin() + j); 
                        ListFlight[i].setAvailableSeats(ListFlight[i].getAvailableSeats() + 1); //Trả lại một ghế
                        found = true;
                    }        
                }
            }
        }   
        if(!found) printf("Could not find id %hhd", l_id);

        for (uint8_t i = 0; i < ListFlight.size(); i++)
        {
            if(ListFlight[i].getIdFlight() == l_id){
                printf("This is a flight to %s", ListFlight[i].getDestination());
                printf("THIS IS THE LIST OF CUSTOMERS\n");
                printf("No.\tID\tName\tSeat Number \n");
                for(uint8_t j = 0; j < ListFlight[i].ListBooking.size(); j++){
                    printf("%hhd\t%hhd\t%s\t%hd\n", j + 1, ListFlight[i].ListBooking[j].getIdBooking(), ListFlight[i].ListBooking[j].getCustomerName(), ListFlight[i].ListBooking[j].getSeatNumber());
                }
            }
        } 

        printf("Press 1 to continue canceling a ticket\n");
        printf("Press 2 to exit\n");
        scanf("%hhd", &key);
    } while (key == 1);     
}

void Airline::viewBookings(){
    printf("-DISPLAY-\n");
    if (ListFlight.empty())
    {
        printf("List empty\n");
    }
    else{
        printf("STT\tID\torigin\tdestination\tdepartureTime\tarrivalTime\tavailableSeats\n");
        for (uint8_t i = 0; i < ListFlight.size(); i++)
        {
            printf("%hhd\t%hhd\t%s\t%s\t\t%hhd\t\t%hhd\t\t%hd\n", i+1, ListFlight[i].getIdFlight(), ListFlight[i].getOrigin(), ListFlight[i].getDestination(), ListFlight[i].getDepartureTime(), ListFlight[i].getArrivalTime(), ListFlight[i].getAvailableSeats());
        }
    }
}

int main(int argc, char const *argv[])
{
    Airline al;
    return 0;
}
//Vẫn còn trường hợp chọn 2 ghế trùng nhau được, thêm 1 biến bool là duoc