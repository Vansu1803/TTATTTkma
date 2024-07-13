/*
Câu 39. Cho mảng A nhập từ bàn phím gồm các số nguyên dương. Hãy viết chương trình tìm các 
cặp số (i,j) trong mảng A sao cho ước chung lớn nhất của chúng là một số nguyên tố.
Câu 40. Cho mảng A nhập từ bàn phím gồm các số nguyên dương. Hãy viết chương trình đếm 
các cặp số (i,j) trong mảng A sao cho ước chung lớn nhất của chúng là một số nguyên tố.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int random(int min, int max) {
    return min + rand() % (max + 1 - min);
}

int ucln(int a, int b) {
    int r;
    if (a >= b) {
        while (b > 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    } else {
        while (a > 0) {
            r = b % a;
            b = a;
            a = r;
        }
        return b;
    }
}

int kiemtranguyento(int n) {
    int t = 10, flag = 0;
    int i, s = 0;
    int a;
    int r = n - 1;
    while (r % 2 == 0) {
        s++;
        r = r / 2;
    }
    for (i = 0; i < t; i++) {
        a = random(2, n - 2);
        int b = 0;
        while (r >= pow(2, b)) {
            b++;
        }
        vector<int> k(b);
        int z = r;
        for (int m = 0; m < b; m++) {
            k[m] = z % 2;
            z = z / 2;
        }
        int y = 1, a1 = a;
        if (k[0] == 1) {
            y = a;
        }
        for (int j = 1; j < b; j++) {
            a1 = a1 * a1 % n;
            if (k[j] == 1) {
                y = y * a1 % n;
            }
        }
        if (y != 1 && y != n - 1) {
            int j = 1;
            while (j <= s - 1 && y != n - 1) {
                y = y * y % n;
                if (y == 1) {
                    flag++;
                    break;
                }
                j++;
            }
            if (y != n - 1) {
                flag++;
                break;
            }
        }
    }
    if (flag == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int i, j, n, dem = 0;
    cout << "Nhap so phan tu cua mang A: ";
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++) {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }
    cout << "Cac cap so la:\n";
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int r = ucln(a[i], a[j]);
            if (r > 3 && r % 2 == 1) {
                int b = kiemtranguyento(r);
                if (b == 1) {
                    cout << "(" << a[i] << "," << a[j] << ")\n";
                    dem++;
                }
            }
            if (r == 2 || r == 3) {
                cout << "(" << a[i] << "," << a[j] << ")\n";
                dem++;
            }
        }
    }
    cout << "So cap thoa man la " << dem;
    return 0;
}
