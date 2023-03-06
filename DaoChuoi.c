#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    uint8_t size[10];   //một chữ không nhiều hơn 10 kí tự
    uint8_t ViTri[100];
}Typearray;

//Tính độ dài chuõi
uint8_t SizeChuoi(char* str)
{
    uint8_t i = 0;
    while (str[i]!='\0') i++;
    // printf("Tong chuoi: %d", i);
    return i;
}

//Chèn thêm một dấu cách ở cuối chuỗi. Mục đích tách các chữ ra dựa vào dấu cách
void insertChar(char *str) {    
    char ch = ' ';
    uint8_t pos = SizeChuoi(str);  // vị trí cần chèn ký tự vào       
    // chèn ký tự mới vào vị trí cần chèn
    str[pos] = ch;
}

//Chương trình xác định số dấu cách có trong chuỗi
uint8_t SoDauCach(char* str)
{
    uint8_t j = 0;
    for (uint8_t i = 0; i < SizeChuoi(str); i++)
    {
        if(str[i] == 32)    j++;
    }

    // printf("So dau cach: %d", j);
    return j;
}

//Chương trình đảo chuỗi
void Dao_Chuoi(char *str) {
    Typearray arr;
    arr.size[0] = 0;
    arr.ViTri[0] = 0;

    for(uint8_t i = 0; i <= SoDauCach(str); i++)    //Số dấu cách tương đương với số chữ trong chuỗi
    {
        for(uint8_t j = arr.ViTri[i]; j < SizeChuoi(str); j++)
        {
            if((str[j] == 32)) //32 <=> 0x20 : dấu cách
            // if((str[j] == '\0')||(str[j] == 32))
            {
                arr.size[i] = j;
                break;
            }
        }
        arr.ViTri[i+1] = arr.size[i] + 1;   //cộng 1 là do có thêm dấu cách
    }
    
    //In ra màn hình theo hướng ngược lại
    for(int8_t i = SoDauCach(str); i >= 0; i--)
    {
        for(uint8_t k = 0 ; k<SizeChuoi (str); k++)        
        {
            if(k == arr.size[i])
            {
                for(uint8_t m = arr.ViTri[i]; m < arr.size[i]; m ++)
                {
                    printf("%c",str[m]);
                }
            }
        }
        printf(" ");    //dấu cách giữa các chữ
    }
    printf("\n");

    //In Hoa Chữ Cái Đầu
    for(int8_t i = SoDauCach(str); i >= 0; i--)
    {
        for(uint8_t k = 0 ; k<SizeChuoi (str); k++)        
        {
            if(k == arr.size[i])
            {
                // printf("%c",str[arr.ViTri[i]]);
                for(uint8_t m = arr.ViTri[i] ; m < arr.size[i]; m ++)
                {
                    if((str[m]>=97)&&(str[m]<=122))     //cái chữ đó viết thường, viết hoa bỏ qua
                    {
                        if(m == arr.ViTri[i])   //Kí tự đầu 
                        {
                            printf("%c",str[m]-32);
                        }
                        else
                        {
                            printf("%c",str[m]);                            
                        }
                    }
                    else  if((str[m]>=65)&&(str[m]<=90)) //Các kí tự sau mà viết hoa cho nó về thường
                    {
                        if(m != arr.ViTri[i])   //Khác kí tự đầu 
                        {
                            printf("%c",str[m]+32);
                        }
                        else
                        {
                            printf("%c",str[m]);                            
                        }
                    }
                }
            }
        }
        printf(" ");    //dấu cách giữa các chữ
    }
    printf("\n");

    //IN HOA
    for(int8_t i = SoDauCach(str); i >= 0; i--)
    {
        for(uint8_t k = 0 ; k<SizeChuoi (str); k++)        
        {
            if(k == arr.size[i])
            {
                // printf("%c",str[arr.ViTri[i]]);
                for(uint8_t m = arr.ViTri[i] ; m < arr.size[i]; m ++)
                {
                    if((str[m]>=97)&&(str[m]<=122))     //cái chữ đó viết thường/ viết hoa bỏ qua
                    {
                        printf("%c",str[m]-32);
                    }
                    else
                    {
                        printf("%c",str[m]);
                    }
                }
            }
        }
        printf(" ");    //dấu cách giữa các chữ
    }    

    printf("\n");
    //viết thường
    for(int8_t i = SoDauCach(str); i >= 0; i--)
    {
        for(uint8_t k = 0 ; k<SizeChuoi (str); k++)        
        {
            if(k == arr.size[i])
            {
                // printf("%c",str[arr.ViTri[i]]);
                for(uint8_t m = arr.ViTri[i] ; m < arr.size[i]; m ++)
                {
                    if((str[m]>=65)&&(str[m]<=90))     //cái chữ đó viết hoa/ viết thường bỏ qua
                    {
                        printf("%c",str[m]+32);
                    }
                    else
                    {
                        printf("%c",str[m]);
                    }
                }
            }
        }
        printf(" ");    //dấu cách giữa các chữ
    }      
}

int main() {
    char my_string[] = "Mot hai ba Bon NAM sAu";    
    insertChar(my_string);  //thêm vào chuỗi một dấu cách ở cuối cùng
    Dao_Chuoi(my_string);
    //Tại sao chuỗi my_string không đổi, đã truyền vào con trỏ rồi mà
    // printf("%s", my_string);
    return 0;
}

