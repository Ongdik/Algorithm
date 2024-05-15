#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<char> v;

	v = { 'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v' };
	int n;
	string s;
	cin >> n >> s;

	bool check = false;

	for (int i = 0; i < v.size(); i++) {
		if (s[n- 1] == v[i]) {
			check = true;
			break;
		}
	}

	cout << (check ? 1 : 0);

	return 0;
}