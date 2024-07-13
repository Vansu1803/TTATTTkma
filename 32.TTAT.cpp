/*
Câu 32. Áp dụng các thuật toán đã được học em hãy cài đặt chương trình giải bài toán mô 
phỏng cách mã và giải mã của hệ mật RSA như sau:
- Tìm số nguyên số p, q (trong đó 100 < p, q < 500)
- Tính n = p.q; (n) = (p – 1) (q – 1) 
- Chọn e (1<e< (n)) là số nguyên tố cùng nhau với (n) (gcd(e, (n)) = 1) và tính d = e-1
mod (n)
- Tính bản mã c của thông điệp m, với m = SBD + 123, c = me mod n
- Giải mã thông điệp, tính m = cd mod n 
*/

#include <iostream>
#include <cmath>
using namespace std;

int ktsnt(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int euclidmr(int e, int en) {
    int a = e, b = en, R;
    while (b > 0) {
        R = a % b;
        a = b;
        b = R;
    }
    return a;
}

int tinhd(int e, int en) {
    int q, r, x, y, x1 = 0, x2 = 1, y1 = 1, y2 = 0;
    while (e > 0) {
        q = en / e;
        r = en % e;
        x = x2 - x1 * q;
        y = y2 - y1 * q;
        en = e;
        e = r;
        x2 = x1;
        y2 = y1;
        x1 = x;
        y1 = y;
    }
    return y2;
}

int main() {
    int p, q, n, en, e;
    cout << "Nhap p > 100: ";
    cin >> p;
    while (p <= 100 || ktsnt(p) == 0) {
        cout << "Nhap lai so nguyen to p > 100: ";
        cin >> p;
    }
    cout << "Nhap so nguyen to q < 500: ";
    cin >> q;
    while (q >= 500 || ktsnt(q) == 0) {
        cout << "Nhap lai so nguyen to q < 500: ";
        cin >> q;
    }
    n = p * q;
    en = (p - 1) * (q - 1);
    cout << "\ne(n) = " << en;

    cout << "\nNhap 1 < e < e(n), nguyen to cung nhau voi e(n): ";
    cin >> e;

    while (e <= 1 || e >= en || euclidmr(e, en) != 1) {
        cout << "\nNhap lai 1 < e < e(n), nguyen to cung nhau voi e(n): ";
        cin >> e;
    }

    cout << "\nd = " << tinhd(e, en) << endl;

    int m, a, k, K[50], b, i, j = 0;
    cout << "Nhap SBD: ";
    cin >> m;
    m = m + 123;
    cout << "Thong diep m = SBD + 123 = " << m << endl;

    k = e;
    a = m;
    b = 1;
    while (k > 0) {
        K[j] = k % 2;
        k = (k - K[j]) / 2;
        j++;
    }

    if (K[0] == 1) {
        b = a;
    }

    for (i = 0; i < j; i++) {
        a = (a * a) % n;
        if (K[i] == 1) {
            b = (a * b) % n;
        }
    }

    cout << "\nBan ma cua thong diep " << m << " la: " << b;

    k = tinhd(e, en);
    a = b;
    b = 1;
    j = 0;
    while (k > 0) {
        K[j] = k % 2;
        k = (k - K[j]) / 2;
        j++;
    }

    if (K[0] == 1) {
        b = a;
    }

    for (i = 0; i < j; i++) {
        a = (a * a) % n;
        if (K[i] == 1) {
            b = (a * b) % n;
        }
    }

    cout << "\nGiai ma thong diep la: " << b;

    return 0;
}
