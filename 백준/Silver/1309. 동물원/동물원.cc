#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001]{ 0,3,7,17,41 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 5; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1] * 2) % 9901;
	}
	cout << dp[n];
}

