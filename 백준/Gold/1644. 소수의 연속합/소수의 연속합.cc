#include <iostream>
#include <vector>
using namespace std;

int primeNum[4000001]{ 0 };
vector<int> v;
int cnt = 0;

void makePrime(int n) {
	for (int i = 2; i <= n; i++) primeNum[i] = 1;

	for (int i = 2; i * i <= n; i++) {
		if (primeNum[i] == 0) continue;
		for (int j = i * i; j <= n; j += i) primeNum[j] = 0;
	}

	for (int i = 2; i <= n; i++) if (primeNum[i] != 0) v.push_back(i);
}

void two_pointer(int x) {
	int size = v.size();
	int l = 0, r = 1;

	int sum = v[0];

	while (1) {
		if (sum < x) {
			if (r + 1 > size) return;
			sum += v[r++];
		}
		else if (sum > x) { sum -= v[l++]; }
		else { cnt++; sum -= v[l]; l++; }
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if (n == 1) { cout << 0; return 0; }
	makePrime(n);
	two_pointer(n);
	cout << cnt;
}