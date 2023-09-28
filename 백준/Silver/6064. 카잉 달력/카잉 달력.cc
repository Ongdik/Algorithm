#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n, x, y, t;
	cin >> t;
	int year = 0;
	while (t--) {
		cin >> m >> n >> x >> y;
		int res = -1;
		int maxYear = lcm(m, n);
		for (int i = x; i <= maxYear; i += m) {
			int ny = i % n;
			if (ny == 0) ny = n;
			if (ny == y) {
				res = i;
				break;
			}
		}
		cout << res << "\n";
	}
}