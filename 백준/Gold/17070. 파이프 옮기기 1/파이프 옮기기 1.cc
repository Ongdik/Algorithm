#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
bool visited[17][17]{ false };
int dr[3]{ 0,1,1 };
int dc[3]{ 1,1,0 };

void dfs(const vector<vector<int>>& graph, int r, int c, int flag) {
	
	if (r == n && c == n) {
		cnt++;
		return;
	}

	if (graph[r][c] != 1 && !visited[r][c]) {
		if (flag == 0) {
			for (int i = 0; i < 2; i++) {
				int nextR = r + dr[i];
				int nextC = c + dc[i];
				if (i == 1) {
					int r1 = nextR;
					int c1 = nextC - 1;
					int r2 = nextR - 1;
					int c2 = nextC;

					if (r1 <= n && c1 <= n && r2 <= n && c2 <= n) {
						if (graph[r1][c1] == 1 || graph[r2][c2] == 1) {
							continue;
						}
					}
					else continue;
				}
				if (nextR <= n && nextC <= n && graph[nextR][nextC] != 1) {
					visited[r][c] = true;
					dfs(graph, nextR, nextC, i);
					visited[r][c] = false;
				}
			}
		}
		else if (flag == 1) {
			for (int i = 0; i < 3; i++) {
				int nextR = r + dr[i];
				int nextC = c + dc[i];
				if (i == 1) {
					int r1 = nextR;
					int c1 = nextC - 1;
					int r2 = nextR - 1;
					int c2 = nextC;

					if (r1 <= n && c1 <= n && r2 <= n && c2 <= n) {
						if (graph[r1][c1] == 1 || graph[r2][c2] == 1) {
							continue;
						}
					}
					else continue;
				}
				if (nextR <= n && nextC <= n && graph[nextR][nextC] != 1) {
					visited[r][c] = true;
					dfs(graph, nextR, nextC, i);
					visited[r][c] = false;
				}
			}
		}
		else {
			for (int i = 1; i < 3; i++) {
				int nextR = r + dr[i];
				int nextC = c + dc[i];
				if (i == 1) {
					int r1 = nextR;
					int c1 = nextC - 1;
					int r2 = nextR - 1;
					int c2 = nextC;

					if (r1 <= n && c1 <= n && r2 <= n && c2 <= n) {
						if (graph[r1][c1] == 1 || graph[r2][c2] == 1) {
							continue;
						}
					}
					else continue;
				}
				if (nextR <= n && nextC <= n && graph[nextR][nextC] != 1) {
					visited[r][c] = true;
					dfs(graph, nextR, nextC, i);
					visited[r][c] = false;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}

	dfs(graph, 1, 2, 0);

	cout << cnt;
}