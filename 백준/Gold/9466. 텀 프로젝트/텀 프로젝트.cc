#include <iostream>
#include <vector>
using namespace std;

void dfs(const int& idx, int& cnt, const vector<int>& student
	, vector<bool>& visited, vector<bool>& done) {

	visited[idx] = true;
	int next = student[idx];

	if (!visited[next]) {
		dfs(next, cnt, student, visited, done);
	}
	else if (!done[next]) {
		for (int i = next; i != idx; i = student[i]) {
			cnt++;
		}

		cnt++;
	}

	done[idx] = true;
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> student(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> student[i];
		}

		int cnt = 0;
		vector<bool> visited(n + 1, false);
		vector<bool> done(n + 1, false);

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) dfs(i, cnt, student, visited, done);
		}

		cout << n - cnt << "\n";
	}
}