/*
Câu 21. Một số gọi là siêu số nguyên tố nếu số lượng các số nguyên tố từ 1 đến X (ngoại trừ X) là 
một số nguyên tố. Hãy viết chương trình đếm số lượng các siêu số nguyên tố này trong khoảng 
[A,B] cho trước nhập từ bàn phím. (12/100)
*/

#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra một số có phải là số nguyên tố hay không
bool checkSNT(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm đếm số lượng số nguyên tố từ 1 đến X
int Dem(int X) {
    int count = 0;
    for (int i = 1; i <= X - 1; ++i) {
        if (checkSNT(i)) {
            count++;
        }
    }
    return count;
}

// Hàm kiểm tra một số có phải là siêu số nguyên tố hay không
bool checkSieuSNT(int X) {
    int count = Dem(X);
    return checkSNT(count);
}

int main() {
    int A, B;
    int kq = 0;
    cout << "Nhap A: "; cin >> A;
    cout << "Nhap B: "; cin >> B;

    // Đếm số lượng siêu số nguyên tố trong khoảng [A, B]
    for (int X = A; X <= B; ++X) {
        if (checkSieuSNT(X)) {
            kq++;
        }
    }
    cout << "So luong sieu so nguyen to trong khoang [" << A << ", " << B << "] la: " << kq << endl;
    return 0;
}
