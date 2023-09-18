#include <iostream>
#include <cmath>
using namespace std;

int primeNumber[1000001]{ 0 };

void makePrime() {
	for (int i = 2; i < 1000001; i++) {
		primeNumber[i] = 1;
	}
	for (int i = 2; i < sqrt(1000001); i++) {
		if (primeNumber[i] == 0) continue;
		for (int j = i * i; j < 1000001; j += i) {
			primeNumber[j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	makePrime();
	while (t--) {
		cin >> n;
		int cnt = 0;
		for (int i = 2; i <= n / 2; i++) {
			if (primeNumber[i] != 0) {
				int tmp = n - i;
				if (primeNumber[tmp]) cnt++;
			}
		}
		cout << cnt << "\n";
	}
}