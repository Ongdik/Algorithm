#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int graph[101][101]{ 0 };
int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };
int n, m;

void bfs(int x, int y) {
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(x, y, 0));

	while (!q.empty()) {
		int nextX = get<0>(q.front());
		int nextY = get<1>(q.front());
		int cnt = get<2>(q.front());
		q.pop();

		if (nextX == m && nextY == n) {
			cout << cnt + 1;
			return;
		}
		if (graph[nextY][nextX] == 0) continue;
		graph[nextY][nextX] = 0;

		for (int i = 0; i < 4; i++) {
			int nx = nextX + dx[i];
			int ny = nextY + dy[i];

			if ((nx > 0 && nx <= m) && (ny > 0 && ny <= n)) {
				if (graph[ny][nx] != 0) q.push(make_tuple(nx, ny, cnt + 1));
 			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++) {
			graph[i][j] = (str[j - 1] - '0');
		}
	}
	bfs(1, 1);
}