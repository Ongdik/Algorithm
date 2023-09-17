#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long int n;
	long long int ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ans *= i;
	}
	cout << ans;
}