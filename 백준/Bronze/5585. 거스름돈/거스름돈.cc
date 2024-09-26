#include <iostream>
using namespace std;

int arr[6]{ 500,100,50,10,5,1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	n = 1000 - n;

	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		if (n / arr[i] != 0) {
			cnt += (n / arr[i]);
			n %= arr[i];
		}
	}

	cout << cnt;
	
}