/*
Câu 13. Viết chương trình tìm hai số nguyên tố nhỏ hơn hoặc bằng N với N nhập vào từ bàn 
phím, sao cho tổng và hiệu của chúng đều là số nguyên tố
*/

#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool kiemtraSNT(int n) {
    if (n < 2) return false;
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    while (n < 2) {
        cout << "Nhap n>=2. Moi nhap lai.\n";
        cout << "Nhap n: ";
        cin >> n;
    }

    for (int i = 2; i <= n; ++i) {
        if (kiemtraSNT(i)) {
            for (int j = i; j <= n; ++j) {
                if (kiemtraSNT(j)) {
                    int tong = i + j;
                    int hieu = abs(i - j);
                    if (kiemtraSNT(tong) && kiemtraSNT(hieu)) {
                        cout << "Hai so nguyen to can tim la: " << i << " va " << j << endl;
                    }
                }
            }
        }
    }

    return 0;
}
