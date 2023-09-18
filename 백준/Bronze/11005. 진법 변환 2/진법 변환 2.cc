#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	int b;
	cin >> n >> b;
	string str = "";

	while (n != 0) {
		int tmp = n % b;
		
		if (tmp < 10) {
			str += '0' + tmp;
		}
		else {
			tmp = tmp - 10 + 'A';
			str += tmp;
		}

		n /= b;
	}
	reverse(str.begin(), str.end());
	cout << str;
}