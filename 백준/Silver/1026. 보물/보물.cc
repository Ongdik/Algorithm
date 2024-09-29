#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v1(n);
	vector<int> v2(n);

	for (int i = 0; i < n; i++) {
		cin >> v1[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> v2[i];
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), cmp);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (v1[i] * v2[i]);
	}
	cout << ans;
}