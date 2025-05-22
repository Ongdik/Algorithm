#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> cnt(n+1, 1);
    cnt[0] = 0;
    
    for (int i=0; i<reserve.size(); i++) {
        int idx = reserve[i];
        cnt[idx]++;
    }
    
    for (int i=0; i<lost.size(); i++) {
        int idx = lost[i];
        cnt[idx]--;
    }
    
    for (int i=1; i<=n; i++) {
        if (cnt[i] == 0) {
            if (cnt[i-1] == 2) {
                cnt[i]++;
                cnt[i-1]--;
            }
            else if (i+1 <= n && cnt[i+1] == 2) {
                cnt[i]++;
                cnt[i+1]--;
            }
        }
    }
    
    for (int i=1; i<=n; i++) {
        if (cnt[i] > 0) answer++;
    }
    
    return answer;
}