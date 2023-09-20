#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k, n, x;
	cin >> k >> n;
	vector<int> v;
	while (k--) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	ll max = 0;
	ll l = 1;
	ll h = v.back();

	while (l <= h) {
		ll val = (l + h) / 2;
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			cnt += v[i] / val;
		}
		if (cnt >= n) {
			if (max < val) max = val;
			l = val + 1;
		}
		else h = val - 1;
	}
	cout << max;
}