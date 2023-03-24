
#include <stdio.h>
#include <stdint.h>

#define TRUE 1
#define FALSE 0

typedef uint8_t bool ;

typedef struct {
    uint8_t Ngay;
    uint8_t Thang;
    uint16_t Nam;
}   ThoiGian;

typedef enum {
     THU7 = 0,       
     CHUNHAT,
     THU2,
     THU3,
     THU4,     
     THU5, 
     THU6, 
} THU;

typedef enum {
    O365_NGAY = 365,
    O366_NGAY    
} NAM;

typedef enum {
     THANG1 = 1,
     THANG2,
     THANG3,
     THANG4,     
     THANG5, 
     THANG6, 
     THANG7,  
     THANG8,     
     THANG9, 
     THANG10, 
     THANG11,         
     THANG12     
} THANG;

typedef enum {
O1_NGAY = 1, 
O2_NGAY, 
O3_NGAY, 
O4_NGAY, 
O5_NGAY, 
O6_NGAY, 
O7_NGAY, 
O8_NGAY, 
O9_NGAY, 
O10_NGAY, 
O11_NGAY, 
O12_NGAY, 
O13_NGAY, 
O14_NGAY, 
O15_NGAY, 
O16_NGAY, 
O17_NGAY, 
O18_NGAY, 
O19_NGAY, 
O20_NGAY, 
O21_NGAY, 
O22_NGAY, 
O23_NGAY, 
O24_NGAY, 
O25_NGAY, 
O26_NGAY, 
O27_NGAY, 
O28_NGAY, 
O29_NGAY, 
O30_NGAY, 
O31_NGAY
} NGAY;

const ThoiGian ThoiGianGoc = {1, 1, 1};
const THU ThuGoc = THU2;

bool CheckNamNhuan( ThoiGian m)
{
    if(m.Nam%100 == 0)
    {
        if(m.Nam%400 == 0) return TRUE;
        else    return FALSE;
    }
    else
    {
        if(m.Nam%4 == 0) return TRUE;
        else    return FALSE;
    }
}

//return kiểu ngày, mà dùng uint8_t
//phải có comment
uint8_t SoNgayTrongThang(ThoiGian m)
{
    switch (m.Thang)
    {
    case THANG1:
    case THANG3:   
    case THANG5:       
    case THANG7:    
    case THANG8:
    case THANG10:   
    case THANG12:  
        return O31_NGAY;       
        break;
    case THANG2:
        if(CheckNamNhuan(m) == TRUE) return O29_NGAY;
        else return O28_NGAY;
        break;        
    default:
        return O30_NGAY;
        break;
    }
}

uint32_t TinhSoNgay(ThoiGian m)
{
    uint32_t SoNgay = 0;
    ThoiGian i;

    for( i.Nam = ThoiGianGoc.Nam; i.Nam <m.Nam; i.Nam++)
    {
        if(CheckNamNhuan(i) == TRUE)         SoNgay += O366_NGAY;
        else       SoNgay += O365_NGAY;
    }

    for( i.Thang = ThoiGianGoc.Thang; i.Thang<m.Thang; i.Thang++)
    {
        SoNgay += SoNgayTrongThang(i);
    }  

    SoNgay += m.Ngay - ThoiGianGoc.Ngay;

    return SoNgay;    
}

uint8_t TinhThu(ThoiGian m)
{
    THU ThuHomNay;
    ThuHomNay =  (ThuGoc +TinhSoNgay(m))%7;
    return ThuHomNay;
}
void HienThi(ThoiGian m)
{
    switch (TinhThu(m))
    {
    case 0:
        printf("THU 7");
        break;
    case 1:
        printf("CHU NHAT");
        break;    
    default:
        printf("THU %d", TinhThu(m));
        break;
    }
}
bool Check(ThoiGian m)
{
    if(m.Nam < 1) return FALSE;
    if((m.Thang<1)||(m.Thang>12)) return FALSE;


    switch (m.Thang)
    {
    case THANG1:
    case THANG3:   
    case THANG5:       
    case THANG7:    
    case THANG8:
    case THANG10:   
    case THANG12:
        if((m.Ngay<1)||(m.Ngay>31)) return FALSE;      
        break;
    case THANG2:
        if(CheckNamNhuan(m) == TRUE)     
        {
            if((m.Ngay<1)||(m.Ngay>29)) return FALSE; 
        }       
        else     
        {
            if((m.Ngay<1)||(m.Ngay>28)) return FALSE; 
        } 
        break;    
    default:
        if((m.Ngay<1)||(m.Ngay>30)) return FALSE;  
        break;
    }
        
    return TRUE;    
}
int main(int argc, char const *argv[])
{
    ThoiGian n;
    do
    {
        printf("NHAP VAO NGAY: ");
        scanf ("%d",&n.Ngay);
        printf("NHAP VAO THANG: ");
        scanf ("%d",&n.Thang);
        printf("NHAP VAO NAM: ");
        scanf ("%d",&n.Nam); 
    } while (!Check(n));

    HienThi(n);        
    return 0;
}
