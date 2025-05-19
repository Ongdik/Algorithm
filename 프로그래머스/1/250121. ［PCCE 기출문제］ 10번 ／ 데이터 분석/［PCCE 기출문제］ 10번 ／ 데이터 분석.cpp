#include <string>
#include <vector>
#include <algorithm>
// unordered_map 활용한 풀이
#include <unordered_map>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    unordered_map<string, int> m{{"code",0}, {"date",1}, {"maximum",2}, {"remain",3}};
    
    int val_idx = m[ext];
    int sort_idx = m[sort_by];
    
    for (int i=0; i<data.size(); i++) {
        if (data[i][val_idx] < val_ext) answer.push_back(data[i]);
    }
    
    // 람다함수 기억하기
    sort(answer.begin(), answer.end(), 
         [sort_idx](vector<int> a, vector<int> b){
             return a[sort_idx] < b[sort_idx];
         });
    
    return answer;
}