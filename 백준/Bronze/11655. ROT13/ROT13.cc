#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	getline(cin, str);

	string ans = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			if ((str[i] + 13) <= 90) ans += (char)(str[i] + 13);
			else ans += (char)(65 + ((str[i] + 13) % 91));
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			if ((str[i] + 13) <= 122) ans += (char)(str[i] + 13);
			else ans += (char)(97 + ((str[i] + 13) % 123));
		}
		else ans += str[i];
	}
	cout << ans;
}