#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int val_idx = 0;
    if (ext == "code") val_idx = 0;
    else if (ext == "date") val_idx = 1;
    else if (ext == "maximum") val_idx = 2;
    else if (ext == "remain") val_idx = 3;
    
    int sort_idx = 0;
    if (sort_by == "code") sort_idx = 0;
    else if (sort_by == "date") sort_idx = 1;
    else if (sort_by == "maximum") sort_idx = 2;
    else if (sort_by == "remain") sort_idx = 3;
    
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