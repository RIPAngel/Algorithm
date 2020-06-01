#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;
ull n;
ull f () {
	ull i, res = 0;
	for (i = 1; i * i < n; ++i) {
		if (n % i == 0) {
            res += (i + n / i);
        }
	}
	if (i * i == n) {
            res += i;
    }
    return res;
}

int main () {
	cin >> n;
	cout << f();
	return 0;
}