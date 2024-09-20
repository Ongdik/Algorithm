#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int parent[100001]{ 0 };
vector<tuple<int, int, int>> graph;
int ans = 0;

int findParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	parent[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b, c;
	cin >> n >> m;

	if (n == 2) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph.push_back({ c,a,b });
	}

	sort(graph.begin(), graph.end());

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	int cnt = 0;
	for (int i = 0; i < graph.size(); i++) {
		int cost = get<0>(graph[i]);
		int curNode = get<1>(graph[i]);
		int nextNode = get<2>(graph[i]);

		if (findParent(curNode) == findParent(nextNode)) continue;

		unionParent(curNode, nextNode);
		ans += cost;
		cnt++;

		if (cnt == n - 2) break;
	}

	cout << ans;
}