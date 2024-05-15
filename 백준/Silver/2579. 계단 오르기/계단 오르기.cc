#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arr[301]{ 0 };
	int dp[301]{ 0 };
	int n, x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		arr[i] = x;
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << dp[n];
}