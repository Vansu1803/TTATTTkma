/*
Câu 35. Cài đặt thuật toán kiểm tra số nguyên tố Miller-Rabin in ra kết luận về 1 số nguyên 
dương N nhập vào từ bàn phím với xác suất kết luận tương ứng sau thuật toán.  (345/4)
*/

#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <cmath>    

using namespace std;

int main() {
    int n, t, i;  
label:
    cout << "\nNhap n: ";
    cin >> n;
    
    if (n < 3 || n % 2 == 0) {
        cout << "\nSo n phai la so le lon hon hoac bang 3; xin moi nhap lai.\n";
        goto label;
    }
    cout << "So lan lap: ";
    cin >> t;
    // Tim r va s thoa man n-1 = r*2^s
    int r, s, trunggian;
    trunggian = n - 1;
    r = trunggian;
    s = 0;
    
    while (r > 0) {
        if (r % 2 == 1) {
            cout << "\ns = " << s << "; r = " << r;
            break;
        }
        r = trunggian / 2;
        trunggian = r;
        s++;
    }
    
    for (i = 1; i <= t; i++) {
        // Chon random so nguyen a, 2 <= a <= n-2
        int a = 0, ran;
        cout << "\n-------------\nLan lap " << i;
        while (a >= 0) {
            ran = rand();
            if ((ran >= 2) && (ran <= (n - 2)))
                break;
        }
        a = ran;
        cout << "\na = " << a << "\n";
        // Dung nhan binh phuong co lap de tinh y = a^r mod n
        int b, A, y, m;
        b = 1;
        A = a;
        m = n;
        if (r == 0)
            y = b; 
        
        // Chuyen nhi phan qua mang R[20]
        int nhiphan, R[20], j = 0, d = 0;
        nhiphan = r;
        
        while (nhiphan > 0) {
            R[j] = nhiphan % 2;
            nhiphan = (nhiphan - R[j]) / 2;
            cout << "R[" << j << "]=" << R[j] << "  ";
            j++;
        }
        cout << "\nj = " << j;
        
        // Ke bang
        if (r == 1)
            b = a;
        cout << "\nd R[i]  A   b";
        
        for (d = 0; d < j; d++) {
            A = (A * A) % m;
            if (R[d] == 1)
                b = (A * b) % m;
            cout << "\n" << d << "  " << R[d] << "   " << A << "  " << b;
        }
        
        cout << "\ny = b = " << b;
        y = b;
        
        if ((y != 1) && (y != n - 1)) {
            j = 1;
            
            while ((j <= (s - 1)) && (y != n - 1)) {
                y = (y * y) % n;
                
                if (y == 1) {
                    cout << "\nHop so.";
                    return 1;
                }
                
                j++;
            }
            
            if (y != n - 1) {
                cout << "\nHop so.";
                return 1;
            }
            else
                cout << "\nSo nguyen to.";
        }
        else
            cout << "\nSo nguyen to.";
    }
    
    return 0;
}
