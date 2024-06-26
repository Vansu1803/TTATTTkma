#include <bits/stdc++.h>
using namespace std;

bool checkSNT(int num){
    if(num <= 1) return false;
    if(num == 2) return true;
    if(num %2 ==0) return false;
    for(int i=3; i<=sqrt(num); i+=2){
        if(num %i == 0) return false;
    }
    return true;
}
/*
bool prime[1000001];

void Sang(){
    for(int i=0; i<=1000000; i++){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i=0; i<=sqrt(1000000); i++){
        if(prime[i]){
            for(int j=i*i; j<=1000000; j+=i){
                prime[j] = 0;
            }
        }
    }
}
*/

int main(){
    Sang();
    int A, B; 
    cout << "Nhap tu ban phim A va B (A<B): "; cin >> A >> B;
    int tong = 0;
    for(int i=A; i<=B; i++){
        if(checkSNT[i]){
            tong +=i;
        }
    }
    cout << "Tong cua cac so nguyen to nam trong khoang [" << A << ", " << B << "] la: " << tong << endl;
    return 0;
}