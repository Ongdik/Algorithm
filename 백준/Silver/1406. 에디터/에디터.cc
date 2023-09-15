#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str, cmd;
	cin >> str;
	stack<char> left;
	stack<char> right;
	for (int i = 0; i < str.length(); i++) {
		left.push(str[i]);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "L") {
			if (left.empty()) continue;
			right.push(left.top());
			left.pop();
		}
		else if (cmd == "D") {
			if (right.empty()) continue;
			left.push(right.top());
			right.pop();
		}
		else if (cmd == "B") {
			if (left.empty()) continue;
			left.pop();
		}
		else if (cmd == "P") {
			char val;
			cin >> val;
			left.push(val);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
}