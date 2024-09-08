#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

// graph는 first:다음노드, second:다음노드까지의 비용
vector<pair<int,int>> graph[20001];
int dist[20001]{ 0 };

void Dijkstra(int start) {
	fill(dist, dist + 20001, INF);

	//pq : {비용, 노드번호}
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

	int V, E, k, u, v, w;
	cin >> V >> E >> k;

	while (E--) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	Dijkstra(k);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == 987654321) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}
}