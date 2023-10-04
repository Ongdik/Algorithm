#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> input;
int numCnt[10001]{ 0 };

void makeBT() {
	if (v.size() > m) return;

	if (v.size() == m) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < input.size(); i++) {
		if (numCnt[input[i]] != 0) {
			v.push_back(input[i]);
			numCnt[input[i]]--;
			makeBT();
			v.pop_back();
			numCnt[input[i]]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (n--) {
		int data;
		cin >> data;
		input.push_back(data);
		numCnt[data]++;
	}
	sort(input.begin(), input.end());
	input.erase(unique(input.begin(), input.end()), input.end());

	makeBT();
}