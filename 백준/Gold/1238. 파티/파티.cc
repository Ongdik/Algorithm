#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

vector<pair<int, int>> graph[1001];
int dist[1001]{ 0 };
int ans[1001]{ 0 };

void Dijkstra(int start) {
	fill(dist, dist + 1001, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int curNode = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if (dist[curNode] < curCost) continue;

		int size = graph[curNode].size();

		for (int i = 0; i < size; i++) {
			int nextNode = graph[curNode][i].first;
			int nextCost = graph[curNode][i].second + curCost;

			if (nextCost < dist[nextNode]) {
				pq.push({ nextCost, nextNode });
				dist[nextNode] = nextCost;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x, a, b, t;
	cin >> n >> m >> x;

	while (m--) {
		cin >> a >> b >> t;
		graph[a].push_back({ b,t });
	}

	for (int i = 1; i <= n; i++) {
		Dijkstra(i);
		ans[i] += dist[x];
	}

	Dijkstra(x);
	for (int i = 1; i <= n; i++) {
		ans[i] += dist[i];
	}

	sort(ans + 1, ans + n + 1);
	cout << ans[n];
}