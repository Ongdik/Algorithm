#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, d, k, c;
	cin >> n >> d >> k >> c;

	vector<int> sushi(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		vector<bool> check(d + 1, false);
		int cnt = 0;
		int duplication = 0;
		int coupon = 1;

		for (int j = i; j < i + k; j++) {
			if (check[sushi[j % n]]) {
				duplication++;
			}

			if (sushi[j % n] == c) coupon = 0;

			cnt++;
			check[sushi[j % n]] = true;
		}

		ans = max(ans, cnt - duplication + coupon);
	}

	cout << ans;
}