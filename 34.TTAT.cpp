/*
Câu 34. Cài đặt thuật toán kiểm tra số nguyên tố Fermat. Trong trường hợp số nào thì thuật toán 
cho kết quả kiểm tra sai. 
*/

#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <cmath>    

using namespace std;

int main() {
    int n, t, a, ran = 0, i, m;

label:
    cout << "\nNhap n: ";
    cin >> n;
    m = n;

    if (n < 3 || n % 2 == 0) {
        cout << "\nSo n phai le va lon hon hoac bang 3, xin moi nhap lai!\n";
        goto label;
    }

    cout << "\nSo lan lap: ";
    cin >> t;

    srand(time(NULL));

    for (i = 1; i <= t; i++) {
        cout << "\n----------------\nLan lap " << i;

        while (ran >= 0) {
            ran = rand();
            if (ran >= 2 && ran <= n - 2)
                break;
        }

        a = ran;
        cout << "\n ran = " << a;

        // Tinh r = a^(n-1) mod n
        int r, x, A;
        x = n - 1; // Tinh r = a^x (mod n)
        int b;
        b = 1; A = a;

        if (x == 0) {
            cout << "\nr = b = 1";
        }

        // Chuyen x thanh so nhi phan
        int nhiphan, k[20], j = 0, d;
        nhiphan = x;
        cout << "\n";

        while (nhiphan > 0) {
            k[j] = nhiphan % 2;
            nhiphan = (nhiphan - k[j]) / 2;
            cout << " k[" << j << "]=" << k[j];
            j++;
        }

        if (k[0] == 1) // Vi n la so le nen x la so chan
            b = a;

        for (d = 0; d < j; d++) {
            A = (A * A) % m;
            if (k[d] == 1)
                b = (A * b) % m;
            cout << "\n " << d << " " << A << " " << b;
        }

        cout << "\nr = b= " << b; // b la r = a^(n-1) mod n

        if (b != 1)
            cout << "\nDay la hop so";
        else
            cout << "\nDay la so nguyen to";
    }

    return 0;
}
