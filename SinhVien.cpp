//Them check gioi tính
//Sửa hiển thị cho đẹp
//Xóa màn hình
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <stdlib.h>
#include <string.h>


using namespace std;

#define NHAP_DIEM(mon_hoc, diem)            \
    do                                      \
    {                                       \
        printf("Nhap Diem %s: ", mon_hoc);  \
        scanf("%lf", &sv.diem);             \
    } while (Check(sv.diem, mon_hoc) != 1);   

             
 
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

//Để ID tự động tăng
SinhVien::SinhVien(){
    static uint8_t id = 100; //0x01 = 100
    SinhVien::ID = id;
    id++;
}


class Menu{
    private:
        uint8_t Check(double diem, char* ten);
        // uint8_t Check_Gioi_Tinh(char* gioi_tinh);
        void NHAP_GIOI_TINH(char* gioi_tinh) ;
    public:
        Menu();
        vector<SinhVien> Database;
        void ThemSinhVien();
        void CapNhatThongTin();
        void XoaSinhVien();
        void TimKiemSinhVien();
        void HienThiDanhSach();
        void TimTheoTen();
        void SapXepTheoTen();
        void SapXepTheoGPA(); 
        void XuatFile();       

};

Menu::Menu(){

    int phim;
    menu:
    printf("Nhap chuong trinh ban muon\n");
    printf("Nhan 1: Them Sinh Vien\n");
    printf("Nhan 2: Chinh Sua Thong Tin Sinh Vien\n");
    printf("Nhan 3: Xoa Sinh Vien\n");        
    printf("Nhan 4: Tim Kiem Sinh Vien Theo Ten\n"); 
    printf("Nhan 5: Sap Xep Sinh Vien Theo GPA\n"); 
    printf("Nhan 6: Sap Xep Sinh Vien Theo Ten\n");       
    printf("Nhan 7: Hien Thi Danh Sach\n");   
    printf("Nhan 8: De thoat chuong trinh\n");  //thực tế khác từ 1 đến 8 là được

    scanf("%d", &phim);

    switch (phim)
    {
    case 1:
        ThemSinhVien:
        ThemSinhVien();
        printf("Nhan 1 Quay lai Menu: \n");
        printf("Nhan 2 Tiep tuc them sinh vien: \n");        
        scanf("%d", &phim);
        if (phim == 1)       goto menu;
        else if (phim == 2)  goto ThemSinhVien;
        break;
    case 2:
        CapNhatThongTin:
        CapNhatThongTin();
        printf("Nhan 1 Quay lai Menu: \n");
        printf("Nhan 2 Tiep tuc sửa thông tin sinh vien: \n");        
        scanf("%d", &phim);
        if (phim == 1)       goto menu;
        else if (phim == 2)  goto CapNhatThongTin;
        break;   
    case 3:
        XoaSinhVien:
        XoaSinhVien();
        printf("Nhan 1 Quay lai Menu: \n");
        printf("Nhan 2 Tiep tuc xoa sinh vien: \n");        
        scanf("%d", &phim);
        if (phim == 1)       goto menu;
        else if (phim == 2)  goto XoaSinhVien;
        break;  
    case 4:
        TimTheoTen:
        TimTheoTen();   
        printf("Nhan 1 Quay lai Menu: \n");
        printf("Nhan 2 Tiep tuc tim sinh vien theo ten: \n");        
        scanf("%d", &phim);
        if (phim == 1)       goto menu;
        else if (phim == 2)  goto TimTheoTen;
        break;       
    case 5:
        SapXepTheoGPA();
        printf("Nhan 1 Quay lai Menu: ");
        scanf("%d", &phim);
        goto menu;
        break;   
    case 6:
        SapXepTheoTen();
        printf("Nhan 1 Quay lai Menu: ");
        scanf("%d", &phim);
        goto menu;
        break;                           
    case 7:
        HienThiDanhSach();
        break;           
           
    default:  
    break;   
    }
}
uint8_t Menu::Check(double diem, char* ten)
{
    if(diem <= 10)   return 1;
    else{
        printf("Diem %f khong hop le: ", ten);
        return 0;
    }
}
// uint8_t Menu::Check_Gioi_Tinh(char* gioi_tinh)
// {
//     if((strcmp("gioi_tinh", "Nam") == 0)||(strcmp("gioi_tinh", "Nu") == 0))   return 1;
//     else{
//         printf("Gioi tinh %s khong hop le: ", gioi_tinh);
//         return 0;
//     }
// }

// void Menu::NHAP_GIOI_TINH(char* gioi_tinh)  
// {
//     do                                              
//     {                                               
//         printf("Nhap Gioi Tinh %s: ", gioi_tinh);   
//         scanf("%lf", &gioi_tinh);                
//     } while (Check_Gioi_Tinh(gioi_tinh) != 1);  
// }    

void Menu::ThemSinhVien(){
    SinhVien sv;
    printf("THEM SINH VIEN\n");
    printf("Nhap Ten: ");
    scanf("%s", sv.TEN);
    // NHAP_GIOI_TINH(sv.GIOI_TINH);
    printf("Gioi Tinh(Nam/Nu): ");
    scanf("%s", sv.GIOI_TINH);

    NHAP_DIEM("Toan", DIEM_TOAN)  ;
    NHAP_DIEM("Ly", DIEM_LY)  ;  
    NHAP_DIEM("Hoa", DIEM_HOA)  ;      

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

            NHAP_DIEM("Toan", DIEM_TOAN)  ;
            NHAP_DIEM("Ly", DIEM_LY)  ;  
            NHAP_DIEM("Hoa", DIEM_HOA)  ;  

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

//Tìm sinh viên theo tên và hiển thị thông tin của sinh viên đó
void Menu::TimTheoTen(){
    char name[20];
    printf("TIM VA HIEN THI THEO TEN SINH VIEN\n");
    printf("Nhap Vao Ten Sinh Vien: ");
    scanf("%s", &name);

    bool found = false;
    for (uint8_t i = 0; i < Database.size(); i++)
    {
        if (strcmp(Database[i].TEN,name)==0)
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

            found = true;
            break;
        }
    }

    if (!found)
    {
        printf("Khong tim thay sinh vien co ten la %d\n", name);
    }    
}

void Menu::SapXepTheoGPA(){
    printf("SAP XEP SINH VIEN THEO GPA TU THAP DEN CAO\n");
    SinhVien temp;
    for (uint8_t i = 0; i < Database.size() - 1; i++) {       
        for (uint8_t j = i + 1; j < Database.size(); j++) {
            if (Database[i].DIEM_TRUNG_BINH > Database[j].DIEM_TRUNG_BINH) {
                temp = Database[i];
                Database[i] = Database[j];
                Database[j] = temp;
                // swap(Database[i], Database[j + 1]);                
            }
        }
    } 
    HienThiDanhSach()   ;
}

void Menu::SapXepTheoTen(){
    printf("SAP XEP SINH VIEN THEO TEN\n");
    SinhVien temp;
    for (uint8_t i = 0; i < Database.size() - 1; i++) {       
        for (uint8_t j = i + 1; j < Database.size(); j++) {
            for(uint8_t k = 0; k<20; k++)
            {
                if (Database[i].TEN[k] > Database[j].TEN[k]) 
                {
                    temp = Database[i];
                    Database[i] = Database[j];
                    Database[j] = temp;
                    // swap(Database[i], Database[j + 1]); 
                    break;
                }               
            }
        }
    }  
    HienThiDanhSach()   ;     
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
void Menu::XuatFile(){
    printf("Chua lam\n");
}


int main(int argc, char const *argv[])
{
    Menu mn;
    return 0;
}
