#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

stack<int> s;
int ans = 0;
int minusVal = 0;
bool check = false;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	for (int i = 0; i <= str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			s.push(str[i] - '0');
		}
		else if (check) {
			int sSize = s.size();
			for (int i = 0; i < sSize; i++) {
				minusVal += (s.top() * pow(10, i));
				s.pop();
			}
		}
		else if (str[i] == '+') {
			int sSize = s.size();
			for (int i = 0; i < sSize; i++) {
				ans += (s.top() * pow(10, i));
				s.pop();
			}
		}
		else if (str[i] == '-') {
			int sSize = s.size();
			for (int i = 0; i < sSize; i++) {
				ans += (s.top() * pow(10, i));
				s.pop();
			}
			check = true;
		}
	}

	int sSize = s.size();

	if (check) {
		while (!s.empty()) {
			for (int i = 0; i < sSize; i++) {
				minusVal += (s.top() * pow(10, i));
				s.pop();
			}
		}
	}
	else {
		for (int i = 0; i < sSize; i++) {
			ans += (s.top() * pow(10, i));
			s.pop();
		}
	}

	cout << ans - minusVal;

}