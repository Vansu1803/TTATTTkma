/*
Câu 25. Cho 2 số M và N thoả mãn điều kiện: 1<=N<=10000; 2<M<=100; Hãy viết chương trình 
xác định xem số N có thể được phân tích thành tổng của M số nguyên tố hay không? Nếu có thì in 
ra các số đó. 
Ví dụ: N=10 và M=3, thì 10=2+3+5 do đó kết quả trả về là thoả mãn và in ra 3 số 2,3,5.  (10/3)
*/

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Nhap n: "; cin >> n;
    cout << "Nhap vao m: "; cin >> m;

    int arrayPrime[100];
    int k = 0;
    int sum = 0;

    // Tìm các số nguyên tố từ 2 đến n
    for (int i = 2; i <= n; i++) {
        bool checkSNT = true;
        // Kiểm tra số nguyên tố
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                checkSNT = false;
                break;
            }
        }
        if (checkSNT) {
            k++;
            arrayPrime[k] = i;
        }
    }

    // Tính tổng m số nguyên tố đầu tiên
    for (int i = 1; i <= m; i++) {
        sum += arrayPrime[i];
    }
    // Kiểm tra và in ra nếu tổng m số nguyên tố đầu tiên bằng n
    if (sum == n) {
        cout << "Cac so nguyen to co tong bang " << n << " la: ";
        for (int i = 1; i <= m; i++) {
            cout << arrayPrime[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Khong ton tai " << m << " so nguyen to co tong bang " << n << endl;
    }
    return 0;
}
