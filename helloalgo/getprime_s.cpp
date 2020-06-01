#include <iostream>
using namespace std;
int n;

bool isPrime (int k) {
	for (int i = 2; i * i <= k; ++i) {
		if (k % i == 0) return false;
	}
	return true;
}

int main () {
	cin >> n;
	int v = 2, cnt = 0, res = 0;
	for (;;) {
		if (cnt == n) {
			cout << res;
			break;
		}
		if (isPrime (v)) {
			res = v;
			cnt++;
		}
		v++;
	}
	return 0;
}