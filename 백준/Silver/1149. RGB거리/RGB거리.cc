#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][4]{ 0 };
int dp[1001][4]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i <= 3; i++) {
		dp[1][i] = arr[1][i];
	}

	for (int i = 2; i <= n; i++) {
		dp[i][1] = min(dp[i - 1][2] + arr[i][1], dp[i - 1][3] + arr[i][1]);
		dp[i][2] = min(dp[i - 1][1] + arr[i][2], dp[i - 1][3] + arr[i][2]);
		dp[i][3] = min(dp[i - 1][1] + arr[i][3], dp[i - 1][2] + arr[i][3]);
	}

	sort(dp[n] + 1, dp[n] + 4);
	cout << dp[n][1];
}

