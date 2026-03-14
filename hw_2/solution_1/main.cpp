#include "config.hpp"
#include <iostream>
int main() {
  const int Config::kMax; // теперь память выделена внутри функции и мы можем обратиться по ссылке
  std::cout << Config::kMax << "\n"; // (1)
  const int* p = &Config::kMax; // (2) uncomment - перед Config стоит ссылка
  std::cout << *p << "\n";
}
