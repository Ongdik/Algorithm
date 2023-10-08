#include <iostream>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, cnt = 0;
	cin >> n;
	
	for (ll i = 1; i * i <= n; i++) cnt++;
	cout << cnt;
}