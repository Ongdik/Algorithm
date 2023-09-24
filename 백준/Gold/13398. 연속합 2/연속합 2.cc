#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll arr[100001]{ 0 };
ll dp[100001][2]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1][0] = arr[1];
	dp[1][1] = arr[1];
	ll maxVal = arr[1];

	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		maxVal = max(maxVal, max(dp[i][0], dp[i][1]));
	}

	cout << maxVal;
}

