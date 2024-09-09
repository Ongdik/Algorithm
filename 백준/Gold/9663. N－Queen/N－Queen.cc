#include <iostream>
#include <cmath>
using namespace std;

int n;
int ans = 0;
int col[15]{ 0 };

bool check(int idx) {
	for (int i = 1; i < idx; i++) {
		// x - x' == y - y' 이면 대각선 관계
		if (col[idx] == col[i] || abs(idx - i) == abs(col[idx] - col[i])) {
			return false;
		}
	}
	return true;
}

void BT(int idx) {
	if (idx == n + 1) {
		ans++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		col[idx] = i;
		if (check(idx)) {
			BT(idx + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	BT(1);
	cout << ans;
}