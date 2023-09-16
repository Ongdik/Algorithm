#include <iostream>
#include <cmath>
using namespace std;

int primeNum[1000001]{ 0 };

void makePrime() {
	for (int i = 2; i <= 1000000; i++) {
		primeNum[i] = 1;
	}

	for (int i = 2; i <= sqrt(1000000); i++) {
		if (primeNum[i] == 0) continue;
		for (int j = i * i; j <= 1000000; j += i) {
			primeNum[j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	makePrime();
	while (true) {
		cin >> n;
		if (n == 0) break;

		bool check = false;
		int x = 0, y = 0;
		for (int i = 2; i <= 500000; i++) {
			if (primeNum[i] != 0) {
				x = i;
				y = n - i;
				if (primeNum[y]) {
					check = true;
					break;
				}
			}
		}
		if (check) cout << n << " = " << x << " + " << y << "\n";
		else cout << "Goldbach's conjecture is wrong.\n";
	}
}