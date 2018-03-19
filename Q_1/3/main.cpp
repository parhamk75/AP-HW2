#include <iostream>


int main() {

  char a{'a'};

  const char* name{"Amir Jahanshahi"};

  const char* p1{name}; // ?

  std::cout << *p1 << *(p1 + 1) << *(p1 + 2) << std::endl;

  p1 = &a; //Allowed?

  std::cout << *p1 << *(p1 + 1) << *(p1 + 2) << std::endl;

  p1 = name;

  *p1 = 'b'; //Allowed?

  char* p2{name}; //Allowed?
    
  return 0;
}
