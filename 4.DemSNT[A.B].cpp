/*
Câu 4. Viết chương trình đếm số số nguyên tố nằm trong khoảng [A,B] với A, B nhập vào từ bàn 
phím.
*/

#include <bits/stdc++.h>

using namespace std;
bool prime[1000001];

void Sang(){
    for(int i=0; i<=1000000; i++){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0; // Loai bo thu cong 
    for(int i=0; i<=sqrt(1000000); i++){
        if(prime[i]){
            for(int j = i*i; j<=1000000; j+=i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    //Sang();
    int A, B; 
    cout << "Nhap tu ban phim A va B (A<B): "; cin >> A >> B;
    int dem = 0;
    //Sang();
    for(int i=A; i<=B; i++){
        Sang();
        if(prime[i]){
            ++dem;
        }
    }
    cout << "Co tat ca " << dem << " so nguyen to nam trong khoang [" << A ", " << B << "]" << endl;
    return 0;
}