#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string str1, string str2) {
	if (str1.length() != str2.length()) return str1.length() < str2.length();
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] >= '0' && str1[i] <= '9') sum1 += str1[i] - '0';
		if (str2[i] >= '0' && str2[i] <= '9') sum2 += str2[i] - '0';
	}
	if (sum1 != sum2) return sum1 < sum2;
	return str1 < str2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	string str;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), cmp);
	for (string s : v) {
		cout << s << "\n";
	}
}