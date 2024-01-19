#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   int n, k;
   cin >> n >> k;
   vector<int> h(n); vector<int> diff;
   for (int& height : h) cin >> height;
   for (int i = 0; i < n - 1; i++) diff.push_back(h[i + 1] - h[i]);

   sort(diff.begin(), diff.end());
   int ans = 0;
   for (int i = 0; i < n - k; i++) ans += diff[i];
   cout << ans;
}