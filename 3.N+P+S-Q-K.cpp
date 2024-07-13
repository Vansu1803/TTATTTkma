/*
Câu 3. Cho một số nguyên dương N, gọi:
- k là số ước nguyên tố của N;
- q là tổng của các ước nguyên tố của N;
- p là tổng của các ước số của N;
- s là số ước của N;
Hãy viết chương trình tính giá trị của: N+p+s-q-k với N cho trước nhập từ bàn phím.
Ví dụ: N=24, có các ước là {1,2,3,4,6,8,12, 24} do đó: 
p=1+2+3+4+6+8+12+24=60 và s=8
trong đó có 2 ước nguyên tố là {2,3} do đó:
q=2+3=5 và k=2
Và từ đó: N+p+s-q-k = 24+60+8-5-2=85;
*/

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