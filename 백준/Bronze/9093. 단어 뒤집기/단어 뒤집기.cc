#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string str;
		stack<char> s;
		getline(cin, str);
		for (int j = 0; j < str.length(); j++) {
			if (str[j] != ' ') s.push(str[j]);
			else {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << " ";
			}
		}
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		cout << "\n";
	}

}