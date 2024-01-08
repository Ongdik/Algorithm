#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int graph[26][26]{ 0 };

int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };
vector<int> v;
int n;


void bfs(int x, int y) {
	if (graph[y][x] == 0) return;

	queue<pair<int, int>> q;
	q.push({ x,y });

	int cnt = 0;
	while (!q.empty()) {
		int nextX = q.front().first;
		int nextY = q.front().second;
		q.pop();

		if (graph[nextY][nextX] == 0) continue;
		graph[nextY][nextX] = 0;
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = nextX + dx[i];
			int ny = nextY + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
				if (graph[ny][nx] != 0) q.push({ nx, ny });
			}
		}

	}
	v.push_back(cnt);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string str;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			graph[i][j + 1] = str[j] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			bfs(j, i);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i : v) cout << i << "\n";
}