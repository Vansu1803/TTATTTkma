/*
Câu 42. Viết chương trình sinh ra 2 số nguyên tố 0<p,q<1000 và kiểm tra với với số 0<a<100 thì 
liệt kê những số a thoả mãn: a^p mod q là số nguyên tố. (23/5/27)
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int a, k, n, b, kq, A, bpA;
    vector<int> K(50);
    cout << "\nNhap a: ";
    cin >> a;
    cout << "\nNhap so mu k: ";
    cin >> k;
    cout << "\nNhap n: ";
    cin >> n;
    if (k == 0) {
        if (n == 1) 
            cout << "\nKet qua = 0";
        else 
            cout << "\nKet qua = 1";
        return 0;
    }
    A = a; 
    b = a;
    if (k == 1) {
        kq = a % n;
        cout << "\nKet qua = " << kq;
        return 0;
    }
    // Chuyen so mu k sang nhi phan
    if (k != 1 && k != 0) {
        int x = k, i = 0, d = 0;
        while (x > 0) {
            K[i] = x % 2;
            x = (x - K[i]) / 2;
            cout << "K[" << i << "]=" << K[i] << " ;  ";
            i++;
            d++;
        }

        for (i = 1; i < d; i++) {
            bpA = pow(A, 2);
            A = bpA % n;
            if (K[i] == 1) {
                b = (A * b) % n;
            }
            cout << "\n" << i << "  " << A << "  " << b;
        }
        cout << "\nA = " << A << "; B = " << b;
        bool check = true;
        for (i = 2; i <= sqrt(b); i++) {
            if (b % i == 0) {
                check = false;
                break;
            }
        }
        if (check) 
            cout << " Day la so nguyen to";
        else 
            cout << " Day khong phai so nguyen to";
    }
    return 0;
}

