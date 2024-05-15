#include <iostream>
using namespace std;

int dp[12]{ 0,1,2,4,7 };

void makeDp() {
	for (int i = 5; i < 12; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	makeDp();

	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n] << "\n";
	}
}