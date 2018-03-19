#include <iostream>


int main() {

  const int a {10};

  int c {20};
  
  int d {30};
  
  const int* b {&a};
  
  b = &c;
  
  std::cout << a << " " << b << " " << *b;

  int* const e{&c};

  e = &d;

  std::cout << d << " " << e << " " << *e;

  return 0;
}


