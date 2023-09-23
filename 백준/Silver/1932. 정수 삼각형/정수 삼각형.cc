#include <iostream>
using namespace std;

int arr[501][501]{ 0 };
int dp[501][501]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j] + arr[i][j]);
		}
	}
	
	int maxVal = 0;
	for (int i = 1; i <= n; i++) {
		if (maxVal < dp[n][i]) maxVal = dp[n][i];
	}
	cout << maxVal;
}

