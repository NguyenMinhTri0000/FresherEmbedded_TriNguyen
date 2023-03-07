#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



//Tính độ dài chuõi
uint8_t SizeChuoi(char* str)
{
    uint8_t i = 0;
    while (str[i]!='\0') i++;
    // printf("Tong chuoi: %d", i);
    return i;
}

//Chèn thêm một dấu cách ở cuối chuỗi. Mục đích tách các chữ ra dựa vào dấu cách
char* insertChar(char *str) {
    uint8_t len = SizeChuoi(str); // tính độ dài chuỗi ban đầu    
    char *new_string = (char*) malloc((len + 2) * sizeof(char));   

    for(uint8_t i = 0; i < len ; i++)
    {
        new_string[i] = str[i];
    }     
    new_string[len] = ' ';
    new_string[len + 1] = '\0';
    // printf("%d\n", SizeChuoi(str));
    // printf("%d\n", SizeChuoi(new_string));
    return new_string;
}

//Chương trình xác định số dấu cách có trong chuỗi
uint8_t SoDauCach(char* str)
{
    uint8_t j = 0;
    for (uint8_t i = 0; i < SizeChuoi(str); i++)
    {
        if(str[i] == 32)    j++;        //32 là dấu cách
    }

    // printf("So dau cach: %d", j);
    return j;
}

//Chương trình tạo ra chuỗi đảo ngược 
char* Dao_Ca_Chuoi(char *str) {
    uint8_t  len = SizeChuoi(str);
    char* new_str = (char*) malloc((len + 1) * sizeof(char));  // cấp phát vùng nhớ mới
    for(uint8_t i = 0; i < len; i++)
    {
        new_str[i] = str[len - i - 1]; // sao chép ký tự theo thứ tự đảo ngược vào vùng nhớ mới
    }
    new_str[len] = '\0'; // thêm ký tự kết thúc chuỗi
    return new_str;
}

char* Dao_Chuoi(char *str) {
    uint8_t  len = SizeChuoi(str);
    char* new_str = (char*) malloc((len + 1) * sizeof(char));
      // cấp phát vùng nhớ mới
    uint8_t size_word = 0;
    uint8_t First_Add = 0;

    for(uint8_t count = 0; count < SoDauCach(str); count++)
    {
        while (str[size_word + First_Add] != ' ')
        {
            size_word++;
        }
        //---------------------------
        for(uint8_t i = 0; i <  size_word; i++)
        {
            new_str[First_Add+i] = str[First_Add + size_word - i - 1]; // sao chép ký tự theo thứ tự đảo ngược vào vùng nhớ mới
        }

        new_str[First_Add + size_word] = ' ';        
        First_Add = First_Add + size_word + 1;  //1 là thêm dấu cách
        size_word = 0;
    }
    new_str[len] = '\0'; // thêm ký tự kết thúc chuỗi
    return new_str;
}

void HienThiChuoi(char *str)
{
    printf("%s\n",str);
}


int main() {
    char my_string[] = "Families of newborn patients at a Nebraska hospital received special hand-knitted hats this weekend. February 14, 2023";    
    char* new_str = Dao_Ca_Chuoi(my_string);  //thêm vào chuỗi một dấu cách ở cuối cùng
    char* chuoidao =    insertChar(new_str);    
    char* chuoidao1 =    Dao_Chuoi(chuoidao); 
    HienThiChuoi(chuoidao1);


    return 0;
}

