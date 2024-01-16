#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string cmd, str;
		int cnt;
		cin >> cmd >> cnt >> str;
		deque<int> dq;
		string tmp = "";
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= '0' && str[i] <= '9') tmp += str[i];
			else {
				if (tmp != "") dq.push_back(stoi(tmp));
				tmp = "";
			}
		}
		string val = "front";
		bool check = false;
		for (int i = 0; i < cmd.length(); i++) {
			if (cmd[i] == 'R') val = (val == "front" ? "back" : "front");
			else if (cmd[i] == 'D') {
				if (dq.empty()) {
					check = true;
					break;
				}
				if (val == "front") dq.pop_front();
				else dq.pop_back();
			}
		}
		if (check) cout << "error\n";
		else {
			cout << "[";
			while (!dq.empty()) {
				if (val == "front") {
					cout << dq.front();
					dq.pop_front();
				}
				else {
					cout << dq.back();
					dq.pop_back();
				}
				if (!dq.empty()) cout << ",";
			}
			cout << "]\n";
		}
	}
	
}