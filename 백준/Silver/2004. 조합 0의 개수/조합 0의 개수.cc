#include <iostream>
using namespace std;

#define ll long long

pair<ll, ll> count(ll x) {
	ll two = 0;
	ll five = 0;

	for (ll i = 2; i <= x; i *= 2) {
		two += x / i;
	}
	for (ll i = 5; i <= x; i *= 5) {
		five += x / i;
	}
	
	return {two, five};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long int n, m;
	cin >> n >> m;

	pair<ll, ll> N = count(n);
	pair<ll, ll> M = count(m);
	pair<ll, ll> NM = count(n - m);

	ll two = N.first - (M.first + NM.first);
	ll five = N.second - (M.second + NM.second);
	cout << min(two, five);
}