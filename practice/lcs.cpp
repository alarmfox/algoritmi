#include <bits/stdc++.h>

#define TEST 1

int solve(const std::string&a, const std::string &b) {

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
  int n, t;
  std::string a, b;
  cin >> t;
  while (t--) {
    cin >> a;
    cin >> b;
    std::cout << solve(a, b) << std::endl;
  }

  if (TEST)
    delete in;
}
