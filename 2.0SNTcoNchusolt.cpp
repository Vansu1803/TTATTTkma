#include <bits/stdc++.h>
#include <stdbool.h>

using namespace std;
// ktra tinh nguyen to
bool check(int num){
    if(num <= 1) return false;
    if(num == 2) return true;
    if(num %2 ==0)  return false;
    for(int i=3; i<=sqrt(num); i+=2 ){
        if(num %i == 0) return false;
    }
    return true; 
}
// ham SNT co N chu so

vector<int> SNTcoNchuso(int N){
    vector<int> primes;
    int start = pow(10, N-1);
    int end = pow(10, N) - 1;
    for(int i= start; i<=end; ++i){
        if(check(i)){
            primes. push_back(i);
        }
    }
    return primes;
}

int main(){
    int N ; 
    cout << "Nhap so N (2 <= N <= 10): "; cin >> N;

    if(N<2 || N>10) {
        cout << "Giá trị N không hợp lệ! Vui lòng nhập giá trị từ 2 đến 10." << endl;
        return 1;
    }
    vector<int> primes = SNTcoNchuso(N);

    cout << "Các số nguyên tố có " << N << " chữ số là:" << endl;
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl; 

    return 0;

}
