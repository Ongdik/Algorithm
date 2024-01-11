#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (binary_search(v.begin(), v.end(), x)) cout << 1 << " ";
		else cout << 0 << " ";
	}
}