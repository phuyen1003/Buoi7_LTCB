#include <iostream>
#include <string>

using namespace std;

struct Tinh {
    int maTinh;
    string tenTinh;
    int danSo;
    double dienTich;
};

void nhapTinh(Tinh &tinh) {
    cout << "Nhap ma tinh: ";
    cin >> tinh.maTinh;
    cin.ignore(); //  Xóa ký tự dòng mới còn lại trong bộ đệm đầu vào
    cout << "Nhap ten tinh: ";
    getline(cin, tinh.tenTinh);
    cout << "Nhap dan so: ";
    cin >> tinh.danSo;
    cout << "Nhap dien tich: ";
    cin >> tinh.dienTich;
}

void xuatTinh(const Tinh &tinh) {
    cout << "Ma tinh: " << tinh.maTinh << endl;
    cout << "Ten tinh: " << tinh.tenTinh << endl;
    cout << "Dan so: " << tinh.danSo << endl;
    cout << "Dien tich: " << tinh.dienTich << endl;
}

void xuatTinhLonHon1Trieu(const Tinh danhSachTinh[], int soLuongTinh) {
    cout << "Danh sach cac tinh co dan so lon hon 1 trieu:" << endl;
    for (int i = 0; i < soLuongTinh; ++i) {
        if (danhSachTinh[i].danSo > 1000000) {
            xuatTinh(danhSachTinh[i]);
            cout << "--------------------" << endl;
        }
    }
}

const Tinh &timTinhDienTichLonNhat(const Tinh danhSachTinh[], int soLuongTinh) {
    const Tinh *tinhLonNhat = &danhSachTinh[0];
    for (int i = 1; i < soLuongTinh; ++i) {
        if (danhSachTinh[i].dienTich > tinhLonNhat->dienTich) {
            tinhLonNhat = &danhSachTinh[i];
        }
    }
    return *tinhLonNhat;
}

int main() {
    const int MAX_TINH = 100;
    Tinh danhSachTinh[MAX_TINH];
    int soLuongTinh;

    cout << "Nhap so luong tinh: ";
    cin >> soLuongTinh;

    for (int i = 0; i < soLuongTinh; ++i) {
        cout << "Nhap thong tin tinh thu " << i + 1 << ":" << endl;
        nhapTinh(danhSachTinh[i]);
        cout << "--------------------" << endl;
    }

    cout << "\nDanh sach cac tinh:" << endl;
    for (int i = 0; i < soLuongTinh; ++i) {
        xuatTinh(danhSachTinh[i]);
        cout << "--------------------" << endl;
    }

    xuatTinhLonHon1Trieu(danhSachTinh, soLuongTinh);

    const Tinh &tinhLonNhat = timTinhDienTichLonNhat(danhSachTinh, soLuongTinh);
    cout << "Tinh co dien tich lon nhat:" << endl;
    xuatTinh(tinhLonNhat);

    return 0;
}
