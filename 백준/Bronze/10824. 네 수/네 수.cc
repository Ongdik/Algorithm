#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	long long sum = stoll(to_string(a) + to_string(b)) + stoll(to_string(c)+ to_string(d));
	cout << sum;
}