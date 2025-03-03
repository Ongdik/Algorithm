#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent(500001, 0);

int findParent(int u) {
	if (parent[u] == u) return u;
	return parent[u] = findParent(parent[u]);
}

void unionNode(int u, int v) {
	u = findParent(u);
	v = findParent(v);

	parent[v] = u;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		
		cnt++;

		if (findParent(u) == findParent(v)) {
			cout << cnt;
			return 0;
		}

		unionNode(u, v);
	}

	cout << 0;
}