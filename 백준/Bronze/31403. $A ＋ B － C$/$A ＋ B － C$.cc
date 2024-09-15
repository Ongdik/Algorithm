#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, b, c;
	cin >> a >> b >> c;

	int intAns = 0;
	int strAns = 0;
	intAns = stoi(a) + stoi(b) - stoi(c);
	strAns = stoi(a + b) - stoi(c);
	cout << intAns << "\n" << strAns;
}