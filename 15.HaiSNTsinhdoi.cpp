/*
Câu 15. Viết chương trình Hai số nguyên tố sinh đôi là hai số nguyên tố hơn kém nhau 2 đơn vị. 
Tìm hai số nguyên tố sinh đôi nhỏ hơn hoặc bằng N, với N được nhập vào từ bàn phím.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool checkSNT(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cout << "Nhap N: ";
    cin >> N;
    // Duyệt qua tất cả các số nhỏ hơn hoặc bằng N để tìm các cặp số nguyên tố sinh đôi
    for (int i = 2; i <= N - 2; ++i) {
        if (checkSNT(i) && checkSNT(i + 2)) {
            cout << "Cap so nguyen to sinh doi: " << i << " va " << i + 2 << endl;
        }
    }
    return 0;
}