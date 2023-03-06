#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <stdlib.h>
#include <string.h>

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
        Menu();
        vector<SinhVien> Database;
        void ThemSinhVien();
        void CapNhatThongTin();
        void XoaSinhVien();
        void TimKiemSinhVien();
        void HienThiDanhSach();
        void NhapDiem_TinhGPA();        
};

Menu::Menu(){

    int phim;
    menu:
    printf("Nhap chuong trinh ban muon\n");
    printf("Nhan 1: Them Sinh Vien\n");
    printf("Nhan 2: Chinh Sua Thong Tin Sinh Vien\n");
    printf("Nhan 3: Xoa Sinh Vien\n");        
    printf("Nhan 5: Hien Thi Danh Sach\n");
    printf("Nhan 6: De thoat chuong trinh\n");

    scanf("%d", &phim);

    switch (phim)
    {
    case 1:
        ThemSinhVien();
        printf("Nhan 1 Quay lai Menu: ");
        scanf("%d", &phim);
        goto menu;
        break;
    case 2:
        CapNhatThongTin();
        printf("Nhan 1 Quay lai Menu: ");
        scanf("%d", &phim);
        goto menu;
        break;   
    case 3:
        XoaSinhVien();
        printf("Nhan 1 Quay lai Menu: ");
        scanf("%d", &phim);
        goto menu;
        break;             
    case 5:
        HienThiDanhSach();
    default:
        break;
    }
}

void Menu::ThemSinhVien(){
    SinhVien sv;
    printf("THEM SINH VIEN\n");
    printf("Nhap Ten: ");
    scanf("%s", sv.TEN);
    printf("Gioi Tinh(Nam/Nu): ");
    scanf("%s", sv.GIOI_TINH);
    // printf("Tuoi: ");
    // scanf("%hhd", sv.TUOI);    

    //-----------------------

    printf("Nhap Diem Toan: ");
    scanf("%lf", &sv.DIEM_TOAN);
    printf("Nhap Diem Ly: ");
    scanf("%lf", &sv.DIEM_LY);
    printf("Nhap Diem Hoa: ");
    scanf("%lf", &sv.DIEM_HOA);

//------------------------
    //Tinh Diem Trung Binh

    sv.DIEM_TRUNG_BINH = (sv.DIEM_TOAN + sv.DIEM_HOA + sv.DIEM_LY)/3;


    //Tinh Hoc Luc

    if (sv.DIEM_TRUNG_BINH >= 8)
    {
        strcpy(sv.HOC_LUC, "GIOI");
    }else if(sv.DIEM_TRUNG_BINH >= 6.5){
        strcpy(sv.HOC_LUC, "KHA");
    }else if(sv.DIEM_TRUNG_BINH >= 5){
        strcpy(sv.HOC_LUC, "TRUNG BINH");
    }else{
        strcpy(sv.HOC_LUC, "YEU");
    }

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
            // printf("Tuoi: ");
            // scanf("%hhd", sv.TUOI);  

            printf("Nhap Diem Toan: ");
            scanf("%lf", &sv.DIEM_TOAN);
            printf("Nhap Diem Ly: ");
            scanf("%lf", &sv.DIEM_LY);
            printf("Nhap Diem Hoa: ");
            scanf("%lf", &sv.DIEM_HOA);

        //------------------------
            //Tinh Diem Trung Binh
            sv.DIEM_TRUNG_BINH = (sv.DIEM_TOAN + sv.DIEM_HOA + sv.DIEM_LY)/3;


            //Tinh Hoc Luc
            if (sv.DIEM_TRUNG_BINH >= 8)
            {
                strcpy(sv.HOC_LUC, "GIOI");
            }else if(sv.DIEM_TRUNG_BINH >= 6.5){
                strcpy(sv.HOC_LUC, "KHA");
            }else if(sv.DIEM_TRUNG_BINH >= 5){
                strcpy(sv.HOC_LUC, "TRUNG BINH");
            }else{
                strcpy(sv.HOC_LUC, "YEU");
            }
            
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

void Menu::HienThiDanhSach(){
    // system("clear");
    printf("HIEN THI THONG TIN SINH VIEN\n"); 
   for (uint8_t i = 0; i < Database.size(); i++)
   {
        printf("Sinh Vien %d:\n", i+1);
        printf("Ten Sinh Vien: %s\n", Database[i].TEN);
        // printf("Tuoi Sinh Vien: %hhd\n", Database[i].TUOI);        
        printf("Gioi Tinh: %s\n", Database[i].GIOI_TINH);

        printf("Diem Toan: %f\n", Database[i].DIEM_TOAN);
        printf("Diem Ly: %f\n", Database[i].DIEM_LY);
        printf("Diem Hoa: %f\n", Database[i].DIEM_HOA);    
        printf("Diem Trung Binh: %f\n", Database[i].DIEM_TRUNG_BINH);    
        printf("Hoc Luc: %s\n", Database[i].HOC_LUC);                             
   }
   
}



int main(int argc, char const *argv[])
{
    Menu mn;
    return 0;
}
