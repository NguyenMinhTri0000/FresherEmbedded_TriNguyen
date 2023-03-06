#include <stdio.h>
#include <stdint.h>
#include <vector>

using namespace std;

class SinhVien{
    public:
        SinhVien();
        uint8_t ID;
        char TEN[20];
        char GIOI_TINH[4];
        uint8_t TUOI;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;
        double DIEM_TRUNG_BINH;
        char HOC_LUC[11];
};

SinhVien::SinhVien(){
    static uint8_t id = 100; //0x01 = 100
    SinhVien::ID = id;
    id++;
}


class Menu{
    public:
        vector<SinhVien> Database;
        void ThemSinhVien();
        void CapNhatThongTin();
        void XoaSinhVien();
        void TimKiemSinhVien();
        void HienThiDanhSach();
        void NhapDiem_TinhGPA();        
};

void Menu::ThemSinhVien(){
    SinhVien sv;// 0x08
    printf("THEM SINH VIEN\n");
    printf("Nhap Ten: ");
    scanf("%s", sv.TEN);
    printf("Gioi Tinh(Nam/Nu): ");
    scanf("%s", sv.GIOI_TINH);
    // printf("Tuoi: ");
    // scanf("%d", sv.TUOI);    

    Database.push_back(sv);
}

void Menu::CapNhatThongTin()
{
    uint8_t id;
    printf("CAP NHAT THONG TIN\n");
    printf("Nhap vao ID: ");
    scanf("%hhd", &id);

    bool found = false;
    for (uint8_t i = 0; i < Database.size(); i++)
    {
        if (Database[i].ID == id)
        {
            SinhVien sv = Database[i];
            printf("Nhap Ten: ");
            scanf("%s", sv.TEN);
            printf("Gioi Tinh(Nam/Nu): ");
            scanf("%s", sv.GIOI_TINH);
            printf("Tuoi: ");
            // scanf("%d", sv.TUOI);              
            // Database[i] = sv;
            found = true;
            break;
        }
    }

    if (!found)
    {
        printf("Khong tim thay sinh vien co ID la %d\n", id);
    }
}

void Menu::XoaSinhVien()
{
    uint8_t id;
    printf("XOA SINH VIEN\n");
    printf("Nhap vao ID: ");
    scanf("%hhd", &id);

    bool found = false;
    for (uint8_t i = 0; i < Database.size(); i++)
    {
        if (Database[i].ID == id)
        {
            SinhVien sv = Database[i];
            Database.erase(Database.begin()+i);
            found = true;
            break;
        }
    }

    if (!found)
    {
        printf("Khong tim thay sinh vien co ID la %d\n", id);
    }
}
void Menu::NhapDiem_TinhGPA()
{
    uint8_t id;
    printf("CAP NHAT DIEM SO\n");
    printf("Nhap vao ID: ");
    scanf("%hhd", &id);

    bool found = false;
    for (uint8_t i = 0; i < Database.size(); i++)
    {
        if (Database[i].ID == id)
        {
            SinhVien sv = Database[i];
            printf("Diem Toan: ");
            scanf("%s", &sv.DIEM_TOAN);
            printf("Diem Ly: ");
            scanf("%s", &sv.DIEM_LY);
            printf("Diem Hoa: ");       //sao nó chạy tới điểm hóa thì bị lỗi
            scanf("%s", &sv.DIEM_HOA);   

            sv.DIEM_TRUNG_BINH = (sv.DIEM_HOA + sv.DIEM_HOA + sv.DIEM_LY)/3;
            // if(sv.DIEM_TRUNG_BINH >= 8)     {
            //     sv.HOC_LUC = "Gioi";
            // }
            // else if(sv.DIEM_TRUNG_BINH >= 6.5)
            // {
            //     sv.HOC_LUC = "Kha";
            // }
            // else if(sv.DIEM_TRUNG_BINH >= 5)
            // {
            //     sv.HOC_LUC = "Trung Binh"; 
            // }
            // else                 sv.HOC_LUC = "Yeu"; 


            Database[i] = sv;
            found = true;
            break;
        }
    }

    if (!found)
    {
        printf("Khong tim thay sinh vien co ID la %d\n", id);
    }
}
void Menu::HienThiDanhSach(){
   for (uint8_t i = 0; i < Database.size(); i++)
   {
        printf("HIEN THI\n");       
        printf("Ten Sinh Vien: %s\n", Database[i].TEN);
        printf("Gioi Tinh: %s\n", Database[i].GIOI_TINH);
        // printf("Tuoi: %d\n", Database[i].TUOI);    

        printf("Diem Toan: %f\n", Database[i].DIEM_TOAN);
        printf("Diem Ly: %f\n", Database[i].DIEM_LY);
        printf("Diem Hoa: %f\n", Database[i].DIEM_HOA);    
        printf("Diem Trung Binh: %s\n", Database[i].DIEM_TRUNG_BINH);    
        printf("Hoc Luc: %s\n", Database[i].HOC_LUC);                             
   }
   
}



int main(int argc, char const *argv[])
{
   Menu mn;

   mn.ThemSinhVien();
   mn.ThemSinhVien();
   mn.CapNhatThongTin();

   mn.XoaSinhVien();
//    mn.NhapDiem_TinhGPA();
   mn.HienThiDanhSach();


    return 0;
}
