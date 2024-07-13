/*
Câu 27. Viết chương trình in ra các cặp số (a,b) thoả mãn điều kiện 0<a,b<1000, sao cho ước 
chung lớn nhất của 2 số đó là một số nguyên tố.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Hàm tính ước chung lớn nhất (gcd)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool checkSNT(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    const int MAX_LIMIT = 1000;

    cout << "Cac cap so (a, b) thoa man dieu kien 0 < a, b < 1000 va UCLN la so nguyen to la:\n";
    for (int a = 1; a < MAX_LIMIT; ++a) {
        for (int b = a + 1; b < MAX_LIMIT; ++b) {
            int ucln = gcd(a, b);
            if (checkSNT(ucln)) {
                cout << "(" << a << ", " << b << ") - UCLN: " << ucln << endl;
            }
        }
    }

    return 0;
}
