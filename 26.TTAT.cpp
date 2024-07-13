/*
Câu 26. Một số được gọi là số mạnh mẽ khi nó đồng thời vừa chia hết cho số nguyên tố và chia 
hết cho bình phương của số nguyên tố đó. Tìm số mạnh mẽ nhỏ hơn số N cho trước (N < 10000).
(12361234523456)
*/ 

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

bool checkSNT(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cout << "Nhap so N: ";
    cin >> N;

    vector<int> primes;
    // Tìm các số nguyên tố nhỏ hơn N
    for (int i = 2; i < N; ++i) {
        if (checkSNT(i)) {
            primes.push_back(i);
        }
    }
    cout << "Cac so manh me nho hon " << N << " la: ";
    // Duyệt và in ra các số mạnh mẽ
    for (int prime : primes) {
        int square = prime * prime;
        if (square < N && N % prime == 0 && N % square == 0) {
            cout << N << " chia het cho " << prime << " va " << square << endl;
        }
    }
    return 0;
}
