#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;

	vector<int> arr(n + 1, 0);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
		if (i != 1 && arr[i - 1] == arr[i]) dp[i-1][i] = 1;
	}

	for (int i = n - 2; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1) {
				dp[i][j] = 1;
			}
		}
	}

	cin >> m;

	while (m--) {
		int s, e;
		cin >> s >> e;

		if (dp[s][e] == 1) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}