#include <fstream>
#include <iostream>
#include <istream>

#define TEST 0

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

  if (TEST)
    delete in;
}
