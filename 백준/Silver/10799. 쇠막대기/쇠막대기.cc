#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack<char> s;
	string str;
	cin >> str;
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') s.push('(');
		else {
			if (str[i - 1] == '(') {
				sum += s.size() - 1;
				s.pop();
			}
			else {
				s.pop();
				sum++;
			}
		}
	}
	cout << sum;
}