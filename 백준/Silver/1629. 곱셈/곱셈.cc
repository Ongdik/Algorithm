#include <iostream>
using namespace std;

typedef long long ll;

ll a, b, c;

ll pow_mod(ll x, ll y) {
	if (y == 0) return 1;
	ll sub = pow_mod(x, y / 2);
	ll rst = sub * sub % c;
	if (y % 2) rst = rst * x % c;
	return rst;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	
	ll ans = pow_mod(a, b);
	cout << ans;
}