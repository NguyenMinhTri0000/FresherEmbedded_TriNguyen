#include <stdio.h>
#include <stdint.h>
#include <math.h>

class HinhChuNhat
{
private:
    uint8_t chieuDai;
    uint8_t chieuRong; 
public:
    HinhChuNhat(uint8_t cd = 0, uint8_t cr = 0);
    uint8_t getChieuDai();
    uint8_t getChieuRong();
    void setChieuDai(uint8_t cd);
    void setChieuRong(uint8_t cr);
};

HinhChuNhat::HinhChuNhat(uint8_t cd, uint8_t cr)
{
    chieuDai = cd;
    chieuRong = cr;
}

uint8_t HinhChuNhat::getChieuDai(){
    return this -> chieuDai;
}

uint8_t HinhChuNhat::getChieuRong(){
    return this -> chieuRong;
}

void HinhChuNhat::setChieuDai(uint8_t cd){
    chieuDai = cd;
}

void HinhChuNhat::setChieuRong(uint8_t cr){
    chieuRong = cr;
}

class PhuongThuc
{
private:
    HinhChuNhat hcn;
public:
    PhuongThuc();
    void chuVi();
    void dienTich();
    void duongCheo();
    void checkVuong();
};

PhuongThuc::PhuongThuc(){
    uint8_t check;
    NhapLai:
    do
    {
        uint8_t cr, cd;
        printf("Nhap vao hieu dai\n");
        scanf("%hhd", &cd);
        printf("Nhap vao hieu rong\n");
        scanf("%hhd", &cr);   
        hcn.setChieuDai(cd);
        hcn.setChieuRong(cr);
        if(cd>cr)   check = 1;
        else printf("Dai dai phai dai hon chieu rong\n");
    } while (!check);
    
    do
    {
        uint8_t key;
        printf("\n\n");
        printf("Nhan 1 De Tinh Chu Vi\n");
        printf("Nhan 2 de tinh dien tich\n");
        printf("Nhan 3 de tinh duong cheo\n");
        printf("Nhan 4 Kiem tra co phai hinh vuong\n");
        printf("Nhan 5 de nhap lai dai rong\n");
        printf("Nhan 6 de thoat\n");
        scanf("%hhd", &key);
        switch (key)
        {
        case 1:
            chuVi();
            break;
        case 2:
            dienTich();
            break;        
        case 3:
            duongCheo();
            break;             
        case 4:
            checkVuong();
            break;    
        case 5:
            goto NhapLai;
            break;     
        case 6:
            return;                              
        default:
            printf("Ban vua nhap %hhd. Vui long nhap lai:\n", key);
        }
    } while (true);
    
}

void PhuongThuc::chuVi(){
    printf("Chu Vi Hinh Chu Nhat: %hhd\n", (hcn.getChieuDai() + hcn.getChieuRong())*2);
}

void PhuongThuc::dienTich(){
    printf("Dien Tich Hinh Chu Nhat: %hhd\n", hcn.getChieuDai()*hcn.getChieuRong());
}

void PhuongThuc::duongCheo(){
    double DuongCheo = sqrt(hcn.getChieuDai()*hcn.getChieuDai() + hcn.getChieuRong()*hcn.getChieuRong());
    printf("Do Dai Duong Cheo: %lf\n", DuongCheo);
}

void PhuongThuc::checkVuong(){
    if(hcn.getChieuDai() == hcn.getChieuRong()){
        printf("Hinh Vuong\n");
    }
    else{
        printf("Khong phai hinh vuong\n");
    }
}

int main(int argc, char const *argv[])
{
    // HinhChuNhat hcn;
    // hcn.setChieuDai(3);
    // hcn.setChieuDai(4);    
    PhuongThuc pt;
    // pt.chuVi();
    return 0;
}
