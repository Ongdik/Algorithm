#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i=0; i<s.length(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            int num = ((s[i] - 'A') + n) % 26;
            s[i] = (char)('A' + num);
        }
        else if ('a' <= s[i] && s[i] <= 'z') {
            int num = ((s[i] - 'a') + n) % 26;
            s[i] = (char)('a' + num);
        }
    }
    
    answer = s;
    
    return answer;
}