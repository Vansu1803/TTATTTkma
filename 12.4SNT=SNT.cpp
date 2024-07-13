/*
Câu 12. Viết chương trình tìm bốn số nguyên tố liên tiếp, sao cho tổng của chúng là số nguyên tố
nhỏ hơn hoặc bằng N (với N được nhập vào từ bàn phím).
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if(n <2) return false;
    if(n == 2 ) return true;
    if(n %2 == 0) return false;
    for(int i=3; i<=sqrt(n); i+=2){
        if(n %i  == 0) return false;
    }
    return true;
}

// Hàm tìm các số nguyên tố liên tiếp và kiểm tra tổng của chúng
void SNTlientiep(int N) {
    vector<int> primes;
    int num = 2;
    
    // Tìm các số nguyên tố và lưu vào vector
    while (primes.size() < 4 || primes.back() <= N) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
        num++;
    }

    // Duyệt qua các số nguyên tố và kiểm tra tổng của 4 số liên tiếp
    for (size_t i = 0; i <= primes.size() - 4; ++i) {
        int sum = primes[i] + primes[i+1] + primes[i+2] + primes[i+3];
        if (sum <= N && isPrime(sum)) {
            cout << "Bốn số nguyên tố liên tiếp là: " 
                 << primes[i] << ", " << primes[i+1] << ", " 
                 << primes[i+2] << ", " << primes[i+3] << endl;
            cout << "Tổng của chúng là: " << sum << endl;
            return;
            }    
        }

    cout << "Không tìm thấy bốn số nguyên tố liên tiếp nào có tổng là số nguyên tố nhỏ hơn hoặc bằng " << N << "." << std::endl;*****************************************
}

int main() {
    int N;
    cout << "Nhập N: ";
    cin >> N;
    SNTlientiep(N);
    return 0;
}