#include <iostream>


int main() {

  int a {10};
  int* const b {&a};
  (*b)++;
  a++;
  std::cout << a << " " << b << " " << *b;
  
  return 0;
}
