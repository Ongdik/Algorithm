#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int _video_len, _pos, _op_start, _op_end;

bool check(int pos) {
    if (_op_start <= pos && pos < _op_end) return true;
    return false;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    
    // 계산 용이하게 전체를 초로 변환
    _video_len = 60 * stoi(video_len.substr(0,2)) + stoi(video_len.substr(3,2));
    _pos = 60 * stoi(pos.substr(0,2)) + stoi(pos.substr(3,2));
    _op_start = 60 * stoi(op_start.substr(0,2)) + stoi(op_start.substr(3,2));
    _op_end = 60 * stoi(op_end.substr(0,2)) + stoi(op_end.substr(3,2));
    
    if (check(_pos)) _pos = _op_end;
    
    string answer = "";

    for (string cmd : commands) {
        if (cmd == "next") {
            _pos = min(_video_len, _pos + 10);
            if (check(_pos)) _pos = _op_end;
        }
        else {
            _pos = max(0 ,_pos - 10);
            if (check(_pos)) _pos = _op_end;
        }
    }
    
    // 초 -> 분:초 형식으로 변환
    
    int tmp;
    
    tmp = _pos / 60;
    string mm = (tmp < 10 ? "0" : "") + to_string(tmp);
    
    tmp = _pos % 60;
    string ss = (tmp < 10 ? "0" : "") + to_string(tmp);
    
    answer = mm + ":" + ss;
    
    return answer;
}