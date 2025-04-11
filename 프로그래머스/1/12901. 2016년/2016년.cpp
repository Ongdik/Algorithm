#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    int sum = 0;
    
    string day[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for (int i=1; i< a; i++) {
        sum += month[i];
    }
    
    sum += b - 1;
    
    answer = day[sum%7];
    
    return answer;
}