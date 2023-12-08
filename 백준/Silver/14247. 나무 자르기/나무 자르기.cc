#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n;
	vector<int> h(n); vector<int> a(n);
	vector<pair<int, int>> tree;
	ll ans = 0;
	for (int& height : h) cin >> height;
	for (int& plus : a) cin >> plus;
	for (int i = 0; i < n; i++) tree.push_back({ h[i], a[i] });

	sort(tree.begin(), tree.end(), cmp);
	for (int i = 0; i < n; i++) {
		ans += (tree[i].first + (tree[i].second * i));
	}
	cout << ans;

}