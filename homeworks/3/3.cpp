#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <cassert>

#define DEBUG 1
int solution(const std::string &s, const std::string& rev_s) {
    int m = s.length();
    int n = rev_s.length();
 
    int dp[m+1][n+1];

    for (int i = 0; i < m; ++i) {
      dp[0][i] = 0;
    }
 
    for (int i = 0; i < m; ++i) {
      dp[i][0] = 0;
    }

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (s[i-1] != rev_s[j-1]) {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
            else {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }
 
    return dp[m][n];
}
 
int main() {
    
    std::vector<std::pair<std::string, int>> inputs = {
        {"madam", 5},
        {"sulkjhgfas", 3},
        {"xqcow", 1}
    };

    int res;
    for (const auto input: inputs) {
      std::string rev(input.first);
      std::reverse(rev.begin(), rev.end());
      res = solution(input.first, rev);
      assert(res == input.second);
      if (DEBUG) {
        std::cout<<"input: "<<input.first<< " valore atteso: " << input.second << " risultato: "  << res << std::endl;
      }
    }
    return 0;
}