#include <iostream>
#include <vector>
#include <cmath>

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) { 
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tìm các số nguyên tố có N chữ số
std::vector<int> findPrimesWithNDigits(int N) {
    std::vector<int> primes;
    int start = std::pow(10, N - 1);
    int end = std::pow(10, N) - 1;

    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    int N;
    std::cout << "Nhập số N (2 ≤ N ≤ 10): ";
    std::cin >> N;

    if (N < 2 || N > 10) {
        std::cerr << "Giá trị N không hợp lệ! Vui lòng nhập giá trị từ 2 đến 10." << std::endl;
        return 1;
    }

    std::vector<int> primes = findPrimesWithNDigits(N);

    std::cout << "Các số nguyên tố có " << N << " chữ số là:" << std::endl;
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
