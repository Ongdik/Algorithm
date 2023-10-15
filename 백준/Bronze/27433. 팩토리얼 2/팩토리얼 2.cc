#include <iostream>
using namespace std;

#define ll long long
ll ans = 1;

int fac(int n) {
	if (n == 0) return ans;
	ans *= n;
	return fac(n - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	fac(n);
	cout << ans;

}