#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int arr[1000001]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<pair<int,int>> left;
	stack<pair<int, int>> right;
	stack<int> ans;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		arr[x]++;
		v.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		left.push({ v[i],arr[v[i]] });
	}

	while (!left.empty()) {
		if (right.empty()) {
			ans.push(-1);
			right.push(left.top());
			left.pop();
		}
		else {
			while (!right.empty()) {
				if (right.top().second > left.top().second) {
					ans.push(right.top().first);
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