//còn sái xóa đt,... 
#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <string.h>

using namespace std;
typedef enum{
    ADD = 1,
    DEL,
    EDIT,
    SHOW,
} CHOICE;

class DienThoai{
    private:
        char tenDienThoai[20];
        char hangSanXuat[20];
        double giaDienThoai;
        uint8_t id;
    public:
        DienThoai(char ten[], char hang[], double gia);
        uint8_t getId();
        char *getTenDienThoai();
        char *getHangDienThoai();    
        double getGia();

        void setTenDienThoai(char ten[]);
        void setHangDienThoai(char hang[]);
        void setGia(double gia); 
};

DienThoai::DienThoai(char ten[], char hang[], double gia)
{
    static uint8_t l_id = 100;
    id = l_id;
    l_id++;
    strcpy(tenDienThoai, ten);
    strcpy(hangSanXuat, hang);
    giaDienThoai = gia;
}

uint8_t DienThoai::getId()
{
    return this->id;
}

char *DienThoai::getTenDienThoai() {
    return tenDienThoai;
}
char *DienThoai::getHangDienThoai() {
    return hangSanXuat;
}  

double DienThoai::getGia() {
    return giaDienThoai;
} 

void DienThoai::setTenDienThoai(char ten[]) {
    strcpy(tenDienThoai, ten);
}

void DienThoai::setHangDienThoai(char hang[]) {
    strcpy(hangSanXuat, hang);
}    

void DienThoai::setGia(double gia)
{
    giaDienThoai = gia;
}


class QuanLyDienThoai{
    private:
        vector<DienThoai>danhSachDienThoai;
        // uint8_t kiemTraId(uint8_t l_id);
    public:
        QuanLyDienThoai();
        void themDienThoai();
        void suaDienThoai();
        void xoaDienThoai();
        void hienThiDanhSach();
};

QuanLyDienThoai::QuanLyDienThoai()
{
    while (true)
    {
        uint8_t choice;
        printf("1. Them dien thoai\n");
        printf("2. Xoa Dien Thoai\n");
        printf("3. Sua Dien Thoai\n");
        printf("4. Hien Thi Dien Thoai\n");
        scanf("%hhu", &choice);
        
        switch (choice)
        {
        case ADD:
            printf("---------Add\n");
            themDienThoai();
            break;
        case DEL:
            printf("---------Del\n");
            xoaDienThoai();
            break;
        case EDIT:
            printf("---------Edit\n");
            suaDienThoai();
            break;
        case SHOW:
            printf("---------Show\n");
            hienThiDanhSach();
            break;
        default:
            printf("Your choice: %hhu", choice);
            printf("Invalid input, please try again.\n");
            continue;
        }
    }    
}
// uint8_t QuanLyDienThoai::kiemTraId(uint8_t l_id)
// {
//     for(uint8_t i = 0; i <  danhSachDienThoai.size(); i++)
//     {
//         if(l_id == danhSachDienThoai[i].getId())
//         {
//             return 1;
//         }
//     }
//     printf("Khong tim thay ID");    
//     return 0;
// }

    void QuanLyDienThoai::themDienThoai()
    {
        char l_ten[20];
        char l_hang[20];
        double l_gia;
        uint8_t key;
        do
        {
            printf("THEM DiEN THOAI\n");
            printf("Nhap Ten Dien Thoai: ");
            scanf("%s", l_ten);
            printf("Nhap Hang Dien Thoai: ");
            scanf("%s", l_hang);        
            printf("Nhap Gia: ");    
            scanf("%lf", &l_gia);
            DienThoai dt(l_ten, l_hang, l_gia);
            danhSachDienThoai.push_back(dt);
            printf("Nhan 1 de them dt: ");
            printf("Nhan 2 de thoat: ");
            scanf("%hhu", &key);
        } while (key == 1);
    }
void QuanLyDienThoai::xoaDienThoai()
{
    if(danhSachDienThoai.empty())
    {
        printf("Danh sach dien thoai rong.\n");
        return;
    }

    uint8_t key;
    do
    {
        hienThiDanhSach();
        uint8_t inID;
        printf("Nhap vao ID: ");
        scanf("%u", &inID);
        for(uint8_t i = 0; i <  danhSachDienThoai.size(); i++)
        {     
            if(inID == danhSachDienThoai[i].getId())
            {
                danhSachDienThoai.erase(danhSachDienThoai.begin() + i);
                printf("Da xoa dien thoai co ID %u.\n", inID);
                i--; // Giảm biến đếm i đi 1 sau khi xóa phần tử hiện tại.
                break;
            }
        }
        printf("Nhan 1 de xoa tiep? ");
        scanf("%hhu", &key);
    } while(key == 1);
}

void QuanLyDienThoai::suaDienThoai()
{
    hienThiDanhSach();
    uint8_t key;
    uint8_t inID;
    printf("Nhap vao ID: ");
    scanf("%u", &inID);

    do
    {
        for(uint8_t i = 0; i <  danhSachDienThoai.size(); i++)
        {

            if(inID == danhSachDienThoai[i].getId())
            {
                    printf("1. Edit name\n");
                    printf("2. Edit manufacturer\n");
                    printf("3. Edit price\n");
                    scanf("%hhu", &key);
                    switch (key)
                    {
                        case 1:
                            char tempName[20];
                            printf("Ten moi: ");
                            scanf("%s", tempName);
                            danhSachDienThoai[i].setTenDienThoai(tempName);
                            break;
                        case 2: 
                            char tempHang[20];
                            printf("Nhap ten hang: ");
                            scanf("%s", tempHang);
                            danhSachDienThoai[i].setHangDienThoai(tempHang); 
                            break; 
                        case 3: 
                            double tempGia;
                            printf("Nhap gia: ");
                            scanf("%lf", &tempGia);
                            danhSachDienThoai[i].setGia(tempGia);
                            break;                                                   
                        default:
                            break;
                    }
                    break;
            }
        }

        printf("Nhan 1 de tiep tuc sua dien thoai");
        scanf("%hhu",&key);
    } while(key == 1);
}

void QuanLyDienThoai::hienThiDanhSach()
{
    // system("cls");
    if(danhSachDienThoai.empty())
    {
        printf("Empty list.\n");
    }
    else
    {
        for(uint8_t i = 0; i < danhSachDienThoai.size(); i++)
        {
            printf("%hhu \t%s\t %s\t %lf\n",danhSachDienThoai[i].getId(), danhSachDienThoai[i].getTenDienThoai(), danhSachDienThoai[i].getHangDienThoai(), danhSachDienThoai[i].getGia());
        }
    }
}

// class Smartphone:public DienThoai{
//     private:
//         uint16_t dungLuongPin;
//         uint8_t dungLuongBoNho;
//     public:
//         Smartphone();
//         uint16_t getDungLuongPin();
//         uint8_t getDungLuongBoNho();
//         void setDungLuongPin(uint16_t dung_luong_pin);
//         void setDungLuongBoNho(uint8_t dung_luong_bo_nho);
// };




//     void Smartphone::setDungLuongPin(uint16_t pin)
//     {
//         Smartphone sp;
//         sp.dungLuongPin = pin;
//     }
//     void Smartphone::setDungLuongBoNho(uint8_t bonho)
//     {
//         Smartphone sp;
//         sp.dungLuongBoNho = bonho;
//     }

 
//     uint16_t Smartphone::getDungLuongPin(){
//         return dungLuongPin;
//     }      
//     uint8_t Smartphone::getDungLuongBoNho(){
//         return dungLuongBoNho;
    // }   

int main(int argc, char const *argv[])
{
    QuanLyDienThoai ql;
    return 0;
}
