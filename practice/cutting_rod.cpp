#include <bits/stdc++.h>

#define TEST 1

int solve(const int n, const int prices[]) {
  int dp[n + 1];
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int max = 0;
    for (int j = 0; j < i; j++) {
      int val = prices[j] + dp[i - j - 1];
      if (val > max) {
        max = val;
      }
    }
    dp[i] = max;
  }
  return dp[n];
}

int main() {

  std::istream *in = &std::cin;

  if (TEST) {
    in = new std::ifstream("input.txt");
    if (in->fail()) {
      std::cout << "errore" << std::endl;
      return 2;
    }
  }

  std::istream &cin = *in;

  // CODICE
  int n, t, prices[10000];
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> prices[i];
    }
    std::cout << solve(n, prices) << std::endl;
  }

  if (TEST)
    delete in;
}
