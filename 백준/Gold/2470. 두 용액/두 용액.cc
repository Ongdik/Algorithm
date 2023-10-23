#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

vector<ll> v;
ll cmp = 2000000001;
ll ans[2]{ 0 };

void two_pointer() {
	int l = 0, r = v.size() - 1;
	
	while (l < r) {
		ll sum = v[l] + v[r];
		if (abs(sum) < cmp) {
			cmp = abs(sum);
			ans[0] = v[l];
			ans[1] = v[r];
		}
		if (sum < 0) l++;
		else if (sum > 0) r--;
		else return;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, data;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> data;
		v.push_back(data);
	}
	sort(v.begin(), v.end());
	two_pointer();
	cout << ans[0] << " " << ans[1];
}