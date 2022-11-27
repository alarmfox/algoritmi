#include <iostream>
#include <vector>
#include <cassert>

typedef std::vector<std::vector<int>> Matrix;

#define DEBUG 0

void print_matrix(const Matrix &m) {
  for (int i = 0; i<m.size(); ++i) {
    for (int j = 0; j < m[i].size(); ++j) {
      std::cout<<m[i][j];
    }
    std::cout<<std::endl;
  }
}

const int solution(const Matrix& M) {
  int area = 0, m = M.size(), n = M[0].size();
  Matrix dp(m + 1, std::vector<int>(n + 1));
  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (M[i][j] == 0) {
        dp[i][j] = dp[i][j + 1] + 1;
      }
      else {
        dp[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int row = i, columns = n; row < m && M[row][j] == 0; ++row) {
        columns = std::min(columns, dp[row][j]);
        area = std::max(area, (row - i + 1) * columns);
      }
    }

  }

  return area;
}

int main() {
  const std::vector<std::pair<Matrix, int>> inputs = {
    {
    {
      {0,1,0,1,1},
      {0,1,0,0,0},
      {0,0,0,0,0},
      {0,1,1,0,1},
    }, 6
    },
    {
    {
      {1,1,0,1,1},
      {0,1,1,0,0},
      {1,0,0,0,0},
      {0,1,1,0,1},
    }, 4
    },
    {
    {
      {1,1,0,1,1},
      {0,0,0,0,0},
      {1,0,0,1,0},
      {0,0,0,0,1},
    }, 6
    }
  };
  int res;
  for (const auto input : inputs ) {
    res = solution(input.first);
    assert(res == input.second);
  }
}