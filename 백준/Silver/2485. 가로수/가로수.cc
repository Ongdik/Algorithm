#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, dist;
	cin >> n;
	vector<int> v;
	while (n--) {
		cin >> dist;
		v.push_back(dist);
	}

	int gcdVal = gcd(v[1] - v[0], v[2] - v[1]);
	for (int i = 1; i < v.size() - 1; i++) {
		gcdVal = gcd(v[i + 1] - v[i], gcdVal);
	}

	int cnt = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		cnt += ((v[i + 1] - v[i]) / gcdVal) - 1;
	}
	cout << cnt;
}