/*
Câu 36. Lập trình tìm kiếm xâu S1 trong xâu S2 theo thuật toán Boyer-Moore, in giá trị của bảng. 
Trong trường hợp nào thì thuật toán Boyer-Moore được xem là cải tiến hơn thuật toán tìm kiếm 
vét cạn
*/

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char t[1000], p[1000];
    int l[127];
    cout << "\nNhap T: ";
    cin.getline(t, sizeof(t));
    cout << "\nNhap P: ";
    cin.getline(p, sizeof(p));
    int lap = 0;
    for (int i = 0; i < 127; i++) {
        l[i] = -1;
    }
    for (int i = 0; i < (int)strlen(p); i++) {
        l[(int)p[i]] = i;
    }
    int cong_them, i, j, d = 0;
    for (i = 0; i < (int)strlen(p); i++) {
        // Debug print statements
        // cout << p[i] << " ";
        // cout << l[(int)p[i]] << "\n";
    }
    i = strlen(p) - 1;
    j = strlen(p) - 1;
    d = 0;
    while (i < (int)strlen(t)) {
        d = 0;
        while (d != (int)strlen(p)) {
            if (t[i] == p[j]) {
                i--;
                j--;
                d++;
                lap++;
            } else {
                int min;
                if (j > 1 + l[(int)t[i]]) {
                    min = 1 + l[(int)t[i]];
                } else {
                    min = j;
                }

                if (min == 0)
                    i = i + strlen(p) - min;
                else
                    i = i + strlen(p) - min;

                j = strlen(p) - 1;
                lap++;
                break;
            }
        }
        if (d == (int)strlen(p)) {
            cout << "P co trong T, bat dau tai vi tri " << i + 2 << "\n";
            cout << "\nLap: " << lap;
            return 0;
        }
    }
    cout << "P khong co trong T\n";
    cout << "\nLap: " << lap;
    return 0;
}
