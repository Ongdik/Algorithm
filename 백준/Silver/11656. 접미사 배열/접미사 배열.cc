#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	cin >> str;

	vector<string> v;
	for (int i = 0; i < str.length(); i++) {
		v.push_back(str.substr(i, str.length()));
	}
	sort(v.begin(), v.end());
	for (string s : v) {
		cout << s << "\n";
	}
}