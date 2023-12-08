#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n); vector<int> dp(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] == 0) dp[i] = dp[i + 1] + 1;
		else if (i + arr[i] >= n - 1) dp[i] = 1;
		else dp[i] = dp[i + arr[i] + 1] + 1;
	}

	for (int i : dp) cout << i << " ";

}