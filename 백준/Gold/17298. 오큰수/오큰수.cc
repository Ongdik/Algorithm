#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<int> left;
	stack<int> right;
	stack<int> ans;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		left.push(x);
	}
	while (!left.empty()) {
		if (right.empty()) {
			ans.push(-1);
			right.push(left.top());
			left.pop();
		}
		else {
			while (!right.empty()) {
				if (right.top() > left.top()) {
					ans.push(right.top());
					right.push(left.top());
					left.pop();
					break;
				}
				else right.pop();
			}
		}
	}
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
}