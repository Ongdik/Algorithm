#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

bool check = false;

void bfs(ll a, ll b) {
	queue<pair<ll, int>> q;
	q.push({ a,0 });

	while (!q.empty()) {
		ll na = q.front().first;
		int nextCnt = q.front().second + 1;
		q.pop();
		if (na > b) continue;

		if (na == b) {
			cout << nextCnt;
			check = true;
			return;
		}
		
		q.push({ na * 10 + 1,nextCnt });
		q.push({ na * 2,nextCnt });
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	bfs(a, b);
	if (!check) cout << -1;
}