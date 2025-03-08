#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> arr(n + 1, 0);
	vector<int> cost(n + 1, 0);
	int sumCost = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		sumCost += cost[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(sumCost + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sumCost; j++) {
			if (j - cost[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + arr[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int i = 0; i <= sumCost; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			break;
		}
	}
}