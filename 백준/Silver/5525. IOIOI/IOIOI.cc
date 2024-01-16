#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	string s;
	cin >> n >> m >> s;

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		if (s[i] == 'I') {
			while (s[i + 1] == 'O' && s[i + 2] == 'I') {
				i += 2;
				cnt++;
				if (cnt == n) {
					cnt--;
					ans++;
				}
			}
		}
	}
	cout << ans;
	
}