#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

vector<ll> v;
ll ans[3]{ 0 };
ll cmp = 3000000001;

void two_pointer() {
	int size = v.size();

	for (int i = 0; i < size - 2; i++) {
		int l = i + 1, r = size - 1;
		while (l < r) {
			ll sum = v[i] + v[l] + v[r];
			if (abs(sum) < cmp) {
				cmp = abs(sum);
				ans[0] = v[i]; ans[1] = v[l]; ans[2] = v[r];
			}
			if (sum < 0) l++;
			else if (sum > 0) r--;
			else return;
		}
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
	cout << ans[0] << " " << ans[1] << " " << ans[2];
}