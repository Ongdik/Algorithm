#include <iostream>
using namespace std;

int dp[1000001]{ 0,0,1,1 };

void makeDp() {
	for (int i = 4; i < 1000001; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	makeDp();
	int n;
	cin >> n;
	cout << dp[n];
}