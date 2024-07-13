/*
Câu 18. Áp dụng thuật toán đã được học để viết chương trình tính tổng của hai số nguyên lớn, 
hiển thị dưới mạng mảng và dạng số nguyên. 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int p, w, t, sel;
    w = 8;
    p = 2147483647;
    t = (log2(p) + 0.5) / w + 0.5;
    char rep;
    do {
        system("cls");
        int a, b, i;
        int A[t], B[t], C[t];
        
        cout << "\nNhap a: "; cin >> a;
        cout << "\nNhap b: "; cin >> b;
        // Tách số a và b thành từng phần tử của mảng A và B
        for (i = t - 1; i >= 0; i--) {
            A[i] = a / pow(2, i * w);
            a = a - A[i] * pow(2, i * w);
            B[i] = b / pow(2, i * w);
            b = b - B[i] * pow(2, i * w);
        }
        // In mảng A và B
        cout << "\n A = [";
        for (i = t - 1; i >= 0; i--) cout << A[i] << " ";
        cout << "]";

        cout << "\n B = [";
        for (i = t - 1; i >= 0; i--) cout << B[i] << " ";
        cout << "]";

        // Tính tổng và cập nhật mảng C
        int e = 0;
        for (i = 0; i < t; i++) {
            C[i] = (A[i] + B[i] + e) % static_cast<int>(pow(2, w));
            if ((A[i] + B[i] + e) >= static_cast<int>(pow(2, w)))
                e = 1;
            else
                e = 0;
        }

        // In tổng
        cout << "\n Tong = (" << e << ", [";
        for (i = t - 1; i >= 0; i--) cout << C[i] << " ";
        cout << "])";

        // Hỏi người dùng có muốn tiếp tục không
        cout << "\n------------------------------------------\nLam lai? YES: 1     NO: 0\nBan chon: ";
        cin >> rep;

    } while (rep == '1');

    return 0;
}
