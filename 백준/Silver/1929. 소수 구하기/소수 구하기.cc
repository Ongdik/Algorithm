#include <iostream>
#include <cmath>
using namespace std;

int primeNum[1000001]{ 0 };

void primeNumber(int a) {
	for (int i = 2; i <= a; i++) {
		primeNum[i] = 1;
	}

	for (int i = 2; i <= sqrt(a); i++) {
		if (primeNum[i] == 0) continue;
		for (int j = i * i; j <= a; j += i) {
			primeNum[j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	primeNumber(m);
	for (int i = n; i <= m; i++) {
		if (primeNum[i] != 0) cout << i << "\n";
	}
}