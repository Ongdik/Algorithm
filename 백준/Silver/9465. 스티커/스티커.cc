#include <iostream>
#include <algorithm>
using namespace std;

int arr[2][100001]{ 0 };
int dp[2][100001]{ 0 };

int t, n;

void solve() {
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[0][1] = arr[0][1];
	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + arr[0][i];
		dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + arr[1][i];
	}

	cout << max(dp[0][n], dp[1][n]) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		solve();
	}
	
}

