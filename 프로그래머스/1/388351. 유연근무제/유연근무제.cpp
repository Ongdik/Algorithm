#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    // 출근 인정 시간
    vector<int> v(schedules.size(), 0);
    for (int i=0; i<v.size(); i++) {
        int hour = schedules[i] / 100;
        int minute = (schedules[i] % 100) + 10;
        
        if (minute >= 60) {
            hour++;
            minute -= 60;
        }
        
        v[i] = hour*100 + minute;
    }

    for (int i=0; i<timelogs.size(); i++) {
        bool check = true;
        // 오답이유 -> startDay부터 금요일까지가 아니라 startDay부터 일주일임
        int cnt = startday - 1;        

        for (int j=0; j<7; j++) {
            if (cnt % 7 >= 5) {
                cnt++;
                // 오답 이유 -> continue시 43번째 줄 cnt++ 동작안함
                continue;
            }
            
            int curTime = timelogs[i][j];
            
            if (curTime > v[i]) {
                check = false;
                break;
            }
            
            cnt++;
        }
        
        if (check) answer++;
    }
    
    return answer;
}