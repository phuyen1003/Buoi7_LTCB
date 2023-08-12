#include <iostream>
#include <string>

using namespace std;

struct DoiBong {
    string tenDoi;
    int soLuongCauThu;
    double diem;
};

void nhapDoiBong(DoiBong &doiBong) {
    cin.ignore(); //  Xóa ký tự dòng mới còn lại trong bộ đệm đầu vào
    cout << "Nhap ten doi: ";
    getline(cin, doiBong.tenDoi);
    cout << "Nhap so luong cau thu: ";
    cin >> doiBong.soLuongCauThu;
    cout << "Nhap diem: ";
    cin >> doiBong.diem;
}

void xuatDoiBong(const DoiBong &doiBong) {
    cout << "Ten doi: " << doiBong.tenDoi << endl;
    cout << "So luong cau thu: " << doiBong.soLuongCauThu << endl;
    cout << "Diem: " << doiBong.diem << endl;
}

void sapXepTheoDiem(DoiBong danhSachDoiBong[], int soLuongDoiBong) {
    for (int i = 0; i < soLuongDoiBong - 1; ++i) {
        for (int j = i + 1; j < soLuongDoiBong; ++j) {
            if (danhSachDoiBong[i].diem < danhSachDoiBong[j].diem) {
                swap(danhSachDoiBong[i], danhSachDoiBong[j]);
            }
        }
    }
}

void sapXepTheoSoLuongCauThu(DoiBong danhSachDoiBong[], int soLuongDoiBong) {
    for (int i = 0; i < soLuongDoiBong - 1; ++i) {
        for (int j = i + 1; j < soLuongDoiBong; ++j) {
            if (danhSachDoiBong[i].soLuongCauThu < danhSachDoiBong[j].soLuongCauThu) {
                swap(danhSachDoiBong[i], danhSachDoiBong[j]);
            }
        }
    }
}

void sapXepTheoTenDoi(DoiBong danhSachDoiBong[], int soLuongDoiBong) {
    for (int i = 0; i < soLuongDoiBong - 1; ++i) {
        for (int j = i + 1; j < soLuongDoiBong; ++j) {
            if (danhSachDoiBong[i].tenDoi > danhSachDoiBong[j].tenDoi) {
                swap(danhSachDoiBong[i], danhSachDoiBong[j]);
            }
        }
    }
}

int main() {
    const int MAX_DOIBONG = 100;
    DoiBong danhSachDoiBong[MAX_DOIBONG];
    int soLuongDoiBong;

    cout << "Nhap so luong doi bong: ";
    cin >> soLuongDoiBong;

    for (int i = 0; i < soLuongDoiBong; ++i) {
        cout << "Nhap thong tin doi bong thu " << i + 1 << ":" << endl;
        nhapDoiBong(danhSachDoiBong[i]);
        cout << "--------------------" << endl;
    }

    sapXepTheoDiem(danhSachDoiBong, soLuongDoiBong);

    cout << "\n3 doi co diem cao nhat:" << endl;
    for (int i = 0; i < 3 && i < soLuongDoiBong; ++i) {
        xuatDoiBong(danhSachDoiBong[i]);
        cout << "--------------------" << endl;
    }

    sapXepTheoSoLuongCauThu(danhSachDoiBong, soLuongDoiBong);

    cout << "\n3 doi co so luong cau thu nhieu nhat:" << endl;
    for (int i = 0; i < 3 && i < soLuongDoiBong; ++i) {
        xuatDoiBong(danhSachDoiBong[i]);
        cout << "--------------------" << endl;
    }

    sapXepTheoTenDoi(danhSachDoiBong, soLuongDoiBong);

    cout << "\nDanh sach doi bong theo thu tu ABC cua ten doi:" << endl;
    for (int i = 0; i < soLuongDoiBong; ++i) {
        xuatDoiBong(danhSachDoiBong[i]);
        cout << "--------------------" << endl;
    }

    return 0;
}
