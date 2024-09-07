#include <iostream>
#include <deque>
using namespace std;

int n, k;
bool visited[200001]{ false };

void bfs(int a) {
	deque<pair<int, int>> deq;
	deq.push_back({ a,0 });

	while (!deq.empty()) {
		int x = deq.front().first;
		int time = deq.front().second;
		deq.pop_front();

		if (visited[x]) continue;
		visited[x] = true;

		if (x == k) {
			cout << time;
			return;
		}

		int nextX[3]{ x - 1, x + 1, x * 2 };

		for (int i = 0; i < 3; i++) {
			if (nextX[i] < 0 || nextX[i] > 100000) continue;
			if (!visited[nextX[i]]) {
				if (i == 2) deq.push_front({ nextX[i],time });
				else deq.push_back({ nextX[i], time + 1 });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	bfs(n);
}