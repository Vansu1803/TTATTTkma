/* Câu 22. Với một số nguyên dương N thoả mãn 0<N<10000, đặt:
F ( N ) = N nếu N là một số nguyên tố
F ( N ) = 0 nếu là hợp số
Cho L và R nhập vào từ bàn phím, với mọi cặp i , j trong khoảng [ L , R ] hãy viết chương trình 
in ra màn hình giá trị tổng của F ( i ) * F ( j ) với j > i. (L<R)
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
// Tính giá trị của hàm F(N) 
int GiatriF(int N) {
    if (checkSNT(N)) {
        return N;
    } else {
        return 0;
    }
}

int main() {
    int L, R;
    cout << "Nhap L: "; cin >> L;
    cout << "Nhap R: "; cin >> R;
    long long sum = 0;
    for (int i = L; i <= R; ++i) {
        for (int j = i + 1; j <= R; ++j) {
            sum += GiatriF(i) * GiatriF(j);
        }
    }
    
    cout << "Tong gia tri F(i) * F(j) voi j > i trong khoang [" << L << ", " << R << "] la: " << sum << endl;
    return 0;
}
