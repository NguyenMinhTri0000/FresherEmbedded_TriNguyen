#include <stdio.h>
#include <stdint.h>
#include <vector>
using namespace std;

typedef struct 
{
    uint8_t STT;
    uint8_t ID;
    char    TEN_MON[30];
    uint16_t GIA;
}Thuc_don;

typedef struct 
{
    Thuc_don THONG_TIN_MON;
    uint8_t SO_LUONG;
}so_luong_mon;

typedef struct 
{
    uint8_t SO_BAN;
    uint8_t TRANG_THAI;
    vector<so_luong_mon> DATA_MON;
}thong_tin_ban;

class QuanLy
{
    private:
        Thuc_don *ptr_thuc_don;
    public:
        QuanLy(vector<Thuc_don> Database_thuc_don);
        void ThemMon();
        void SuaMon();        
        void XoaMon();
        void HienThiDanhSach();        
};

class Menu{
    public:
        vector<Thuc_don> Database_thuc_don;
};

QuanLy::QuanLy(vector<Thuc_don> Database_thuc_don)
{
    ptr_thuc_don = Database_thuc_don;
}

void QuanLy::ThemMon()
{
    printf("THEM MON\n");
    scanf("%s", ptr_thuc_don->TEN_MON);
}
class NhanVien
{
    public:
        NhanVien(Thuc_don value, thong_tin_ban &value_thong_tin_ban);
        void GoiMon();
        void TinhTien();
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
