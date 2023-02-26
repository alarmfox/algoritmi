#include <fstream>
#include <iostream>

#define TEST 1
int main() {

  std::istream *in = &std::cin;

  if (TEST) {
    in = new std::ifstream("ballbox.txt");
    if (in->fail()) {
      std::cout << "errore" << std::endl;
      return 2;
    }
  }

  auto &cin = *in;

  int t, n, k, min;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> k;
    min = k * (k + 1) / 2;
    if (n >= min) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }

  if (TEST)
    delete in;
}
