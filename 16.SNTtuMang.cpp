/*
Câu 16. Viết chương trình tìm các số nguyên tố từ một mảng sinh ngẫu nhiên có kích thước N, 
với N nhập vào từ bàn phím.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int check, N, i, j, ra;
    cout << "Nhap so N: ";  cin >> N;
    srand(time(0)); // Khởi tạo seed cho hàm rand()

    for (j = 0; j < N; j++) {
        check = 1;
        ra = rand();
        cout << ra << " ";
        for (i = 2; i <= sqrt(ra); i++) {
            if (ra % i == 0) {
                check = 0;
                break;
            }
        }
        if (check == 1) {
            cout << " Day la so nguyen to" << endl;
        } else {
            cout << " Day khong phai la so nguyen to" << endl;
        }
    }
    return 0;
}

