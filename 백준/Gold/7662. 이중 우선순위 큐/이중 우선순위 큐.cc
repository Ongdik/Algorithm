#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;

		// 1 2 3
		priority_queue<ll, vector<ll>, greater<ll>> minPq;
		// 3 2 1
		priority_queue<ll, vector<ll>, less<ll>> maxPq;
		map<ll, ll> cnt;

		while (k--) {
			string cmd;
			int val;
			cin >> cmd >> val;

			if (cmd == "I") {
				minPq.push(val);
				maxPq.push(val);
				cnt[val]++;
			}
			else if (cmd == "D") {
				if (val == -1) {
					while (!minPq.empty() && cnt[minPq.top()] == 0) {
						minPq.pop();
					}
					if (!minPq.empty()) {
						cnt[minPq.top()]--;
						minPq.pop();
					}
				}
				else {
					while (!maxPq.empty() && cnt[maxPq.top()] == 0) {
						maxPq.pop();
					}
					if (!maxPq.empty()) {
						cnt[maxPq.top()]--;
						maxPq.pop();
					}
				}
			}
		}

		while (!minPq.empty() && cnt[minPq.top()] == 0) {
			minPq.pop();
		}

		while (!maxPq.empty() && cnt[maxPq.top()] == 0) {
			maxPq.pop();
		}

		if (minPq.empty() || maxPq.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << maxPq.top() << " " << minPq.top() << "\n";
		}
	}	
}