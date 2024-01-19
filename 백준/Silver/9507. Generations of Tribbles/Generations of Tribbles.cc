#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

ll dp[68]{ 1,1,2,4 };

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   for (int i = 4; i < 68; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
   
   int t;
   cin >> t;

   for (int i = 0; i < t; i++) {
      int n;
      cin >> n;
      cout << dp[n] << "\n";
   }

   return 0;
}