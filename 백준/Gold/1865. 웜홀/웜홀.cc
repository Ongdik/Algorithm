#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

#define INF 987654321

void BellmanFord(const vector<tuple<int,int,int>>& graph
	, vector<int>& dist, int n) {

	// 벨만포드 알고리즘
	/*1. 출발 노드를 설정
	  2. 최단 거리 테이블을 초기화
	  3. 다음의 과정을(N - 1)번 반복
	    3-1. 간선 E개를 전부 하나씩 확인
	    3-2. 각 간선을 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신
		만약 음수 사이클이 존재하는지 확인하고싶다면 3번의 과정을 한번 더 수행 */
	
	for (int i = 0; i < n; i++) {
		for (int pos = 0; pos < graph.size(); pos++) {
			int from = get<0>(graph[pos]);
			int to = get<1>(graph[pos]);
			int cost = get<2>(graph[pos]);

			if (dist[from] + cost < dist[to]) {
				dist[to] = dist[from] + cost;
			}
		}
	}

	for (int pos = 0; pos < graph.size(); pos++) {
		int from = get<0>(graph[pos]);
		int to = get<1>(graph[pos]);
		int cost = get<2>(graph[pos]);

		if (dist[from] + cost < dist[to]) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m, w;
		cin >> n >> m >> w;

		vector<tuple<int,int,int>> graph;
		vector<int> dist(n + 1, INF);

		for (int i = 0; i < m; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			graph.push_back({ s,e,t });
			graph.push_back({ e,s,t });
		}

		for (int i = 0; i < w; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			graph.push_back({ s,e,-t });
		}

		BellmanFord(graph, dist, n);
	}
}