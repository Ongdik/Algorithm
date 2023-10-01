#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> input;
vector<int> v;
bool used[10001]{ false };

void makeBT() {
	if (v.size() == m) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < input.size(); i++) {
		if (!v.empty() && input[i] == v.back()) continue;
		if (!used[input[i]]) {
			v.push_back(input[i]);
			used[input[i]] = true;
			makeBT();
			v.pop_back();
			used[input[i]] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int x;
	while (n--) {
		cin >> x;
		input.push_back(x);
	}
	sort(input.begin(), input.end());
	makeBT();
}