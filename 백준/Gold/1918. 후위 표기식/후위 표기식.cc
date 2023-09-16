#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	stack<char> s;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') cout << str[i];
		else if (str[i] == '(') s.push('(');
		else if (str[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else if (str[i] == '+' || str[i] == '-') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/') {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}