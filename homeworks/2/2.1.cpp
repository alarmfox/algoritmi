#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrix;

#define DEBUG 0

std::ostream& print_matrix(const Matrix &m, std::ostream& out) {
  for (int i = 0; i<m.size(); ++i) {
    for (int j = 0; j < m[i].size(); ++j) {
      out<<m[i][j];
    }
    out<<std::endl;
  }
  return out;
}


bool is_in(const int start, const int end, const int value) {
  return value <= end && value >= start;
}

bool is_valid(const Matrix& m, int x, int y, const Matrix& visited) {
  const int rows = m.size(), columns = m[0].size();

  if (!is_in(0, rows -1, x) || !is_in(0, columns-1, y)) {
    return false;
  }

  if (visited[x][y] == 1) {
    return false;
  }

  if (
    (is_in(0, rows-1, x+1) && m[x+1][y] == 0) || 
    (is_in(0, rows-1, x-1) && m[x-1][y] == 0) || 
    (is_in(0, columns-1, y+1) && m[x][y+1] == 0) ||
    (is_in(0, columns-1, y-1) && m[x][y-1] == 0)
    ) {
    return false;
  }

  return true;
}

void find_min_path(const Matrix& m, Matrix & visited, int start_x, int start_y, int end_x, int end_y, int &res, int &final_length) {
  if (start_x == end_x && start_y == end_y ) {
    if (res < final_length) {
      final_length = res;

    }
    return;
  }

  visited[start_x][start_y] = 1;
  res++;

  if (DEBUG) {
    print_matrix(visited, std::cout);
    std::cout<<std::endl;
  }

  // andiamo sotto
  if (is_valid(m, start_x+1, start_y, visited)) {
    find_min_path(m, visited, start_x+1, start_y, end_x, end_y, res, final_length);
  } 

  // andiamo a destra
  if (is_valid(m, start_x, start_y+1, visited)) {
    find_min_path(m, visited, start_x, start_y+1, end_x, end_y, res, final_length);
  } 

  // andiamo sopra
  if (is_valid(m, start_x-1, start_y, visited)) {
    find_min_path(m, visited, start_x-1, start_y, end_x, end_y, res, final_length);
  } 

  // andiamo a sinistra
  if (is_valid(m, start_x, start_y-1, visited)) {
    find_min_path(m, visited, start_x, start_y-1, end_x, end_y, res, final_length);
  } 

  visited[start_x][start_y] = 0;

  res--;
  
}

void solution(const Matrix& m) {
  const int last_column = m[0].size() -1;
  int start_x, start_y, end_x, end_y, res = 0, final_length = INT_MAX;
  
  for (int i = 0; i < m.size(); ++i) {
    start_x = i;
    start_y = 0;
    for (int j = 0; j < m.size(); j++) {
      Matrix visited (m.size(), std::vector<int>(m[0].size()));
      end_x = j;
      end_y = last_column;
      res = 0;
      final_length = INT_MAX;
      find_min_path(m, visited, start_x, start_y, end_x, end_y, res, final_length); 
      std::cout 
      << "start_x: " << start_x << " "
      << "start_y: " << start_y << " "
      << "end_x: " << end_x << " "
      << "end_y: " << end_y << " "
      << "result: ";
      if (final_length == INT_MAX) {
        std::cout<<"no result";
      } else {
        std::cout<< final_length;
      }

      std::cout<<std::endl;

    }
  }

}

int main() {
  Matrix m; 
  m.push_back({1,1,1,1,0,1,1});
  m.push_back({1,1,1,1,1,1,1});
  m.push_back({0,1,1,1,1,1,1});
  m.push_back({1,1,1,1,1,1,1});
  m.push_back({1,1,1,0,1,1,1});
  m.push_back({1,1,1,1,0,1,1});
  solution(m);

}