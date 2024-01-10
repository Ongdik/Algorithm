#include <iostream>
using namespace std;

int dp[1001][1001]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[n][i];
	}
	cout << ans % 10007;
}