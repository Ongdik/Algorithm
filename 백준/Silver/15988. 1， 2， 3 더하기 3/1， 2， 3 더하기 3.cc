#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000009
#define ll long long

int n;
ll dp[1000001]{ 0,1,2,4 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 4; i < 1000001; i++) dp[i] = ((dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cout << dp[x] << "\n";
	}

	return 0;
}