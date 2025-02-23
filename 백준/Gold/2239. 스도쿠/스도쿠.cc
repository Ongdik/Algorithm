#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> sudoku(10, vector<int>(10, 0));
// 빈 칸인 r,c 좌표들 저장한 벡터
vector<pair<int, int>> emptySpace;

bool check(int r, int c, int val) {
	for (int i = 1; i <= 9; i++) {
		// 행 비교
		if (sudoku[r][i] == val && i != c) return false;

		// 열 비교
		if (sudoku[i][c] == val && i != r) return false;
	}

	// 3x3 체크
	int nextR = ((r - 1) / 3) * 3 + 1;
	int nextC = ((c - 1) / 3) * 3 + 1;
	for (int i = nextR; i < nextR + 3; i++) {
		for (int j = nextC; j < nextC + 3; j++) {
			if (i == r && j == c) continue;
			if (sudoku[i][j] == val) return false;
		}
	}

	return true;
}

void BT(int idx) {
	if (idx == emptySpace.size()) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << sudoku[i][j];
			}
			cout << "\n";
		}

		exit(0);
		// return 시 2번 반복됨 
		// 출력되었다면 끝이므로 exit로 나가주기
	}

	int r = emptySpace[idx].first;
	int c = emptySpace[idx].second;

	for (int val = 1; val <= 9; val++) {
		if (check(r, c, val)) {
			sudoku[r][c] = val;
			BT(idx + 1);
			sudoku[r][c] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 9; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= 9; j++) {
			sudoku[i][j] = (str[j - 1] - '0');
			if (sudoku[i][j] == 0) emptySpace.push_back({ i,j });
		}
	}

	BT(0);
}