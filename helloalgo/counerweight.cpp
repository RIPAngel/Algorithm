#include <iostream>
using namespace std;
int n, data[] = {1, 3, 9, 27, 81, 243, 729}, end, chk[8];

void f (int num, int sum) {
    if (end) return;
    if (sum == num) {
        for (int i = 2; i > 0; --i) {
            for (int j = 0; j < 7; ++j) {
                if (chk[j] == i) {
                    cout << data[j] << ' ';
                }
            }
            if (i == 2)
                cout << "0 ";
            end = 1;
        }
    }
    for (int i = 0; i < 7; ++i) {
        if (chk[i] == 0) {
            chk[i] = 1, f (num, sum + data[i]); // 오른쪽 접시 사용
            chk[i] = 2, f (num + data[i], sum); // 왼쪽 접시 사용
            chk[i] = 0;
        }
    }
}

int main () {
    cin >> n;
    cout << n << " ";
    f (n, 0);
    return 0;
}