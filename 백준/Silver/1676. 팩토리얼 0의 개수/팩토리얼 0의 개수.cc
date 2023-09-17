#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 5; i <= n; i += 5) {
		if (i % 5 == 0) cnt++;
		if (i % 25 == 0) cnt++;
		if (i % 125 == 0) cnt++;
	}
	cout << cnt;
}