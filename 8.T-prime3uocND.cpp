#include <bits/stdc++.h>
using namespace std;

bool check(int n){
    int dem = 2; // 1 va chinh no
    for(int i=2; i<=(n/2); i++){
        if(n%i == 0){
            ++dem;
        }
    }
    return dem ==3;
}
int main(){
    int N, dem;
    cout << "Nhap N tu ban phim: \n"; cin >> N;
    cout << "Cac so T-prime </= " << N << " la: " << endl;
    for(int i=1; i<=N; i++){
        if(check(i)){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}