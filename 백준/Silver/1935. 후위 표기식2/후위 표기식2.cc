#include <iostream>
#include <stack>
using namespace std;

int arr[26]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, val;
	string str;
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		cin >> val;
		arr[i] = val;
	}

	stack<double> s;
	cout << fixed;
	cout.precision(2);
	for (int i = 0; i < str.length(); i++) {
		double x = 0, y = 0;
		if (str[i] >= 'A' && str[i] <= 'Z') {
			s.push(arr[str[i] - 'A']);
		}
		else {
			if (str[i] == '+') {
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				s.push(y + x);
			}
			else if (str[i] == '-') {
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				s.push(y - x);
			}
			else if (str[i] == '*') {
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				s.push(y * x);
			}
			else if (str[i] == '/') {
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				s.push(y / x);
			}
		}
	}
	cout << s.top();
}