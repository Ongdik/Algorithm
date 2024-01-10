#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arr[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	string day[7]{ "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int x, y;
	cin >> x >> y;
	int res = 0;
	for (int i = 1; i < x; i++) res += arr[i];
	res += y;
	cout << day[res % 7];
	
}