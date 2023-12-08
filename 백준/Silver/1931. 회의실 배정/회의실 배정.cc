#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int>p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second < p2.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back({ start,end });
	}
	sort(v.begin(), v.end(), cmp);

	int start = v[0].first;
	int end = v[0].second;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (v[i].first < end) continue;
		end = v[i].second;
		cnt++;
	}
	cout << cnt;
}