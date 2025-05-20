#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    // idx -> 찾는다면? 더 작은걸로 선택
    // 시간이 되나 100개에 100string -> 10000
    
    map<char, int> m; 
    
    for (int i=0; i<keymap.size(); i++) {
        for (int j=1; j<=keymap[i].size(); j++) {
            char c = keymap[i][j-1];
            m[c] = m[c] != 0 ? min(m[c], j) : j;
        }
    }
    
    for (int i=0; i<targets.size(); i++) {
        int cnt = 0;
        bool check = true;
        for (int j=0; j<targets[i].size(); j++) {
            char c = targets[i][j];
            if (m[c] == 0) {
                answer.push_back(-1);
                check = false;
                break;
            }
            else {
                cnt += m[c];
            }
        }
        if (check) answer.push_back(cnt);
    }
    
    return answer;
}