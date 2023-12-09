#include <iostream>
#include <vector>
using namespace std;

int dp[50001]{ 0 };

void makeDp(int n) {
	for (int i = 1; i * i <= n; i++) {
		if (dp[n] == 0) dp[n] = dp[i * i] + dp[n - i * i];
		else dp[n] = min(dp[n], dp[i * i] + dp[n - i * i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i * i < 50001; i++) dp[i * i] = 1;
	int n;
	cin >> n;
	
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n];
	
	return 0;
}