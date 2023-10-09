#include <iostream>
using namespace std;

int primeNum[246913]{ 0 };

void makePrime() {
	for (int i = 2; i < 246913; i++) {
		primeNum[i] = 1;
	}

	for (int i = 2; i * i < 246913; i++) {
		if (primeNum[i] == 0) continue;
		for (int j = i * i; j < 246913; j += i) primeNum[j] = 0;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	makePrime();
	while (true) {
		cin >> n;
		if (n == 0) return 0;
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) if (primeNum[i] != 0) cnt++;
		cout << cnt << "\n";
	}
}