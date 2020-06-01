#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstdio>
using namespace std;
const int IND = 45;
int gift[IND], first, second, third, sum, n, diff = INT_MAX, temp;

bool def (int a, int b, int c) {
    return (a >= b && b >= c);
}
void f (int attempt, int a, int b, int c, int d) {
    if (attempt < n) {
        f (attempt + 1, a + gift[attempt], b, c, (a + gift[attempt] - c));
        f (attempt + 1, a, b + gift[attempt], c, (a - c));
        f (attempt + 1, a, b, c + gift[attempt], (a - c - gift[attempt]));
    }
    else if (def (a, b, c) && d < diff) {
        first = a, second = b, third = c;
		temp = a;
        diff = d;
    }
    else if (def (a, b, c) && d == diff) {
        if (temp > a) {
            first = a, second = b, third = c;
			temp = a;
            diff = d;
        }  
    }
}
int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> gift[i];
		sum += gift[i];
	}
    sort (gift, gift + n);
    f (0, 0, 0, 0, 0);
	first = (sum - (second + third));
    cout << first << ' ' << second << ' ' << third;
    return 0;
}