#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;

	int size = (int)pow(2, n);
	int ans = 0;
	while (true) {
		if (r == 0 && c == 0) break;
		if (size != 1) size /= 2;
		if (r >= size && c >= size) {
			ans += (size * size) * 3;
			r -= size;
			c -= size;
		}
		else if (r >= size && c < size) {
			ans += (size * size) * 2;
			r -= size;
		}
		else if (r < size && c >= size) {
			ans += (size * size);
			c -= size;
		}
	}
	cout << ans;
}