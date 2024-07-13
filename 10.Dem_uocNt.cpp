/*
Câu 10. Viết chương trình đếm số ước và số ước nguyên tố của một số N nhập vào từ bàn phím.
*/ 

#include <bits/stdc++.h>
using namespace std;

bool prime[1000001];

void Sang(){
    for(int i=0; i<=1000001; i++){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i=2; i<=sqrt(1000000); i++){
        if(prime[i]){
            for(int j = i*i; j<=1000000; j+=i){
                prime[j] = 0;
            }
        }
    }
}


int main(){
    int N , ans=0; 
    Sang();
    cout << "Nhhap tu ban phim N: " ; cin >> N;
    int dem =2;
    for(int i=2; i<=(N/2); i++){
        if(N %i == 0){
            ++dem;
            if(prime[i]) ans+=1;
        }
    }
    cout << N << " co tat ca " << dem << " so uoc.\n";

    cout << N << " co " << ans << " so uoc nguyen to.";
    return 0;
}