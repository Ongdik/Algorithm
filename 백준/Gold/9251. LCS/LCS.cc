#include <iostream>
using namespace std;

string str1, str2;
int LCS[1001][1001]{ 0 };

void makeLcs() {
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else {
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str1 >> str2;
	
	makeLcs();

	cout << LCS[str1.size()][str2.size()];
}