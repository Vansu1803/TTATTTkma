/*
Câu 17. Viết chương trình tìm số nguyên dương x nhỏ nhất và nhỏ hơn N nhập từ bàn phím sao 
cho giá trị của biểu thức 𝐴𝑥^2 + 𝐵𝑥 + 𝐶 là một số nguyên tố với A,B,C là các số nguyên nhập vào 
từ bàn phím. (1/0/-1/23)
*/

#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool checkSNT(int N) {
    if (N < 2) return false;
    for (int i = 2; i < N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    int A, B, C, N;
    cout << "Nhap A: "; cin >> A;
    cout << "Nhap B: "; cin >> B;
    cout << "Nhap C: "; cin >> C;
    cout << "Nhap N: "; cin >> N;

    int x = 1;
    while (x < N) {
        int res = A * x * x + B * x + C;
        if (checkSNT(res)) {
            cout << "Gia tri x nho nhat thoa man dieu kien: " << x << endl;
            break;
        }
        x++;
    }
    return 0;
}
