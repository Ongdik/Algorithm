#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<pair<int, int>> graph[10001];
bool visited[10001]{ false };
int node = 0;
int ans = 0;

void dfs(int x, int dist) {
	if (visited[x]) return;
	visited[x] = true;

	if (ans < dist) {
		node = x;
		ans = dist;
	}

	for (int i = 0; i < graph[x].size(); i++) {
		int nextX = graph[x][i].first;
		int nextDist = graph[x][i].second + dist;
		if (!visited[nextX]) dfs(nextX, nextDist);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int p, c, w;
		cin >> p >> c >> w;
		graph[p].push_back({ c,w });
		graph[c].push_back({ p,w });
	}

	dfs(1, 0);
	ans = 0;
	memset(visited, false, sizeof(visited));
	dfs(node, 0);
	cout << ans;
}