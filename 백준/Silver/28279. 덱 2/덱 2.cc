#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;
	int n, cmd, data;
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> data;
			dq.push_front(data);
		}
		else if (cmd == 2) {
			cin >> data;
			dq.push_back(data);
		}
		else if (cmd == 3) {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else cout << -1 << "\n";
		}
		else if (cmd == 4) {
			if (!dq.empty()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else cout << -1 << "\n";
		}
		else if (cmd == 5) cout << dq.size() << "\n";
		else if (cmd == 6) {
			if (!dq.empty()) cout << 0 << "\n";
			else cout << 1 << "\n";
		}
		else if (cmd == 7) {
			if (!dq.empty()) cout << dq.front() << "\n";
			else cout << -1 << "\n";
		}
		else if (cmd == 8) {
			if (!dq.empty()) cout << dq.back() << "\n";
			else cout << -1 << "\n";
		}
	}

}