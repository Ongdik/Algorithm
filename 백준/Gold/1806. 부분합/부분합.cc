#include <iostream>
using namespace std;

int arr[100001]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int l = 0;
	int h = 0;

	int ans = 100001;
	int curVal = arr[0];
	while (l <= h && h <= n) {
		if (curVal >= s) {
			if (l == h) {
				cout << 1;
				return 0;
			}

			ans = min(ans, (h - l + 1));
			curVal -= arr[l];
			l++;
		}
		else {
			h++;
			curVal += arr[h];
		}
	}

	if (ans == 100001) cout << 0;
	else cout << ans;
}
