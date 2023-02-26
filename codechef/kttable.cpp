#include <fstream>
#include <iostream>
#include <istream>

#define TEST 1

int main() {
  std::istream *in = &std::cin;

  if (TEST)
    in = new std::ifstream("ktt.txt");

  auto &cin = *in;

  int t, n, res = 0;
  int arr[10000];
  cin >> t;

  for (int i = 0; i < t; ++i) {
    cin >> n;
    int curr, prev = 0;

    for (int j = 0; j < n; j++) {
      cin >> curr;
      arr[j] = curr - prev;
      prev = curr;
    }

    res = 0;
    for (int j = 0; j < n; j++) {
      cin >> curr;
      res = curr <= arr[j] ? res +1 : res;
    }
    std::cout << res << std::endl;
  }

  if (TEST)
    delete in;
  return 0;
}
