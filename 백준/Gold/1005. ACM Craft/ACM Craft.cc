#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologySort(const vector<vector<int>>& graph, const vector<int>& time,
	vector<int>& inDegree, vector<int>& delay, const int& n) {

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			delay[i] = time[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (const auto& next : graph[cur]) {
			if (--inDegree[next] == 0) {
				q.push(next);
			}
			
			delay[next] = max(delay[next], delay[cur] + time[next]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<vector<int>> graph(n + 1);
		vector<int> time(n + 1, 0);
		vector<int> inDegree(n + 1, 0);
		vector<int> delay(n + 1, 0);

		for (int i = 1; i <= n; i++) {
			cin >> time[i];
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			inDegree[y]++;
		}

		topologySort(graph, time, inDegree, delay, n);

		int w;
		cin >> w;
		cout << delay[w] << "\n";
	}
}