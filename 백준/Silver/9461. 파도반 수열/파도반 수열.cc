#include <iostream>
using namespace std;

#define ll long long

ll dp[101]{ 0,1,1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 3; i <= 100; i++) dp[i] = dp[i - 3] + dp[i - 2];
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
}