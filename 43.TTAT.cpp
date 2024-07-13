/*
Câu 43. Cho N nhập vào từ bàn phím (0<N<1000), sinh một số nguyên tố p<100. Hãy viết 
chương trình tìm tất cả các số nguyên a<N sao cho a^p mod N là số nguyên tố. (567)
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
    int i, e, p, n, t, check;

    cout << "\nNhap N voi (0<N<1000): ";
    cin >> n;

    // Tạo số nguyên tố p ngẫu nhiên
    p:
    check = 0;
    p = 2 + rand() % 999;   // Sinh số nguyên tố p trong khoảng từ 2 đến 1000
    for (i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            check = 1;
            break;
        }
    }
    if (check == 1) goto p;

    cout << "Gia tri cua p = " << p << endl;
    cout << "Nhung so a thoa man de bai la: ";

    int j = 0, a, b, d, k, K[50];

    // Chuyển p sang dạng nhị phân và lưu vào mảng K
    k = p;
    while (k > 0) {
        K[j] = k % 2;
        k = (k - K[j]) / 2;
        j++;
    }

    // Kiểm tra từng số nguyên d từ 1 đến 99
    for (d = 1; d < 100; d++) {
        check = 1;
        a = d;

        // Tính b = a^((p-1)/2) % n
        if (K[0] == 1) b = a;
        for (i = 0; i < j; i++) {
            a = (a * a) % n;
            if (K[i] == 1) {
                b = (a * b) % n;
            }
        }
        // Kiểm tra nếu b là số 2 và là số nguyên tố
        if (b == 2) cout << d;
        // Kiểm tra d có phải là số nguyên tố
        for (i = 2; i <= sqrt(b); i++) {
            if (b % i == 0) {
                check = 0;
                break;
            }
        }  
        // Nếu d là số nguyên tố, in ra d
        if (check == 1) cout << d << " ";
    }

    return 0;
}
