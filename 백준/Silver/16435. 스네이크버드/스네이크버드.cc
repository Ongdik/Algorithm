#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;
	vector<int> h(n);
	for (int &height : h) cin >> height;
	sort(h.begin(), h.end());
	for (int i = 0; i < n; i++) {
		if (l >= h[i]) l++;
		else break;
	}
	cout << l;
}