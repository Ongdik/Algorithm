#include <iostream>
using namespace std;

int arr[301]{ 0 };
int dp[301]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	}

	cout << max(dp[n - 2] + arr[n], dp[n - 3] + arr[n - 1] + arr[n]);
}