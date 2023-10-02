#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> input;
int n, m;

void makeBT() {
    if (v.size() > m) return;

    if (v.size() == m) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < input.size(); i++) {
        if (!v.empty() && v.back() >= input[i]) continue;
        v.push_back(input[i]);
        makeBT();
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
    while (n--) {
        int x;
        cin >> x;
        input.push_back(x);
    }
    sort(input.begin(), input.end());
    makeBT();
}