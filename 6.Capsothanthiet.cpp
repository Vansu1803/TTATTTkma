/*
Câu 6. Hai số tạo thành một cặp số thân thiết khi chúng tuân theo quy luật: Số này bằng tổng tất 
cả các ước của số kia (trừ chính số đó) và ngược lại. Viết chương trình tìm hai số dạng này nhỏ 
hơn N (với N nhập vào từ bàn phím).
*/

#include <bits/stdc++.h>
using namespace std;

// Hàm tính tổng các ước của một số (trừ chính số đó)
int check(int num) {
    int sum = 1; // 1 luôn là ước của mọi số
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int N;
    cout << "Nhập số N: ";
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int sum1 = check(i);
        if (sum1 > i && sum1 < N) {
            int sum2 = check(sum1);
            if (sum2 == i) {
                cout << "Cặp số thân thiết: (" << i << ", " << sum1 << ")\n";
            }
        }
    }
    return 0;
}
