#include <iostream>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll dp[91]{ 0,1 };
	for (int i = 2; i < 91; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int n;
	cin >> n;
	cout << dp[n];
}