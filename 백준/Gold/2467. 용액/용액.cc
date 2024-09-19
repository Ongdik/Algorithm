#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

ll ans = 9876543210;
int arr[100001]{ 0 };
ll val1 = 0;
ll val2 = 0;

void binarySearch(int low, int high) {
	while (low < high) {
		int curVal = arr[low] + arr[high];
		if (curVal == 0) {
			val1 = arr[low];
			val2 = arr[high];
			return;
		}
		if (abs(curVal) < ans) {
			ans = abs(curVal);
			val1 = arr[low];
			val2 = arr[high];
		}
		if (curVal < 0) {
			low++;
		}
		else {
			high--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	binarySearch(0, n - 1);

	cout << val1 << " " << val2;
}