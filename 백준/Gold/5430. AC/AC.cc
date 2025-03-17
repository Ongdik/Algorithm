#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// R 뒤집는 수, D 버리는 수
	int t;
	cin >> t;

	while (t--) {
		string cmd;
		cin >> cmd;
		int n;
		cin >> n;
		string input;
		cin >> input;

		deque<int> deq;
		// check : true -> 정방향 , false -> 역방향
		bool check = true;

		string curNum = "";
		for (int i = 1; i < input.size() - 1; i++) {
			if (input[i] == ',') {
				deq.push_back(stoi(curNum));
				curNum = "";
			}
			else {
				curNum += input[i];
			}
		}

		if (curNum != "") deq.push_back(stoi(curNum));
		
		bool ifError = false;
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] == 'R') check = (!check);
			else if (cmd[i] == 'D') {
				if (deq.empty()) {
					cout << "error\n";
					ifError = true;
					break;
				}
				if (check) {
					deq.pop_front();
				}
				else {
					deq.pop_back();
				}
			}
		}

		
		if (!ifError) {
			cout << "[";
			while (!deq.empty()) {
				if (check) {
					cout << deq.front();
					deq.pop_front();
				}
				else {
					cout << deq.back();
					deq.pop_back();
				}

				if (!deq.empty()) cout << ",";
			}
			cout << "]\n";
		}

	}
}