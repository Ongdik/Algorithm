#include <iostream>
#include <map>
#include <cmath>
using namespace std;

char leftHand[14]{ 
   'q','w','e','r','t',
   'a','s','d','f','g',
   'z','x','c','v' };
pair<int, int> leftPosition[14]{ 
   {0,0},{0,1},{0,2},{0,3},{0,4},
   {1,0},{1,1},{1,2},{1,3},{1,4},
   {2,0},{2,1},{2,2},{2,3} };

char rightHand[12]{
   'y','u','i','o','p',
   'h','j','k','l',
   'b','n','m'
};
pair<int, int> rightPosition[12]{
   {0,5},{0,6},{0,7},{0,8},{0,9},
   {1,5},{1,6},{1,7},{1,8},
   {2,4},{2,5},{2,6} };

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);


   string str;
   char l, r;
   cin >> l >> r >> str;

   int l_position[2]{ 0 };
   int r_position[2]{ 0 };

   for (int i = 0; i < 14; i++) {
      if (l == leftHand[i]) {
         l_position[0] = leftPosition[i].first;
         l_position[1] = leftPosition[i].second;
      }
      if (i < 12) {
         if (r == rightHand[i]) {
            r_position[0] = rightPosition[i].first;
            r_position[1] = rightPosition[i].second;
         }
      }
   }

   int cnt = 0;
   for (int i = 0; i < str.length(); i++) {
      for (int j = 0; j < 14; j++) {
         if (str[i] == leftHand[j]) {
            cnt += (abs(l_position[0] - leftPosition[j].first) + abs(l_position[1] - leftPosition[j].second)) + 1;
            l_position[0] = leftPosition[j].first;
            l_position[1] = leftPosition[j].second;
         }
         if (j < 12) {
            if (str[i] == rightHand[j]) {
               cnt += (abs(r_position[0] - rightPosition[j].first) + abs(r_position[1] - rightPosition[j].second)) + 1;
               r_position[0] = rightPosition[j].first;
               r_position[1] = rightPosition[j].second;
            }
         }
      }
   }
   
   cout << cnt;

}