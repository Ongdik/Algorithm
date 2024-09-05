#include <iostream>
#include <algorithm>
using namespace std;

int n;

int arr[100001][4]{ 0 };

int maxDp[4]{ 0 };
int minDp[4]{ 0 };

void makeDp() {
	for (int i = 2; i <= n; i++) {

		int tempMax[4]{ 0 };
		int tempMin[4]{ 0 };

		for (int j = 1; j <= 3; j++) {
			if (j == 1) {
				tempMax[1] = max(maxDp[1], maxDp[2]) + arr[i][j];
				tempMin[1] = min(minDp[1], minDp[2]) + arr[i][j];
			}
			else if (j == 2) {
				tempMax[2] = max(max(maxDp[1], maxDp[2]), maxDp[3]) + arr[i][j];
				tempMin[2] = min(min(minDp[1], minDp[2]), minDp[3]) + arr[i][j];
			}
			else {
				tempMax[3] = max(maxDp[2], maxDp[3]) + arr[i][j];
				tempMin[3] = min(minDp[2], minDp[3]) + arr[i][j];
			}
		}

		for (int j = 1; j <= 3; j++) {
			maxDp[j] = tempMax[j];
			minDp[j] = tempMin[j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= 3; i++) {
		maxDp[i] = arr[1][i];
		minDp[i] = arr[1][i];
	}

	makeDp();

	int maxVal = max(max(maxDp[1], maxDp[2]), maxDp[3]);
	int minVal = min(min(minDp[1], minDp[2]), minDp[3]);

	cout << maxVal << " " << minVal;
}