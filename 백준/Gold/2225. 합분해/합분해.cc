#include <iostream>
using namespace std;

#define ll long long

ll MOD = 1000000000;
ll dp[201][201]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1;
	}
	for (int i = 1; i <= k; i++) {
		dp[1][i] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}
	cout << dp[n][k];
}