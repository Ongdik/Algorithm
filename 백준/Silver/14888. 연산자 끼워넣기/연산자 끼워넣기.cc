#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int operators[4]{ 0 };
int maxVal = -1000000001, minVal = 1000000001;
int n;

void makeBT(int num, int idx) {
   if (idx == n) {
      maxVal = max(maxVal, num);
      minVal = min(minVal, num);
      return;
   }

   for (int i = 0; i < 4; i++) {
      if (operators[i] > 0) {
         operators[i]--;
         if (i == 0) makeBT(num + v[idx], idx + 1);
         else if (i == 1) makeBT(num - v[idx], idx + 1);
         else if (i == 2) makeBT(num * v[idx], idx + 1);
         else if (i == 3) makeBT(num / v[idx], idx + 1);
         operators[i]++;
      }
   }

}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin >> n;
   int x;
   for (int i = 0; i < n; i++) {
      cin >> x;
      v.push_back(x);
   }
   for (int i = 0; i < 4; i++)   cin >> operators[i];
   makeBT(v[0], 1);
   cout << maxVal << "\n" << minVal;
}