#include <stdio.h>
#include <math.h>

class HinhTron
{
private:
    double banKinh;
public:
    HinhTron(double bk = 0);
    double getBanKinh();
    void setBanKinh(double bk);
};

HinhTron::HinhTron(double bk)
{
    banKinh = bk;
}

double HinhTron::getBanKinh()
{
    return banKinh;
}

void HinhTron::setBanKinh(double bk)
{
    banKinh = bk;
}

class PhuongThuc
{
private:
    HinhTron ht;
public:
    PhuongThuc();
    void chuVi();
    void dienTich();
};

PhuongThuc::PhuongThuc()
{
    double bk;
    SuaBanKinh:
    printf("Nhap vao ban kinh\n");
    scanf("%lf", &bk);
    ht.setBanKinh(bk);
    
    do
    {
        int key;
        printf("\n\n");
        printf("Nhan 1 De Tinh Chu Vi\n");
        printf("Nhan 2 de tinh dien tich\n");
        printf("Nhan 3 de sua ban kinh\n");
        printf("Nhan 4 de thoat\n");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            chuVi();
            break;
        case 2:
            dienTich();
            break;    
        case 3:
            goto SuaBanKinh;
            break;                        
        case 4:
            return;
        default:
            printf("Ban vua nhap %d. Vui long nhap lai:\n", key);
        }
    } while (true);
}

void PhuongThuc::chuVi()
{
    printf("Chu Vi Hinh Tron: %lf\n", 2 * M_PI * ht.getBanKinh());      //M_PI trong thư viện math là số pi
}

void PhuongThuc::dienTich()
{
    printf("Dien Tich Hinh Tron: %lf\n", M_PI * ht.getBanKinh() * ht.getBanKinh());
}

int main()
{
    PhuongThuc pt;
    return 0;
}
