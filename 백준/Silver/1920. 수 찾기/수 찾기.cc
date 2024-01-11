#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

void binarySearch(int a, int l, int h) {
	int idx = (l + h) / 2;
	if (h < l || idx < 0 || idx > v.size() - 1) {
		cout << 0 << "\n";
		return;
	}
	
	if (a > v[idx]) {
		l = idx + 1;
		binarySearch(a, l, h);
	}
	else if (a < v[idx]) {
		h = idx - 1;
		binarySearch(a, l, h);
	}
	else {
		cout << 1 << "\n";
		return;
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		binarySearch(x, 0, v.size() - 1);
	}
}