#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologySort(const vector<vector<int>>& graph
	, vector<int>& inDegree, const int& n) {

	queue<int> q;
	vector<int> ans;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			ans.push_back(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (const auto& next : graph[cur]) {
			if (--inDegree[next] == 0) {
				q.push(next);
				ans.push_back(next);
			}
		}
	}

	if (ans.size() != n) {
		cout << 0 << "\n";
		return;
	}
	
	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1);
	vector<int> inDegree(n + 1, 0);

	while (m--) {
		int cnt;
		cin >> cnt;

		vector<int> singer(cnt, 0);
		for (int i = 0; i < cnt; i++) {
			cin >> singer[i];
		}

		for (int i = 0; i < cnt - 1; i++) {
			int u = singer[i];
			int v = singer[i + 1];

			graph[u].push_back(v);
			inDegree[v]++;
		}
	}

	topologySort(graph, inDegree, n);
}