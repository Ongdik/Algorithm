#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool broken[10]{ false };

bool check(int number) {
    string str = to_string(number);

    for (int i = 0; i < str.length(); i++) {
        if (broken[str[i] - '0']) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, num;
    cin >> n >> m;

    while (m--) {
        cin >> num;
        broken[num] = true;
    }

    if (n == 100) {
        cout << 0;
        return 0;
    }

    int minCnt = abs(n - 100);

    for (int i = 0; i <= 1000000; i++) {
        if (check(i)) {
            int tmp = abs(n - i) + to_string(i).length();
            minCnt = min(minCnt, tmp);
        }
    }

    cout << minCnt;
}