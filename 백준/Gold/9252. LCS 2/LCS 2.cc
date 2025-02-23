#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str1, str2;
	cin >> str1 >> str2;

	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int r = str1.size();
	int c = str2.size();
	string ansStr = "";
	while (r > 0 && c > 0) {
		if (dp[r][c] == dp[r - 1][c]) r--;
		else if (dp[r][c] == dp[r][c - 1]) c--;
		// 모두 다르면 문자 저장 & 왼쪽 대각으로 이동
		else {
			ansStr.push_back(str1[r - 1]);
			r--;
			c--;
		}
	}

	cout << dp[str1.size()][str2.size()] << "\n";
	for (int i = ansStr.size() - 1; i >= 0; i--) {
		cout << ansStr[i];
	}
}