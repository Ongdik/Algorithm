#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int graph[50][50]{ 0 };
int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };
int total = 0;

void bfs(int x, int y) {
	if (graph[y][x] == 0) return;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int nextX = q.front().first;
		int nextY = q.front().second;
		q.pop();

		if (graph[nextY][nextX] == 0) continue;
		graph[nextY][nextX] = 0;

		for (int i = 0; i < 4; i++) {
			int nx = nextX + dx[i];
			int ny = nextY + dy[i];
			if (nx >= 0 && nx < 50 && ny >= 0 && ny < 50) {
				if (graph[ny][nx] != 0) q.push({ nx,ny });
			}
		}
	}
	total++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int m, n, k, x, y;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			graph[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				bfs(j, i);
			}
		}
		cout << total << "\n";
		total = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				graph[i][j] = 0;
			}
		}
	}
}