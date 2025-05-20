#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    stack<int> s;
    
    for (int i=0; i<ingredient.size(); i++) {
        int idx = ingredient[i];
        s.push(idx);
        
        if (idx == 1 && s.size() > 3) {
            stack<int> tmp;
            tmp.push(s.top());
            s.pop();
            
            int tmpIdx = 3;
            for (int i=0; i<3; i++) {
                if (s.top() == tmpIdx) {
                    s.pop();
                    tmp.push(tmpIdx);
                    tmpIdx--;
                }
                else break;
            }
            if (tmpIdx != 0) {
                while(!tmp.empty()) {
                    s.push(tmp.top());
                    tmp.pop();
                }
            }
            else answer++;
        }
    }
   
    
    return answer;
}