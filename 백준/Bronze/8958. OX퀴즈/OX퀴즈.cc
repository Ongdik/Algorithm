#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	string str;
	cin >> t;
	while (t--) {
		cin >> str;
		int total = 0;
		int tmp = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'O') tmp++;
			else tmp = 0;
			total += tmp;
		}
		cout << total << "\n";
	}
}