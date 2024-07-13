/*
Câu 41. Cho các số nguyên dương a,k,n, nhập từ bàn phím (0<a,k<n<1000), Viết chương trình 
xác định xem a
k mod n có phải là một số nguyên tố hay không (sử dụng thuật toán bình phương 
và nhân có lặp)?
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
            cout << "\nKet qua = 0" << endl;
        else
            cout << "\nKet qua = 1" << endl;
    } else if (k == 1) {
        kq = a % n;
        cout << "\nKet qua = " << kq << endl;
    } else {
        A = a;
        b = a;
        // Chuyển đổi số mũ k sang dạng nhị phân
        int x = k, i = 0, d = 0;
        while (x > 0) {
            K[i] = x % 2;
            x = (x - K[i]) / 2;
            cout << "K[" << i << "]=" << K[i] << " ;  ";
            i++;
            d++;
        }

        // Tính toán kết quả
        for (i = 1; i < d; i++) {
            bpA = pow(A, 2);
            A = bpA % n;
            if (K[i] == 1) {
                b = (A * b) % n;
            }
            cout << "\n" << i << "  " << A << "  " << b;
        }
        cout << "\nA = " << A << "; B = " << b << ";";
        bool isPrime = true;
        for (i = 2; i <= sqrt(b); i++) {
            if (b % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            cout << " Day la so nguyen to" << endl;
        else
            cout << " Day khong phai so nguyen to" << endl;
    }
    return 0;
}
