/*
Câu 5. Viết chương trình tính tổng của các số nguyên tố nằm trong khoảng [A, B] với A, B nhập 
vào từ bàn phím.
*/ 

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