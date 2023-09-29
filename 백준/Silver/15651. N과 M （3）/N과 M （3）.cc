#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, m;

void makeBT() {
    if (v.size() > m) return;

    if (v.size() == m) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        v.push_back(i);
        makeBT();
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
    makeBT();
}