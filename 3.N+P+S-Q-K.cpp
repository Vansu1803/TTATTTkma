#include <bits/stdc++.h>
#include <stdbool.h>
#include <math.h>
using namespace std;

bool checkSNT(int num){
    if(num <= 1) return false;
    if(num == 2) return true;
    if(num %2 ==0)  return false;
    for(int i=3; i<=sqrt(num); i+=2 ){
        if(num %i == 0) return false;
    }
    return true; 
}

int main(){
    int N, P=0, S=0, Q=0, K=0, Tong = 0;
    cout << "Nhap tu ban phim so nguyen N: "; cin >> N ;
    
    for(int i=1; i<=N; i++){
        if(N % i == 0){
            P += i;
        }
    }
    for(int i=1; i<=sqrt(N); i++){
        if(N % i == 0){
            if(i == N/i){    
                S++;
            }
            else{
                S+=2;
            }
        }    
    }
    for(int i=1; i<=sqrt(N); i++){
        if(N %i == 0){
            if(checkSNT(i)){
                Q+=i;
                ++K;
            }
        }
    }
    cout << P << endl;
    cout << S << endl;
    cout << Q << endl;
    cout << K << endl;
    Tong = N+P+S-Q-K;
    cout << "Vay ket qua cua N+P+S-Q-K: " << Tong << endl;
}