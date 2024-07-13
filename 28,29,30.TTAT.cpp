/*
Câu 28. Viết chương trình tìm các số Carmichael (là các số giả nguyên tố n thoả mãn điều kiện là 
hợp số và thoả mãn 𝑏^(n-1) ≡ 1 (𝑚𝑜𝑑 𝑛) với mọi số nguyên dương b nguyên tố cùng nhau với n) 
nhỏ hơn một số N cho trước nhập vào từ bàn phím (với điều kiện 0 ≤ 𝑁 ≤ 10000. 
Câu 29. Viết chương trình đếm số các số Carmichael (là các số giả nguyên tố n thoả mãn điều 
kiện là hợp số và thoả mãn 𝑏
𝑛−1 ≡ 1 (𝑚𝑜𝑑 𝑛) với mọi số nguyên dương b nguyên tố cùng nhau 
với n) nhỏ hơn một số N cho trước nhập vào từ bàn phím (với điều kiện 0 ≤ 𝑁 ≤ 10000.
Câu 30. Viết chương trình tính tổng của các số Carmichael (là các số giả nguyên tố n thoả mãn 
điều kiện là hợp số và thoả mãn 𝑏
𝑛−1 ≡ 1 (𝑚𝑜𝑑 𝑛) với mọi số nguyên dương b nguyên tố cùng 
nhau với n) nhỏ hơn một số N cho trước nhập vào từ bàn phím (với điều kiện 0 ≤ 𝑁 ≤ 10000.
(5433)
*/

#include <bits/stdc++.h>
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


int main() {
    int x;
    cout << "Nhap x: ";
    cin >> x;

    for (int n = 4; n <= x; n++) {
        int m = n;
        int a[10], b[10], j = 0, permission = 0, check = 1;
        // Phân tích thừa số nguyên tố của n
        for (int i = 2; i <= m; i++) {
            int dem = 0;
            while ((m % i) == 0) {
                m /= i;
                dem++;
            }
            if (dem >= 1) {
                a[j] = i;  // Lưu thừa số nguyên tố
                b[j] = dem;  // Lưu số lần xuất hiện của thừa số
                if (b[j] >= 2) check = 0;
                j++;
            }
        }
        // Kiểm tra điều kiện Carmichael
        if (check == 0 || j < 3) {
            permission = 1;
        }
        // Kiểm tra các điều kiện Carmichael
        for (int i = 0; i <= j - 1; i++) {
            if ((n % a[i]) == 0 && (n - 1) % (a[i] - 1) != 0) {
                permission = 1;
            } else if ((n % a[i]) == 0 && (n - 1) % (a[i] - 1) == 0 && check != 0 && permission != 1) {
                permission = 0;
            }
        }

        if (permission == 0 && check != 0) {
            cout << n << " ";
        }
    }

    cout << endl;
    return 0;
}
