/*
Câu 14. Viết chương trình tìm số nguyên tố có ba chữ số, biết rằng nếu viết số đó theo thứ tự 
ngược lại thì ta được một số là lập phương của một số tự nhiên
*/

#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool kiemtraSNT(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm đảo ngược một số
int DaonguocSNT(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

// Hàm kiểm tra xem một số có phải là lập phương của một số tự nhiên hay không
bool check(int n) {
    int cub = round(cbrt(n));
    return cub * cub * cub == n;
}

int main() {
    for (int i = 100; i <= 999; ++i) {
        if (kiemtraSNT(i)) {
            int rev = DaonguocSNT(i);
            if (check(rev)) {
                cout << "So nguyen to can tim la: " << i << endl;
            }
        }
    }
    return 0;
}
