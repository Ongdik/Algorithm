#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	getline(cin, str);
	stack<char> s;
	queue<char> q;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '<') {
			if (!s.empty()) {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
			}
			while (str[i] != '>') {
				q.push(str[i]);
				i++;
			}
			q.push('>');
		}
		else if (str[i] == ' ') {
			if (!s.empty()) {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << " ";
			}
		}
		else {
			if (!q.empty()) {
				while (!q.empty()) {
					cout << q.front();
					q.pop();
				}
			}
			s.push(str[i]);
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	while (!q.empty()) {
		cout << q.front();
		q.pop();
	}
}