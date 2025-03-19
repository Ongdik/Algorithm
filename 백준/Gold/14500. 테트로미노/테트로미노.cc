#include <bits/stdc++.h>
using namespace std;

int ans;
int n, m;

int dr[4]{ 0,0,1,-1 };
int dc[4]{ 1,-1,0,0 };

void dfs(vector<vector<int>>& paper, vector<vector<bool>>& visited
	, const int& r, const int& c, int cnt, int sum) {

	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	if (!visited[r][c]) {
		sum += paper[r][c];
		for (int i = 0; i < 4; i++) {
			int nextR = r + dr[i];
			int nextC = c + dc[i];

			if (nextR < 0 || nextC < 0 || nextR >= n || nextC >= m) continue;

			visited[r][c] = true;
			dfs(paper, visited, nextR, nextC, cnt + 1, sum);
			visited[r][c] = false;
		}

	}

	// ㅓ
	if (c - 1 >= 0 && r - 1 >= 0 && r + 1 < n) {
		ans = max(ans, paper[r][c - 1] + paper[r - 1][c] + paper[r + 1][c] + paper[r][c]);
	}
	// ㅏ
	if (c + 1 < m && r - 1 >= 0 && r + 1 < n) {
	ans = max(ans, paper[r][c + 1] + paper[r - 1][c] + paper[r + 1][c] + paper[r][c]);
}
	// ㅗ
	if (r - 1 >= 0 && c - 1 >= 0 && c + 1 < m) {
		ans = max(ans, paper[r - 1][c] + paper[r][c - 1] + paper[r][c + 1] + paper[r][c]);
	}
	// ㅜ
	if (r + 1 < n && c - 1 >= 0 && c + 1 < m) {
		ans = max(ans, paper[r + 1][c] + paper[r][c - 1] + paper[r][c + 1] + paper[r][c]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<vector<int>> paper(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(paper, visited, i, j, 0, 0);
		}
	}
	
	cout << ans;
}