#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
int parent[100001]{ 0 };

void dfs(int a) {
	for (int i = 0; i < v[a].size(); i++) {
		int next = v[a][i];
		if (parent[next] == 0) {
			parent[next] = a;
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}
}