#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	string tmp = "";
	cin >> str;
	bool check = false;
	int ans = 0;
	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (check) ans -= stoi(tmp);
			else ans += stoi(tmp);
			tmp = "";
			if (str[i] == '-') check = true;
		}
		else tmp += str[i];
	}
	cout << ans;
}