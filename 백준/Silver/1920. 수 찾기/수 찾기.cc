#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

void binarySearch(int l, int h, int data) {
	if (h < l) {
		cout << 0 << "\n";
		return;
	}
	int idx = (l + h) / 2;

	if (arr[idx] == data) {
		cout << 1 << "\n";
		return;
	}
	else if (arr[idx] < data) binarySearch(idx + 1, h, data);
	else binarySearch(l, idx - 1, data);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, data;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> data;
		binarySearch(0, n - 1, data);
	}

}