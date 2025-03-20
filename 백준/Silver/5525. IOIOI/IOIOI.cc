#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	string str;
	cin >> n >> m >> str;

	int cnt = 0;

	for (int i = 0; i < str.length(); i++) {
		int length = 0;

		if (str[i] == 'O') continue;

		while (str[i + 1] == 'O' && str[i + 2] == 'I') {
			length++;

			if (length == n) {
				cnt++;
				length--;
			}
			i += 2;
		}

		length = 0;
	}

	cout << cnt;
}