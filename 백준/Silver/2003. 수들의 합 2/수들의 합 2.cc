#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

void two_pointer(vector<int> v, int x) {
	int size = v.size();
	int l = 0, r = 1;

	int sum = v[0];

	while (true) {
		if (sum < x) {
			if (r + 1 > size) return;
			sum += v[r++];
		}
		else if (sum > x) sum -= v[l++];
		else {
			ans++; sum -= v[l]; l++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;
	int n, m, data;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> data;
		v.push_back(data);
	}
	two_pointer(v, m);
	cout << ans;
}