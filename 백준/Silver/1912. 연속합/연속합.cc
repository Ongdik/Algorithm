#include <iostream>
using namespace std;

long long arr[100001]{ 0 };
long long dp[100001]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int maxVal = -1001;

	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		if (maxVal < dp[i]) maxVal = dp[i];
	}
	cout << maxVal;
	
}