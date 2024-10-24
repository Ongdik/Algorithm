#include <iostream>
#include <vector>
using namespace std;

bool used[10]{ false };

void makeBT(vector<int>& v, int& n, int& m, int idx) {
	if (v.size() == m) {
		for (const auto& i : v) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i <= n; i++) {
		if (!used[i]) {
			v.push_back(i);
			used[i] = true;
			makeBT(v, n, m, i + 1);
			v.pop_back();
			used[i] = false;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v;
	makeBT(v, n, m, 1);
}