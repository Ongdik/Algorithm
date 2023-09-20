#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> v;
map<string, int> stringMap;

bool cmp(string s1, string s2) {
	if (stringMap[s1] != stringMap[s2]) return stringMap[s1] > stringMap[s2];
	if (s1.length() != s2.length()) return s1.length() > s2.length();
	return s1 < s2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	string str;
	while (n--) {
		cin >> str;
		if (str.length() >= m) {
			if (stringMap.find(str) == stringMap.end()) {
				stringMap[str] = 0;
				v.push_back(str);
			}
			else stringMap[str]++;
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (string s : v) {
		cout << s << "\n";
	}

}