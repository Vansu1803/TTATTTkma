/*
Câu 31. Áp dụng theo các thuật toán đã được học trong phần lí thuyết em hãy cài đặt chương 
trình:
- Tìm số nguyên tố k gần nhất với phần số của mã số sinh viên của mình (trong trường hợp 
khoảng cách bằng nhau thì lấy số nhỏ hơn).
- Từ số k tìm được tính ak mod n với a = SBD, n = 123456.  (2345/123)
*/

#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int MSV, SBD, MSVd, MSVt, i, cduoi, ctren, check, b, k, a, j, n;
    int K[50];
    cduoi = ctren = 0;
    n = 1234; // Giới hạn số nguyên tố để tìm các số nguyên tố gần nhất

    cout << "Nhap MSV: ";
    cin >> MSV;
    cout << "Nhap SBD: ";
    cin >> SBD;

    MSVd = MSVt = MSV;

    // Tìm số nguyên tố gần nhất với MSVd (bên dưới MSV)
    do {
        MSVd--;
        cduoi++;
        check = 0;
        for (i = 2; i <= sqrt(MSVd); i++) {
            if (MSVd % i == 0) {
                check = 1;
                break;
            }
        }
    } while (check == 1);

    // Tìm số nguyên tố gần nhất với MSVt (bên trên MSV)
    do {
        MSVt++;
        ctren++;
        check = 0;
        for (i = 2; i <= sqrt(MSVt); i++) {
            if (MSVt % i == 0) {
                check = 1;
                break;
            }
        }
    } while (check == 1);

    // Chọn số nguyên tố gần nhất
    if (cduoi <= ctren)
        MSV = MSVd;
    else
        MSV = MSVt;

    k = MSV;
    a = SBD;
    b = 1;
    j = 0;

    // Chuyển đổi k sang dạng nhị phân và tính a^k mod n
    while (k > 0) {
        K[j] = k % 2;
        k = (k - K[j]) / 2;
        j++;
    }

    if (K[0] == 1)
        b = a;

    for (i = 0; i < j; i++) {
        a = (a * a) % n;
        if (K[i] == 1) {
            b = (a * b) % n;
        }
    }

    cout << SBD << " ^ " << MSV << " mod " << n << " = " << b << endl;

    return 0;
}

