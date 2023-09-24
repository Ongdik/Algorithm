#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001]{ 0 };
int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };
queue<pair<int, int>> q;
int m, n;

void bfs() {
	while (!q.empty()) {
		int nextX = q.front().first;
		int nextY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = nextX + dx[i];
			int ny = nextY + dy[i];

			if (nx >= 1 && nx <= m && ny >= 1 && ny <= n) {
				if (graph[ny][nx] == 0) {
					graph[ny][nx] = graph[nextY][nextX] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) q.push({ j,i });
		}
	}

	bfs();
	int day = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (graph[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (day < graph[i][j]) day = graph[i][j];
		}
	}
	cout << day - 1;
}