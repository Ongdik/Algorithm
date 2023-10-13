#include <iostream>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		ll ans = 1;
		int r = 1;
		for (int i = m; i > m - n; i--) {
			ans *= i;
			ans /= r++;
		}
		cout << ans << "\n";
	}
}