#include <iostream>
#include <vector>
using namespace std;

string str[64]{ "" };

void solve(int size, int y, int x) {
	char c = str[y][x];

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (c != str[i][j]) {
				cout << "(";
				solve(size / 2, y, x);
				solve(size / 2, y, x + size / 2);
				solve(size / 2, y + size / 2, x);
				solve(size / 2, y + size / 2, x + size / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> str[i];
	solve(n, 0, 0);
}
