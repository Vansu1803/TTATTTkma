/*
Câu 1 Một số gọi là Q-prime khi nó có đúng 4 ước số nguyên dương. Hãy viết chương trình in ra
các số Q-Prime nhỏ hơn hoặc bằng một số N cho trước nhập từ bàn phím. 
*/

#include <bits/stdc++.h>
#include <stdbool.h>

using namespace std;

bool check(int n){
    int dem=2; // co hai nghiem 1 va chinh no
    for(int i=2; i<= n/2; i++){
        if(n%i == 0){
            ++dem;
        }
    }
    return dem==4;
}

int main(){
    int n, dem;
    cout << "Nhap tu ban phim so nguyen N: "; cin >> n;
    cout << "Cac so P-rime: ";
    for(int i=0; i<=n; i++){
        if(check(i)==true){
            cout << i << " ";
        }
    }
    return 0;
}