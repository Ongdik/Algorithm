#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v;
int n;
int res = 0;

void makeBT(int n) {
	if (v.size() == n) {
		cout << res << "\n";
		return;
	}
	for (int i = 1; i <= 9; i++) {
		res = (res * 10 + i);
		bool check = true;
		if (res == 1) check = false;
		for (int i = 2; i <= sqrt(res); i++) {
			if (res % i == 0) check = false;
		}
		if (check) {
			v.push_back(i);
			makeBT(n);
			v.pop_back();
			res /= 10;
		}
		else res /= 10;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	makeBT(n);
}