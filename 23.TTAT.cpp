/*
Câu 23. Viết chương trình in ra màn hình YES trong trường hợp tổng của các số nguyên tố trong 
khoảng [A, B] là cũng là một số nguyên tố và NO nếu ngược lại. Với A,B là hai số được nhập vào 
từ bàn phím.  (A < B)
*/

#include <iostream>
#include <cmath>
using namespace std;

bool checkSNT(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int A, B;
    cout << "Nhap A: "; cin >> A;
    cout << "Nhap B: "; cin >> B;

    int sumSNT = 0;

    // Tính tổng của các số nguyên tố trong khoảng [A, B]
    for (int i = A; i <= B; ++i) {
        if (checkSNT(i)) {
            sumSNT += i;
        }
    }
    
    bool checkSumSNT = checkSNT(sumSNT);
    if (checkSumSNT) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
