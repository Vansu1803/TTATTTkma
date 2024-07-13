/*
Câu 24. Đặt S1, S2 là các mảng chứa giá trị bình phương của các số nguyên. Hãy viết chương 
trình in ra số lượng tất cả các số nguyên tố nằm trong khoảng [a,b] sao cho số này cũng là tổng
của hai số x và y với x thuộc S1 và y thuộc S2. Trong đó, a,b là các số được nhập từ bàn phím
Ví dụ: với a=10, b =15, in ra giá trị là 1 vì trong khoảng [10,15] chỉ có 2 số nguyên tố 11 và 13, 
nhưng chỉ có 13 = 2^2 + 3^2=4+9. 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, sb, i, j, k, Tong, check;
    cout << "Nhap a: "; cin >> a;
    cout << "Nhap b: "; cin >> b;
    sb = sqrt(b);
    int S1[b+1], S2[b+1];
    
    for (i = 1; i <= sb; i++) {
        S1[i] = i * i;
        S2[i] = i * i;
        cout << S1[i] << " ";
    }
    
    for (i = 1; i <= sb; i++) {
        for (j = 1; j <= sb; j++) {
            Tong = S1[i] + S2[j];
            if (Tong >= a && Tong <= b) {
                check = 1;
                for (k = 2; k <= sqrt(Tong); k++) {
                    if (Tong % k == 0) {
                        check = 0;
                        break;
                    }
                }
                if (check == 1) {
                    cout << "\nCap so S1, S2: " << S1[i] << " " << S2[j];
                }
            }
        }
    }

    return 0;
}
