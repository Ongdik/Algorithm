#include <iostream>
using namespace std;

int dp[1001]{ 0,1,2,3,5 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 5; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}
	cout << dp[n];
}