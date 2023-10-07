#include <iostream>
using namespace std;

#define ll long long

bool isPrime(ll num) {
  if (num <= 1)
    return false;

  if (num == 2 || num == 3)
    return true;

  if (num % 2 == 0 || num % 3 == 0)
    return false;

  for (ll i = 5; i * i <= num; ++i) {
    if (num % i == 0 || num % (i + 2) == 0)
      return false;
  }

  return true;
}

int main() {
  ll N, n;
  cin >> N;

  while (N--) {
    cin >> n;
    while (!isPrime(n)) {
      n++;
    }
    cout << n << "\n";
  }
}