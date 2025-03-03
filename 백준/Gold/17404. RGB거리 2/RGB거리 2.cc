#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> arr(n + 1, vector<int>(3, 0));
	vector<vector<int>> dp(n + 1, vector<int>(3, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 1000001;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == i) dp[1][j] = arr[1][j];
			else dp[1][j] = 1000001;
		}

		for (int j = 2; j <= n; j++) {
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + arr[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + arr[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + arr[j][2];
		}

		for (int j = 0; j < 3; j++) {
			if (j == i) continue;
			ans = min(ans, dp[n][j]);
		}
	}

	cout << ans;
}