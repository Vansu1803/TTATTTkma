#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    int N, sum = 0;
    std::cout << "Enter N: ";
    std::cin >> N;

    for (int i = 2; sum + i <= N; ++i) {
        if (isPrime(i)) {
            sum += i;
            if (isPrime(sum) && sum <= N) {
                std::cout << "Four consecutive primes: " << i - 3 << ", " << i - 2 << ", " << i - 1 << ", " << i << std::endl;
                std::cout << "Their sum: " << sum << std::endl;
                break;
            }
        }
        if (i > 4) {
            // Subtract the oldest prime number in the sequence
            if (isPrime(i - 4)) {
                sum -= (i - 4);
            }
        }
    }

    if (sum > N || !isPrime(sum)) {
        std::cout << "No such primes found." << std::endl;
    }

    return 0;
}
