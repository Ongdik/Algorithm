#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000000

int dp[101][10]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][0] = dp[i - 1][j + 1];
			else if (j == 9) dp[i][9] = dp[i - 1][j - 1];
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= MOD;
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = (ans + dp[n][i]) % MOD;
	}
	cout << ans;

	return 0;
}