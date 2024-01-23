#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> val;
int n, m;

void makeBT() {
	if (v.size() == m) {
		for (int i : v) cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < val.size(); i++) {
		if (!v.empty() && v.back() > val[i]) continue;
		v.push_back(val[i]);
		makeBT();
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		val.push_back(a);
	}

	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	makeBT();
}