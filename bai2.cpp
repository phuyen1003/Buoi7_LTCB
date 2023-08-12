#include <iostream>
#include <string>

using namespace std;

struct SinhVien {
    string hoTen;
    string phai;
    double diemTB;
};

void nhapSinhVien(SinhVien &sv) {
    cin.ignore(); // Xóa ký tự dòng mới còn lại trong bộ đệm đầu vào
    cout << "Nhap ho ten: ";
    getline(cin, sv.hoTen);
    cout << "Nhap phai: ";
    cin >> sv.phai;
    cout << "Nhap diem TB: ";
    cin >> sv.diemTB;
}

void xuatSinhVien(const SinhVien &sv) {
    cout << "Ho ten: " << sv.hoTen << endl;
    cout << "Phai: " << sv.phai << endl;
    cout << "Diem TB: " << sv.diemTB << endl;
}

void sapXepTheoHoTen(SinhVien danhSachSinhVien[], int soLuongSinhVien) {
    for (int i = 0; i < soLuongSinhVien - 1; ++i) {
        for (int j = i + 1; j < soLuongSinhVien; ++j) {
            if (danhSachSinhVien[i].hoTen > danhSachSinhVien[j].hoTen) {
                swap(danhSachSinhVien[i], danhSachSinhVien[j]);
            }
        }
    }
}

int main() {
    const int MAX_SINHVIEN = 100;
    SinhVien danhSachSinhVien[MAX_SINHVIEN];
    int soLuongSinhVien;

    cout << "Nhap so luong sinh vien: ";
    cin >> soLuongSinhVien;

    for (int i = 0; i < soLuongSinhVien; ++i) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        nhapSinhVien(danhSachSinhVien[i]);
        cout << "--------------------" << endl;
    }

    sapXepTheoHoTen(danhSachSinhVien, soLuongSinhVien);

    cout << "\nDanh sach sinh vien sau khi sap xep theo ho ten tang dan:" << endl;
    for (int i = 0; i < soLuongSinhVien; ++i) {
        xuatSinhVien(danhSachSinhVien[i]);
        cout << "--------------------" << endl;
    }

    return 0;
}
