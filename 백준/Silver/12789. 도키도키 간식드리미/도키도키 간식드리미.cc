#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	queue<int> q;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		q.push(x);
	}

	int cnt = 1;
	while (!q.empty()) {
		if (q.front() == cnt) {
			q.pop();
			cnt++;
		}
		else if (!s.empty() && s.top() == cnt) {
			s.pop();
			cnt++;
		}
		else {
			s.push(q.front());
			q.pop();
		}
	}

	while (!s.empty()) {
		if (cnt == s.top()) {
			s.pop();
			cnt++;
		}
		else break;
	}

	if (s.empty()) cout << "Nice";
	else cout << "Sad";
}