#include <iostream>
using namespace std;

int dp[100001]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i * i <= n; i++) {
		dp[i * i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		if (dp[i] != 1) dp[i] = dp[i - 1] + 1;
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
		}
	}
	cout << dp[n];
}