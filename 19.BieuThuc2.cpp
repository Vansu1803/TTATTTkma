/*
Câu 19. Viết chương trình in ra các số nguyên dương x nằm trong khoảng [m,l] sao cho giá trị
của biểu thức 𝐴𝑥^2 + 𝐵𝑥 + 𝐶 là một số nguyên tố. Với A,B,C, m,l là các số nguyên nhập từ bàn 
phím (m<l). ( 1/100/1/0/-1)
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m, l, A, B, C, x;
    bool check2 = false;
    cout << "Nhap so m: "; cin >> m;
    cout << "Nhap so l > m: "; cin >> l;
    cout << "Nhap A: "; cin >> A;
    cout << "Nhap B: "; cin >> B;
    cout << "Nhap C: "; cin >> C;
    //duyệt x từ m đến l
    for (int x = m; x <= l; x++) {
        int ra = A * x * x + B * x + C;
        bool check = true;
        //Kiểm tra số nguyên tố
        if (ra <= 1) {
            check = false;
        } else {
            for (int i = 2; i <= sqrt(ra); i++) {
                if (ra % i == 0) {
                    check = false;
                    break;
                }
            }
        }
        // In ra kq
        if (check) {
            cout << x << " la so nguyen to cua tong A.x^2 + B.x + C = " << ra << endl;
            check2 = true;
        }
    }

    if (!check2) {
        cout << "Khong co gia tri thoa man" << endl;
    }
    return 0;
}


