#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[10001];
bool visited[10001]{ false };
pair<int, int> ans[10001]{ {0,0} };
int n, m;
int cnt = 0;
int maxCnt = 0;

void dfs(int start) {
	if (visited[start]) return;

	visited[start] = true;
	cnt++;
	maxCnt = max(maxCnt, cnt);

	for (auto i : graph[start]) {
		if (!visited[i]) dfs(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		dfs(i);
		ans[i].first = maxCnt;
		ans[i].second = i;
		maxCnt = 0;
		cnt = 0;
		fill(visited, visited + 10001, false);
	}

	sort(ans + 1, ans + n + 1);
	
	int maxVal = ans[n].first;
	for (int i = 1; i <= n; i++) {
		if (maxVal <= ans[i].first) cout << ans[i].second << " ";
	}
}