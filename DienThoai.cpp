#include <stdio.h>
#include <vector>
#include <stdint.h>

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
        void ThemDienThoai(DienThoai &dt);
        void SuaDienThoai(uint8_t id);
        void XoaDienThoai(uint8_t id);
        void HienThi();
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
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
