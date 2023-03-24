#include <stdio.h>
#include <stdint.h>

//Chương trình kiểm tra giá trị nhập vào có mấy chữ số(= count), trả về 10^(count)
uint32_t Check(uint32_t num)
{
    uint8_t count = 0;
    uint32_t SoChia = 1;
    while (num>=1)
    {
        count++;
        num = num/10;
    }
   
        for (uint8_t i = 0; i < count-1; i++)
        {
            SoChia = SoChia*10;
        }        
        return SoChia; 
}
//CHương trình chuyển số sang chữ từ 1 đến 9
void CTBienSoThanhChu(uint8_t num)
{
    switch (num)
    {              
    case 1:
        printf("MOT ");
            break;        
    case 2:
        printf("HAI ");
            break;        
    case 3:
        printf("BA ");
            break;        
    case 4:
        printf("BON ");
            break;            
    case 5:
        printf("NAM "); 
            break;               
    case 6:
        printf("SAU ");
            break;        
    case 7:
        printf("BAY ");
            break;        
    case 8:
        printf("TAM ");
            break;        
    case 9:
        printf("CHIN ");                              
        break;
    default: 
        break;
    }
}
//Chương trình đọc số
void DocSo(uint32_t num)
{
    for (uint32_t i = Check(num); i >= 1; i = i/10)
    {
        switch (i)
        {
        //HANG TRIEU
        case 1000000:
            if(num/i%10 != 0) 
            {
                CTBienSoThanhChu(num/i%10);
                printf("TRIEU\t");
            }
            break;
        //HANG TRAM NGAN
        case 100000:
            //KIỂM TRA NẾU HÀNG TRĂM NGÀN, CHỤC NGÀN, NGÀN ĐỀU BẰNG 0 THÌ BỎ QUA
            if((num/i%10 == 0)&&(num*10/i%10 == 0)&&(num*100/i%10 == 0)) continue;
            if(num/i%10 != 0) 
            {
                CTBienSoThanhChu(num/i%10);
                printf("TRAM ");
            }
            else printf("KHONG TRAM "); 
            break; 
        //HANG CHỤC NGAN
        case 10000:
            //KIỂM TRA NẾU HÀNG CHỤC NGÀN, NGÀN ĐỀU BẰNG 0 THÌ BỎ QUA 
            if((num/i%10 == 0)&&(num*10/i%10 == 0)) continue;            
            if(num/i%10 != 0) 
            {
                CTBienSoThanhChu(num/i%10);
                printf("MUOI ");
            }
            else printf("LE ");
            break; 
        //HANG NGAN
        case 1000:
            //KIỂM TRA NẾU HÀNG TRĂM NGÀN, CHỤC NGÀN, NGÀN ĐỀU BẰNG 0 THÌ BỎ QUA            
            if((num/i%10 == 0)&&(num/10/i%10 == 0)&&(num/100/i%10 == 0)) continue;            
            if(num/i%10 != 0) 
            {
                CTBienSoThanhChu(num/i%10);
                printf("NGAN \t");
            }
            else printf("NGAN \t"); 
            break; 
        //HANG TRAM 
        case 100:
            //KIỂM TRA NẾU HÀNG TRĂM NGÀN, CHỤC NGÀN, NGÀN ĐỀU BẰNG 0 THÌ BỎ QUA
            if((num/i%10 == 0)&&(num*10/i%10 == 0)&&(num*100/i%10 == 0)) continue;
            if(num/i%10 != 0) 
            {
                CTBienSoThanhChu(num/i%10);
                printf("TRAM ");
            }
            else printf("KHONG TRAM ");
            break;  
        //HANG CHUC 
        case 10:
            //KIỂM TRA NẾU HÀNG TRĂM NGÀN, CHỤC NGÀN, NGÀN ĐỀU BẰNG 0 THÌ BỎ QUA
            if((num/i%10 == 0)&&(num*10/i%10 == 0)) continue;              
            if(num/i%10 != 0) 
            {
                CTBienSoThanhChu(num/i%10);
                printf("MUOI ");
            }
            else printf("LE "); 
            break;  
        //HANG DƠN VỊ 
        case 1:
            //KIỂM TRA NẾU HÀNG TRĂM NGÀN, CHỤC NGÀN, NGÀN ĐỀU BẰNG 0 THÌ BỎ QUA
            if((num/i%10 == 0)&&(num/10/i%10 == 0)&&(num/100/i%10 == 0)) continue;            
            if(num/i%10 != 0) 
            {
                CTBienSoThanhChu(num/i%10);
            }
            break;                                                               
        default:
            break;
        }                           
    }
}

int main(int argc, char const *argv[])
{
    uint32_t a;
    do
    { 
        printf("NHAP VAO SO A IT HON 7 CHU SO: ");
        scanf ("%d",&a);
    } while (a>99999999);    
    DocSo(a);  
     
    return 0;
}
