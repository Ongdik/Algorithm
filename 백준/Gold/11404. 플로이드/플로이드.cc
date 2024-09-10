#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int n, m;
vector<pair<int, int>> graph[101];
int dist[101]{ 0 };

void Dijkstra(int start) {
	fill(dist, dist + 101, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// pq : {비용, 다음노드}
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

			if (dist[nextNode] > nextCost) {
				pq.push({ nextCost, nextNode });
				dist[nextNode] = nextCost;
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b, c;
	cin >> n >> m;

	while (m--) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) {
		Dijkstra(i);
		for (int i = 1; i <= n; i++) {
			if (dist[i] == 987654321) cout << 0 << " ";
			else cout << dist[i] << " ";
		}
		cout << "\n";
	}
}