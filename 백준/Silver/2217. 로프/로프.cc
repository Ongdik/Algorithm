#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
   return a > b;
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   int n;
   cin >> n;
   vector<int> v(n);
   for (int& weight : v) cin >> weight;
   sort(v.begin(), v.end(), cmp);
   int ans = v[0], curWeight;
   for (int i = 1; i < n; i++) {
      curWeight = v[i] * (i + 1);
      ans = max(ans, curWeight);
   }
   cout << ans;
}