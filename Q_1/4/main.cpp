#include <iostream>


int main() {

int* p1{new int[10]}; //?
int* p2[10]; //?
int (*p3)(int[]); //?
int (*p4[10])(int [][10]); //?
int (*p5)[10]{new int [10][10]}; //?

 return 0;
}

