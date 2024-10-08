#include <iostream>
using namespace std;

int n, m;

int arr[1025][1025]{ 0 };
int dp[1025][1025]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int x1, y1, x2, y2;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) + arr[i][j];
		}
	}


	while (m--) {
		cin >> x1 >> y1 >> x2 >> y2;

		int ans = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];

		cout << ans << "\n";
	}

}