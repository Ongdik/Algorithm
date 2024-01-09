#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[100001]{ false };


void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,0 });

	while (!q.empty()) {
		int front = q.front().first;
		int time = q.front().second;
		q.pop();

		if (visited[front]) continue;
		visited[front] = true;
		if (front == b) {
			cout << time;
			return;
		}

		int plus = front + 1;
		int minus = front - 1;
		int multiple = front * 2;

		if (plus <= 100000) q.push({ plus,time + 1 });
		if (minus >= 0) q.push({ minus,time + 1 });
		if (multiple <= 100000) q.push({ multiple,time + 1 });
		

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	bfs(a, b);
}