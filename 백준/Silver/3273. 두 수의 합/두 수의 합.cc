#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;

void two_pointer(vector<int> v, int x) {
	int size = v.size();
	int l = 0, r = v.size() - 1;

	while (l < r) {
		if (v[l] + v[r] < x) l++;
		else if (v[l] + v[r] > x) r--;
		else { cnt++; r--; }
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, data, x;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	cin >> x;
	two_pointer(v, x);
	cout << cnt;
}