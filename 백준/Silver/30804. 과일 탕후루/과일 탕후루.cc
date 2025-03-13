#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> cnt(10, 0);
	int n;
	cin >> n;

	int types = 0;
	queue<int> q;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int num;

		cin >> num;

		q.push(num);

		if (cnt[num]++ == 0) {
			types++;
		}

		while (types > 2) {
			num = q.front();
			q.pop();

			if (--cnt[num] == 0) {
				types--;
			}
		}

		ans = max(ans, static_cast<int>(q.size()));
	}

	cout << ans;
}