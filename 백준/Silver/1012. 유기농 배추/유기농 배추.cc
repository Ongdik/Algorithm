#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int graph[51][51]{ 0 };
int dr[4]{ 1,-1,0,0 };
int dc[4]{ 0,0,-1,1 };
int ans = 0;

int m, n;

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r,c });

	while (!q.empty()) {
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		if (graph[curR][curC] == 0) continue;
		graph[curR][curC] = 0;

		for (int i = 0; i < 4; i++) {
			int nextR = curR + dr[i];
			int nextC = curC + dc[i];
			if (nextR >= 0 && nextC >= 0 && nextR < n && nextC < m) {
				if (graph[nextR][nextC] != 0) {
					q.push({ nextR, nextC });
				}
			}
		}
	}
	ans++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, k, x, y;
	cin >> t;

	while (t--) {
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			graph[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] == 0) continue;
				bfs(i, j);
			}
		}

		cout << ans << "\n";

		// 반복문 돌 때마다 초기화
		ans = 0;
		fill(&graph[0][0], &graph[0][0] + n * m, 0);
	}
}