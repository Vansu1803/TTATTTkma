/*
Câu 20. Viết chương trình in ra các cặp số (A,B) nằm trong khoảng (M,N) sao cho ước số chung 
lớn nhất của A và B có giá trị là một số D cho trước. Với M,N,D nhập vào từ bàn phím. (0<M,N, 
D < 1000). (10/30/5)
*/

#include <iostream>
using namespace std;

// Hàm tính ước số chung lớn nhất gcd
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int M, N, D;
    cout << "Nhap M: "; cin >> M;
    cout << "Nhap N: "; cin >> N;
    cout << "Nhap D: "; cin >> D;
    //in kq
    cout << "Cac cap so (A, B) thoa man UCLN(A, B) = " << D << " trong khoang [" << M << ", " << N << "] la:" << endl;
    for (int A = M; A <= N; A++) {
        for (int B = A + 1; B <= N; B++) {
            if (gcd(A, B) == D) {
                cout << "(" << A << ", " << B << ")" << endl;
            }
        }
    }

    return 0;
}
