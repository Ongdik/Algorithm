#include <iostream>
using namespace std;

#define ll long long

ll n, l, w, h;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> w >> h;

	double low = 0;
	double high = max(max(l, w), h);
	double ans = 0;
	
	for (int i = 0; i < 100; i++) {

		double mid = (low + high) / 2;

		if ((ll)(l / mid) * (ll)(w / mid) * (ll)(h / mid) < n) {
			high = mid;
		}
		else {
			low = mid;
		}
	}

	// 10자리 + 뒤에 10자리
	cout.precision(20);
	cout << low;
}