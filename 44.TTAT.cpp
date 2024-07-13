/*
Câu 44. Cho mảng A gồm các số nguyên thuộc 𝐹𝑝 nhập vào từ bàn phím, hãy viết chương trình in 
ra mảng B có các phần tử là nghịch đảo của các phần tử tương ứng trong A. 17/3  /5/6/8
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int phantu, e, n, t, p, soto, sobe, trunggian;
    cout << "\nNhap p: ";
    cin >> p;
    cout << "Nhap so phan tu trong mang: ";
    cin >> phantu;
    int mang[phantu];
    cout << "Nhap cac phan tu cua mang, hay de so nay va p co gcd bang mot nhe \n";

label:
    for (e = 0; e < phantu; e++) {
        cout << "A[" << e << "] = ";
        cin >> mang[e];
        if (mang[e] > p) {
            soto = mang[e];
            sobe = p;
        } else {
            soto = p;
            sobe = mang[e];
        }
        if (p == mang[e]) {
            goto label;
        }
        while (sobe > 0) {
            trunggian = soto % sobe;
            soto = sobe;
            sobe = trunggian;
        } // gcd = soto

        if (soto != 1) {
            cout << "\nHay nhap lai tu dau!\n";
            goto label;
        }
    }
    cout << "mang A = (";
    for (e = 0; e < phantu; e++) {
        cout << "  " << mang[e] << "  ";
    }
    cout << ")";

    int mangB[phantu];
    for (e = 0; e < phantu; e++) {
        // Tính nghịch đảo của mang[e] modulo p
        int a = p, b = mang[e];
        int x1 = 0, x2 = 1, y1 = 1, y2 = 0;

        while (b > 0) {
            int q = a / b;
            int r = a - q * b;
            int x = x2 - q * x1;
            int y = y2 - q * y1;
            a = b;
            b = r;
            x2 = x1;
            x1 = x;
            y2 = y1;
            y1 = y;
        }

        int d = a;
        int x = x2;

        // Lưu nghịch đảo vào mangB[e]
        mangB[e] = y2;
    }

    cout << "\nKet qua: (";
    for (e = 0; e < phantu; e++) {
        if (mangB[e] < 0) {
            mangB[e] = mangB[e] + p;
        }
        cout << " " << mangB[e] << " ";
    }
    cout << ")";
    return 0;
}
