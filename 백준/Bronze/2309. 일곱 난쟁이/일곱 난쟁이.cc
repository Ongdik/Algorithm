#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x;
	vector<int> v;
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> x;
		v.push_back(x);
		sum += x;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (v[i] + v[j]) == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << v[k] << "\n";
				}
				return 0;
			}
		}
	}
}