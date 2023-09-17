#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	long long int a = -1, b = -1;
	bool check = false;

	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (i * i + j * j == n) {
				a = i;
				b = j;
				check = true;
				break;
			}
		}
		if (check) break;
	}

	if (a == -1 && b == -1) cout << "Impossible\n";
	else {
		cout << 0 << " " << 0 << "\n";
		cout << a << " " << b << "\n";
		cout << -b << " " << a << "\n";
		cout << -b+a << " " << a+b << "\n";
	}
}