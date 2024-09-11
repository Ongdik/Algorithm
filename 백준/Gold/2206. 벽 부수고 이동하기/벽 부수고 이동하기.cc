#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int arr[1001][1001]{ 0 };
bool visited[1001][1001]{ false };
bool brokenVisited[1001][1001]{ false };
int dr[4]{ 1,-1,0,0 };
int dc[4]{ 0,0,1,-1 };
bool check = false;

void bfs(int row, int column) {
	// r, c, dist, 벽뚫기 가능여부
	queue<tuple<int, int, int, bool>> q;
	q.push({ row,column,true, 1 });

	check = false;

	while (!q.empty()) {
		int r = get<0>(q.front());
		int c = get<1>(q.front());
		int dist = get<2>(q.front());
		bool chance = get<3>(q.front());
		q.pop();

		if (chance) {
			if (visited[r][c]) continue;
		}
		else {
			if (brokenVisited[r][c]) continue;
		}
		
		if (chance) visited[r][c] = true;
		else brokenVisited[r][c] = true;

		if (r == n && c == m) {
			cout << dist;
			check = true;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nextR = r + dr[i];
			int nextC = c + dc[i];

			if (chance == false && arr[nextR][nextC] == 1) continue;

			if (nextR > 0 && nextC > 0 && nextR <= n && nextC <= m) {
				if (chance) {
					if (!visited[nextR][nextC]) {
						if (chance == true && arr[nextR][nextC] == 0) q.push({ nextR, nextC, dist + 1, true });
						else q.push({ nextR, nextC, dist + 1, false });
					}
				}
				else {
					if (!brokenVisited[nextR][nextC]) {
						if (arr[nextR][nextC] == 0) q.push({ nextR, nextC, dist + 1, false });
					}
				}
				
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = str[j - 1] - '0';
		}
	}

	bfs(1, 1);

	if (!check) cout << -1;
}