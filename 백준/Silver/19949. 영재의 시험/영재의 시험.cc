#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> ans;
int cnt = 0;

void makeBT(int score) {
	if (v.size() == 10) {
		if (score >= 5) cnt++;
		return;
	}
	for (int i = 1; i < 6; i++) {
		int nextScore = score;
		if (v.size() <= 1) {
			v.push_back(i);
			if (v[v.size() - 1] == ans[v.size() - 1]) nextScore++;
			makeBT(nextScore);
			v.pop_back();
		}
		else {
			if (v[v.size() - 1] == i && v[v.size() - 2] == i) continue;
			v.push_back(i);
			if (v[v.size() - 1] == ans[v.size() - 1]) nextScore++;
			makeBT(nextScore);
			v.pop_back();
		}
	}

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		ans.push_back(x);
	}
	makeBT(0);
	cout << cnt;
}