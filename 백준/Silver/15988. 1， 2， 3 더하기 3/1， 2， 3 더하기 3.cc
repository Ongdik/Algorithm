#include <iostream>
using namespace std;

#define ll long long

ll dp[1000001]{ 0,1,2,4 };
ll MOD = 1000000009;

void makeDp() {
	for (int i = 4; i < 1000001; i++) {
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	makeDp();

	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> x;
		cout << dp[x] << "\n";
	}
}

