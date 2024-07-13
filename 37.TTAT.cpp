/*
Câu 37. Lập trình tìm kiếm xâu S1 trong xâu S2 theo thuật toán Knutt-Morris-Patt. Trong trường 
hợp nào thì thuật toán Boyer-Moore được xem là cải tiến hơn thuật toán tìm kiếm vét cạn?
*/

#include <iostream>
#include <cstring>

using namespace std;

// Hàm so sánh hai chuỗi con của chuỗi mẫu
int soSanhChuoi(char p[], int j, int i) {
    int check = 0;
    for (int k = 0; k < i; k++) {
        if (p[k] == p[j - i + k]) {
            check++;
        }
    }
    return check == i ? 1 : 0;
}

// Hàm kiểm tra tiền tố dài nhất của chuỗi mẫu cũng là hậu tố
int kiemTra(char p[], int j) {
    for (int i = j - 1; i >= 1; i--) {
        if (soSanhChuoi(p, j, i) == 1) {
            return i;
        }
    }
    return 0;
}

// Hàm tạo mảng hàm thất bại
void failureFunction(char p[], int f[]) {
    f[0] = -1;
    f[1] = 0;
    for (int j = 2; j < (int)strlen(p); j++) {
        f[j] = kiemTra(p, j);
    }
}

// Hàm xử lý văn bản và chuỗi mẫu sử dụng thuật toán KMP
int xuLy(char t[], char p[], int f[]) {
    int i = 0, j = 0, check = 0, sopheptinhlap = 0;
    while (i < (int)strlen(t) - (int)strlen(p)) {
        int checkp = j, k = i + j;
        while (checkp != (int)strlen(p)) {
            if (t[k] == p[j]) {
                k++;
                j++;
                checkp++;
                sopheptinhlap++;
            } else {
                i = i + j - f[j];
                j = f[j] == -1 ? 0 : f[j];
                sopheptinhlap++;
                break;
            }
        }
        if (checkp == (int)strlen(p)) {
            cout << "\nKQ: Vi tri " << i;
            check = 1;
            j = 0;
            i = i + strlen(p);
        }
    }
    if (check == 0) {
        cout << "\nKQ: Khong co chuoi can tim";
    }
    return sopheptinhlap;
}

int main() {
    char t[5000], p[100];
    cout << "Nhap doan van ban T: ";
    cin.getline(t, sizeof(t));
    cout << "Nhap chuoi P can tim: ";
    cin.getline(p, sizeof(p));

    int f[strlen(p)];
    failureFunction(p, f);
    int sopheptinhlap = xuLy(t, p, f);
    cout << "\nSo phep tinh lap la: " << sopheptinhlap;

    return 0;
}
