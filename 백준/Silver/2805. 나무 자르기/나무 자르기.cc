#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

vector<ll> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, m, x;
	cin >> n >> m;
	while (n--) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	ll l = 0;
	ll h = v.back();
	ll maxHeight = 0;

	while (l <= h) {
		ll val = (l + h) / 2;
		ll sum = 0;

		for (int i = 0; i < v.size(); i++) {
			if (val < v[i]) sum += v[i] - val;
		}
		
		if (m <= sum) {
			if (maxHeight < val) maxHeight = val;
			l = val + 1;
		}
		else h = val - 1;
	}
	cout << maxHeight;
}