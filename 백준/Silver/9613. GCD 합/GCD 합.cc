#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n, x;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		long long sum = 0;
		vector<int> v;
		for (int j = 0; j < n; j++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < v.size() - 1; j++) {
			for (int k = j + 1; k < v.size(); k++) {
				sum += gcd(v[j], v[k]);
			}
		}
		cout << sum << "\n";
	}
}