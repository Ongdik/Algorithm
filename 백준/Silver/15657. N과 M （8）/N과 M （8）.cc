#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> input;
int n, m;

void makeBT() {
	if (v.size() == m) {
		for (int i = 0; i < m; i++) cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!v.empty()) if (v.back() > input[i]) continue;
		v.push_back(input[i]);
		makeBT();
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		input.push_back(num);
	}
	sort(input.begin(), input.end());

	makeBT();
}