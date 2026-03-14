#include "config.hpp"
#include <iostream>
int main() {
  std::cout << Config::kMax << "\n"; // (1)
  const int* p = &Config::kMax; // (2) uncomment - перед Config стоит ссылка
  std::cout << *p << "\n";
}
