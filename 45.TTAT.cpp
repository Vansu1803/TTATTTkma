/*
Câu 45. Viết chương trình sinh một mảng số nguyên tố A gồm N phần tử (N nhập từ bàn phím) 
sử dụng kiểm tra Miller-Rabin. In ra mảng và tính khoảng cách nhỏ nhất giữa 2 số bất kỳ trong 
mảng.  (5/3)
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
    int phantu, e, random = 0, n, t;
    cout << "\nNhap N: ";
    cin >> phantu;
    cout << "So lan lap: ";
    cin >> t;
    int mang[phantu];
    for (e = 0; e < phantu; e++) {
    label:
        while (random >= 0) {
            random = rand();
            if ((random >= 2) && (random < 1000))
                break;
        }
        n = random;

        int i;
        // Tìm r và s thỏa mãn n-1 = r*2^s
        int r, s, trunggian;
        trunggian = n - 1;
        r = trunggian;
        s = 0;
        while (r > 0) {
            if (r % 2 == 1) {
                break;
            }
            r = trunggian / 2;
            trunggian = r;
            s++;
        }

        for (i = 1; i <= t; i++) {
            // Chọn số ngẫu nhiên a, 2 <= a <= n-2
            int a = 0, ran;
            while (a >= 0) {
                ran = rand();
                if ((ran >= 2) && (ran <= (n - 2)))
                    break;
            }
            a = ran;

            // Dùng phép nhân có lặp để tính y = a^r mod n
            int b, A, y, m;
            b = 1;
            A = a;
            m = n;
            if (r == 0)
                y = b; // không xảy ra vì r từ đầu là số lẻ

            // Chuyển r sang dạng nhị phân qua mảng R[]
            int nhiphan, R[20], j = 0, d = 0;
            nhiphan = r;
            while (nhiphan > 0) {
                R[j] = nhiphan % 2;
                nhiphan = (nhiphan - R[j]) / 2;
                j++;
            }

            // Kế bảng
            if (r == 1)
                b = a;

            for (d = 0; d < j; d++) {
                A = (A * A) % m;
                if (R[d] == 1)
                    b = (A * b) % m;
            }
            y = b;

            if ((y != 1) && (y != n - 1)) {
                j = 1;
                while ((j <= (s - 1)) && (y != n - 1)) {
                    y = (y * y) % n;
                    if (y == 1) {
                        goto label;
                    }
                    j++;
                }
                if (y != n - 1) {
                    goto label;
                } else
                    mang[e] = n;
            } else
                mang[e] = n;
        }
    }

    cout << "\nCac phan tu trong mang la:\nA (";
    for (e = 0; e < phantu; e++)
        cout << mang[e] << "  ";
    cout << ")";

    // Sắp xếp thứ tự từ bé đến lớn
    int vt, phu;
    for (e = 0; e < phantu; e++)
        for (vt = 0; vt < phantu; vt++) {
            if (mang[e] < mang[vt]) {
                phu = mang[e];
                mang[e] = mang[vt];
                mang[vt] = phu;
            }
        }
    cout << "\nMang sau sap xep:\nA (";
    for (e = 0; e < phantu; e++)
        cout << mang[e] << "  ";
    cout << ")";

    // Tính khoảng cách nhỏ nhất
    int hieu, min = 200;
    for (e = 0; e < phantu; e++) {
        hieu = abs(mang[e] - mang[e + 1]);
        if (hieu < min)
            min = hieu;
    }
    cout << "\nKhoang cach nho nhat la: " << min;
    return 0;
}
