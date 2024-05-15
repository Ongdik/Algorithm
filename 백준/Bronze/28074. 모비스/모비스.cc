#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<char> v;
	bool check[5]{ false };

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'M') check[0] = true;
		else if (str[i] == 'O') check[1] = true;
		else if (str[i] == 'B') check[2] = true;
		else if (str[i] == 'I') check[3] = true;
		else if (str[i] == 'S') check[4] = true;
	}

	for (int i = 0; i < 5; i++) {
		if (check[i] == false) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
}