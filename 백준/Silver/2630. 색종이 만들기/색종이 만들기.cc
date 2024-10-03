#include <iostream>
#include <algorithm>
using namespace std;

int arr[129][129]{ 0 };
int ans[2]{ 0 };

void solve(int r, int c, int size) {
	int num = arr[r][c];
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (num != arr[i][j]) {
				solve(r, c, size / 2);
				solve(r + size / 2, c, size / 2);
				solve(r, c + size / 2, size / 2);
				solve(r + size / 2, c + size / 2, size / 2);
				return;
			}
		}
	}
	ans[num]++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	solve(0, 0, n);

	cout << ans[0] << "\n" << ans[1];
}