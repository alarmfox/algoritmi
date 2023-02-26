#include <fstream>
#include <iostream>
#include <unordered_map>

#define TEST 1
int main() {

  std::istream *in = &std::cin;

  if (TEST) {
    in = new std::ifstream("input.txt");
    if (in->fail()) {
      std::cout << "errore" << std::endl;
      return 2;
    }
  }

  auto &cin = *in;

  int t, n, k;
  cin >> t;


  for (int i = 0; i < t; ++i) {
    cin >> n >> k;

    if (k == 0) {
      ((n + 4) % 4) == 0 ? std::cout << "Off\n" : std::cout << "On\n";
      continue;
    }

    int curr_state, prev_state, new_pos;
    bool ambiguous = false;

    for (int j = 1; j <= 3 && !ambiguous; j++) {
      new_pos = (j + n) % 4;
      curr_state = new_pos != 0; 
      if (j != 1 && prev_state != curr_state) {
        ambiguous = true;
      } else {
        prev_state = curr_state;
      }
    }
    ambiguous       ? std::cout << "Ambiguous\n"
    : curr_state == 0 ? std::cout << "Off\n"
                      : std::cout << "On\n";
  }

  if (TEST)
    delete in;
}
