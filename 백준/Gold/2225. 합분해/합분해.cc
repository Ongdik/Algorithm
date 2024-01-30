#include <iostream>
using namespace std;

int N, K;
int dp[201][201];

/*
DP[a][b] = c
a개를 더해서 그 합이 b가 되는 경우의 수는 c개입니다.

점화식
DP[K][N]=DP[K-1][0] + DP[K-1][1] + ... + DP[K-1][N]
*/

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i <= K; i++) dp[1][i] = i;


	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}