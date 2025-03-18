#include <bits/stdc++.h>
using namespace std;

#define MOD 10000

void bfs(int num, const int& b) {
	queue<pair<int, string>> q;
	q.push({ num,""});
	bool visited[10001]{ false };

	while (!q.empty()) {
		int curNum = q.front().first;
		string curStr = q.front().second;
		q.pop();

		if (curNum == b) {
			cout << curStr << "\n";
			return;
		}

		int D = (curNum * 2) % MOD;
		int S = ((curNum == 0) ? 9999 : curNum - 1);
		int L = (curNum % 1000) * 10 + (curNum / 1000);
		int R = (curNum % 10) * 1000 + (curNum / 10);

		if (!visited[D]) {
			visited[D] = true;
			q.push({ D, curStr + "D" });
		}
		if (!visited[S]) {
			visited[S] = true;
			q.push({ S, curStr + "S" });
		}
		if (!visited[L]) {
			visited[L] = true;
			q.push({ L, curStr + "L" });
		}
		if (!visited[R]) {
			visited[R] = true;
			q.push({ R, curStr + "R" });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;
		
		bfs(a, b);
	}
}