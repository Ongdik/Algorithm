#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(string s1, string s2) {
	for (int i = 1; i <= min(s1.length(), s2.length()); i++) {
		if (s1.substr(s1.size() - i) == s2.substr(0, i)) return true;
		if (s2.substr(s2.size() - i) == s1.substr(0, i)) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string str;
	vector<string> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}
	int cnt = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i+1; j < v.size(); j++) {
			if (check(v[i], v[j])) cnt++;
		}
	}
	cout << cnt;
}