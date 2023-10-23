#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll A[5][5]{ 0 };
ll ans[5][5]{ 0 };
ll tmp[5][5]{ 0 };
ll n, b;

void makeMatrix(ll ans1[5][5], ll ans2[5][5]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				tmp[i][j] += (ans1[i][k] * ans2[k][j]);
			}
			tmp[i][j] %= 1000;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans1[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
		ans[i][i] = 1;
	}

	while (b > 0) {
		if (b % 2 == 1) {
			makeMatrix(ans, A);
		}
		makeMatrix(A, A);
		b /= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}
