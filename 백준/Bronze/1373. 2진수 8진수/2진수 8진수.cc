#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string binary, res;
	cin >> binary;
	int len = binary.length();
	int i = 0;
	if (len % 3 == 1) {
		cout << binary[0];
		i = 1;
	}
	else if (len % 3 == 2) {
		cout << ((binary[0] - '0') * 2) + (binary[1] - '0');
		i = 2;
	}
	for (i; i < len; i += 3) {
		cout << ((binary[i] - '0') * 4) + ((binary[i + 1] - '0') * 2) + ((binary[i + 2] - '0'));
 	}
}