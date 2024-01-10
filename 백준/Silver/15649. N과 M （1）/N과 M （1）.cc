#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, m;
bool check[10]{ false };

void makeBT() {

	if (v.size() == m) {
		for (int i : v) cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (check[i]) continue;
		v.push_back(i);
		check[i] = true;
		makeBT();
		v.pop_back();
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	makeBT();
}