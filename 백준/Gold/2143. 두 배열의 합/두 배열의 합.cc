#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t;
	int n, m;
	cin >> t;

	cin >> n;
	vector<ll> v1(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v1[i];
	}

	cin >> m;
	vector<ll> v2(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> v2[i];
	}

	vector<ll> sumV1;
	vector<ll> sumV2;

	for (int i = 0; i < n; i++) {
		int sum = v1[i];
		sumV1.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += v1[j];
			sumV1.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++) {
		int sum = v2[i];
		sumV2.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += v2[j];
			sumV2.push_back(sum);
		}
	}

	sort(sumV2.begin(), sumV2.end());

	ll ans = 0;

	for (int i = 0; i < sumV1.size(); i++) {
		ll diff = t - sumV1[i];

		auto start = lower_bound(sumV2.begin(), sumV2.end(), diff);
		auto end = upper_bound(sumV2.begin(), sumV2.end(), diff);

		ans += (end - start);
	}

	cout << ans;
}