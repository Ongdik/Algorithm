#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string s1, string s2) {
	if (s1.length() != s2.length()) return s1.length() < s2.length();
	return s1 < s2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	vector<string> v;
	while (n--) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (string s : v) {
		cout << s << "\n";
	}

}