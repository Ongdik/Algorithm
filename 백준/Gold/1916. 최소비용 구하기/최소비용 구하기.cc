#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int dist[1001]{ 0 };
// graph는 first : 다음 노드, seconde : 다음 노드로 가는 비용
vector<pair<int, int>> graph[1001];

void Dijkstra(int start) {
	fill(dist, dist + 1001, INF);

	// pq는 {비용, 노드 번호}
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

	int n, m, start, end, cost;
	cin >> n >> m;

	while (m--) {
		cin >> start >> end >> cost;
		graph[start].push_back({ end, cost });
	}

	cin >> start >> end;
	Dijkstra(start);

	cout << dist[end];
}