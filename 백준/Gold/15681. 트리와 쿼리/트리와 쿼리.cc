#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[100001];
bool visited[100001]{ false };
int dp[100001]{ 0 };

void dfs(int node, int parent) {
	if (visited[node]) return;
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int nextNode = graph[node][i];
		if (!visited[nextNode]) dfs(nextNode, node);
	}

	if (parent != -1) {
		dp[parent] += dp[node];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, r, q, u, v;
	cin >> n >> r >> q;
	fill(dp, dp + 100001, 1);

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(r, -1);

	while (q--) {
		cin >> u;
		cout << dp[u] << "\n";
	}
}