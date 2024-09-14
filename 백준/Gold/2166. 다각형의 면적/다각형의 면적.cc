#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;

vector<pair<double, double>> v;
double ans = 0;

void solve() {
	for (int i = 1; i < v.size() - 1; i++) {
		ans += (v[0].first * v[i].second + v[i].first * v[i + 1].second + v[i + 1].first * v[0].second);
		ans -= (v[i].first * v[0].second + v[i + 1].first * v[i].second + v[0].first * v[i + 1].second);
	}

	ans = abs(ans);
	ans /= 2;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		double x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	solve();

	cout << fixed;
	cout.precision(1);
	cout << ans;
}