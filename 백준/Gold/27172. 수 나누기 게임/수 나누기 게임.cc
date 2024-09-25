#include <iostream>
#include <cmath>
using namespace std;

//int primeNum[1000001]{ 0 };
//
//void makePrimeNum(int a) {
//	for (int i = 2; i <= a; i++) {
//		primeNum[i] = 1;
//	}
//
//	for (int i=2; i<=sqrt(a); i++) {
//		if (primeNum[i] == 0) continue;
//		for (int j = i * i; j <= a; j += i) {
//			primeNum[j] = 0;
//		}
//	}
//}

int arr[1000001]{ 0 };
bool check[1000001]{ false };
int score[1000001]{ 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		check[arr[i]] = true;
	}

	for (int i = 0; i < n; i++) {
		for (int j = (arr[i] * 2); j < 1000001; j += arr[i]) {
			if (check[j]) {
				score[arr[i]]++;
				score[j]--;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << score[arr[i]] << " ";
	}
}
