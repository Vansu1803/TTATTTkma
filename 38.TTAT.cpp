/*
Câu 38. Tìm nghịch đảo của một số a trong trường 𝐹𝑝 với a và p được nhập từ bàn phím.   (a>b)
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, d, q, r, x, y, x1, x2, y1, y2;
    cout << "Nhập a và b với (a>b) \n";
    cout << "\nNhap a: "; cin >> a;
    cout << "\nNhap b: "; cin >> b;
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
        cout << "\n(d,x,y) = (" << d << "," << x << "," << y << ")\n";
        return 1;
    }
    // Khởi tạo các biến phụ trợ
    x1 = 0;
    x2 = 1;
    y1 = 1;
    y2 = 0;
    // Vòng lặp tính toán Euclid mở rộng
    while (b > 0) {
        q = a / b;
        r = a - q * b;
        x = x2 - q * x1;
        y = y2 - q * y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    //Cập nhật giá trị cho lần lặp kế tiếp
    d = a;
    x = x2;
    y = y2;
    cout << "\n(d,x,y) = (" << d << "," << x << "," << y << ")\n";
    return 0;
}
