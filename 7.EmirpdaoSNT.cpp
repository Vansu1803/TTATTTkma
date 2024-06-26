#include <bits/stdc++.h>
using namespace std;
bool prime[1000001];

void Sang(){
    for(int i=0; i<=1000000; i++){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i=2; i<=1000; i++){
        if(prime[i]){
            for(int j=i*i; j<=1000000; j+=i){
                prime[j] = 0;
            }
        }
    }  
}

int reverse(int x){
    int rev = 0;
    if(x>0){
        rev = (rev*10) + x%10;
        x = x/10;
        return rev;
    }
    //Sang();
}
int main(){
    int N; 
    cout << "Nhap N: \n"; cin >> N;
    Sang();
    for(int i; i<=N; i++){
        reverse(i);
        Sang();
        if(prime[i]){
            cout << i << " ";
        }
    }
    cout << endl;
}