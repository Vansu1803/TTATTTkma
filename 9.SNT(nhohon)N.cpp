#include <bits/stdc++.h>
#include <math.h>

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
    int N; 
    cout << "Enter N: "; cin >> N;
    cout << "Cac so nguyen to (</=) " << N << " la: ";
    Sang();
    for(int i=0; i<=N ; i++){
        if(prime[i]) cout << i << " ";
    }
    return 0;
}