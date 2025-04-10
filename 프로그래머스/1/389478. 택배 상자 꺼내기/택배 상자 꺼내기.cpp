#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;

    vector<vector<int>> box(w + 1);

    for (int i = 1; i <= n; i++) {
        int a = i / w;
        int b = i % w;

        if (b == 0) {
            a--;
            if (a % 2 == 0) b = w;
            else b = 1;
        }
        else if (a % 2 == 1) {
            b = w - b + 1;
        }

        box[b].push_back(i);
    }

    int a = num / w;
    int b = num % w;
    if (b == 0) {
        a--;
        if (a % 2 == 0) b = w;
        else b = 1;
    }
    else if (a % 2 == 1) {
        b = w - b + 1;
    }

    for (int i = box[b].size() - 1; i >= 0; i--) {
        answer++;
        if (box[b][i] == num) break;
    }

    return answer;
}