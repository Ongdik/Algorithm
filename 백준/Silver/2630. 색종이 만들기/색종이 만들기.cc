#include <iostream>
using namespace std;

int arr[128][128]{ 0 };
int n;
int zero = 0, one = 0;

void solve(int size, int x, int y) {
	int num = arr[y][x];

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (num != arr[i][j]) {
				solve(size / 2, x, y);
				solve(size / 2, x + size / 2, y);
				solve(size / 2, x, y + size / 2);
				solve(size / 2, x + size / 2, y + size / 2);
				return;
			}
		}
	}
	if (num == 0) zero++;
	else if (num == 1) one++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(n, 0, 0);
	cout << zero << "\n" << one;
}