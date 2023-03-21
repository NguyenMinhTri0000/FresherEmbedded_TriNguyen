#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <string.h>

using namespace std;

class DienThoai{
    private:
        char tenDienThoai[20];
        char hangXuanXuat[20];
        double gia;
        uint8_t id;
    public:
        DienThoai();
        char *getTenDienThoai();
        char *getHangDienThoai();    
        double getGia();

        void setTenDienThoai(char ten[]);
        void setHangDienThoai(char hang[]);
        void setGia(double gia); 
};

class QuanLyDienThoai{
    private:
        vector<DienThoai>danhsachDienThoai;
    public:
        void ThemDienThoai(DienThoai &dt);
        void SuaDienThoai(uint8_t id);
        void XoaDienThoai(uint8_t id);
        void HienThiDanhSach();
};

class Smartphone:public DienThoai{
    private:
        uint16_t dungLuongPin;
        uint8_t dungLuongBoNho;
    public:
        Smartphone();
        uint16_t getDungLuongPin();
        uint8_t getDungLuongBoNho();
        void setDungLuongPin(uint16_t dung_luong_pin);
        void setDungLuongBoNho(uint8_t dung_luong_bo_nho);
};
    DienThoai::DienThoai()
    {
        printf("DAY LA TRANG QUAN LY DIEN THOAI\n");
    }
    void QuanLyDienThoai::ThemDienThoai(DienThoai &dt)
    {

    }
    void QuanLyDienThoai::SuaDienThoai(uint8_t ID)
    {

    }
    void QuanLyDienThoai::XoaDienThoai(uint8_t ID)
    {
        // bool found = false;
        // for (uint8_t i = 0; i < danhsachDienThoai.size(); i++)
        // {
        //     if (danhsachDienThoai[i]. == ID)
        //     {
        //         SinhVien sv = Database[i];
        //         Database.erase(Database.begin()+i);
        //         found = true;
        //         break;
        //     }
        // }

        // if (!found)
        // {
        //     printf("Khong tim thay sinh vien co ID la %d\n", id);
        // }
    }    
    void QuanLyDienThoai::HienThiDanhSach()
    {

    }  
    void DienThoai::setTenDienThoai(char ten[]) {
        strcpy(tenDienThoai, ten);
    }
    void DienThoai::setHangDienThoai(char ten[]) {
        strcpy(hangXuanXuat, ten);
    }    
    void DienThoai::setGia(double gia)
    {
        DienThoai dt;
        dt.gia = gia;
    }
    void Smartphone::setDungLuongPin(uint16_t pin)
    {
        Smartphone sp;
        sp.dungLuongPin = pin;
    }
    void Smartphone::setDungLuongBoNho(uint8_t bonho)
    {
        Smartphone sp;
        sp.dungLuongBoNho = bonho;
    }

    char *DienThoai::getTenDienThoai() {
        return tenDienThoai;
    }
    char *DienThoai::getHangDienThoai() {
        return hangXuanXuat;
    }   
    double DienThoai::getGia() {
        return gia;
    }  
    uint16_t Smartphone::getDungLuongPin(){
        return dungLuongPin;
    }      
    uint8_t Smartphone::getDungLuongBoNho(){
        return dungLuongBoNho;
    }   

int main(int argc, char const *argv[])
{
    // QuanLyDienThoai ql;

    // DienThoai dt;
    // uint8_t phim;
    // menu:
    // printf("Nhap chuong trinh ban muon\n");
    // printf("Nhan 1: Them Dien Thoai\n");
    // printf("Nhan 2: Chinh Sua Thong Tin Dien Thoai\n");
    // printf("Nhan 3: Xoa Dien Thoai\n");            
    // printf("Nhan 4: Hien Thi Danh Sach\n");   

    // scanf("%d", &phim);

    // switch (phim)
    // {
    // case 1:
    //     ThemDienThoai:
    //     ThemDienThoai(dt);
    //     printf("Nhan 1 Quay lai Menu \n");
    //     printf("Nhan 2 Tiep tuc them sinh vien \n");        
    //     scanf("%d", &phim);
    //     switch (phim)
    //     {
    //         case 1:
    //             goto menu;
    //             break;
    //         case 2:
    //             goto ThemDienThoai;
    //             break;                
    //         default:
    //             break;
    //     }
    // case 2:
    //     SuaDienThoai:
    //     uint8_t id_nhap;
    //     printf("Nhap vao ID dien thoai muon sua: ");
    //     scanf("%d", &id_nhap);
    //     SuaDienThoai(id_nhap);
    //     printf("Nhan 1 Quay lai Menu \n");
    //     printf("Nhan 2 Tiep tuc sửa thông tin sinh vien \n");  
    //     printf("Nhan 3 De hien thi thong tin sinh vien\n");              
    //     scanf("%d", &phim);
    //     switch (phim)
    //     {
    //         case 1:
    //             goto menu;
    //             break;
    //         case 2:
    //             goto SuaDienThoai;
    //             break;                  
    //         default:
    //             break;
    //     }
    //     break;   
        
    // case 3:
    //     XoaDienThoai:
    //     printf("Nhap vao ID dien thoai muon xoa: ");
    //     scanf("%d", &id_nhap);        
    //     XoaDienThoai(id_nhap);
    //     printf("Nhan 1 Quay lai Menu \n");
    //     printf("Nhan 2 Tiep tuc xoa sinh vien \n"); 
    //     printf("Nhan 3 De hien thi thong tin sinh vien\n");               
    //     scanf("%d", &phim);
    //     switch (phim)
    //     {
    //         case 1:
    //             goto menu;
    //             break;
    //         case 2:
    //             goto XoaDienThoai;
    //             break;                  
    //         default:
    //             break;
    //     }
    //     break;  
    // case 4:
    //     HienThiDanhSach();  
    //     printf("Nhan 1 Quay lai Menu: ");
    //     scanf("%d", &phim);
    //     goto menu;            
    //     break;           
           
    // default:  
    // break;   
    // }
    DienThoai dt;

    return 0;
}
