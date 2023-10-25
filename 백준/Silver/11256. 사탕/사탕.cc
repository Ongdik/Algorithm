#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, j, n, r, c;
	cin >> t;
	while (t--) {
		vector<int> v;
		cin >> j >> n;
		for (int i = 0; i < n; i++) {
			cin >> r >> c;
			v.push_back(r * c);
		}
		sort(v.begin(), v.end(), cmp);
		int cnt = 0;
		while (j > 0) {
			j -= v[cnt];
			cnt++;
		}
		cout << cnt << "\n";
	}
}