#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	string str;
	while (n != 0) {
		if (n % -2 == 0) {
			str += "0";
			n /= -2;
		}
		else {
			str += "1";
			n = (n-1) / -2;
		}
	}
	for (int i = str.length() - 1; i >= 0; i--) {
		cout << str[i];
	}
}