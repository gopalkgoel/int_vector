#include "int_vec.h"

void test1(ivec* vec) {
  init(vec);
  for(int i=0;i<20;i++) pb(vec, i);
  for(int i=0;i<15;i++) pop(vec);
  print_vector(vec);
  printf("----------------------------\n");
}

void test2(ivec* vec) {
  init(vec);
  for(int i=0;i<20;i++) pb(vec, i);
  for(int i=0;i<20;i++) pop(vec);
  print_vector(vec);
  printf("----------------------------\n");
}

void test3(ivec* vec) {
  init(vec);
  for(int i=0;i<20;i++) pb(vec, i);
  for(int i=0;i<19;i++) pop(vec);
  print_vector(vec);
  printf("----------------------------\n");
}

void test4(ivec* vec) {
  init(vec);
  for(int i=0;i<20;i++) pb(vec, i);
  for(int i=0;i<19;i++) pop(vec);
  for(int i=1;i<=20;i++) pb(vec, i);
  print_vector(vec);
  printf("----------------------------\n");
}

//gonna try to pop too much
void test5(ivec* vec) {
  init(vec);
  for(int i=0;i<10;i++) pb(vec, i);
  for(int i=0;i<11;i++) pop(vec);
  print_vector(vec);
  printf("----------------------------\n");
}

//gonna try to access a good index
void test6(ivec* vec) {
  init(vec);
  for(int i=0;i<10;i++) pb(vec, i);
  for(int i=0;i<5;i++) pop(vec);
  print_vector(vec);
  printf("I also found that vec[2] = %d\n", get(vec,2));
  printf("----------------------------\n");
}

//gonna try to access a bad index
void test7(ivec* vec) {
  init(vec);
  for(int i=0;i<10;i++) pb(vec, i);
  for(int i=0;i<5;i++) pop(vec);
  print_vector(vec);
  printf("I also found that vec[7] = %d\n", get(vec,7));
  printf("----------------------------\n");
}


int main() {
  ivec vec;

  test1(&vec);
  test2(&vec);
  test3(&vec);
  test4(&vec);
  test5(&vec); //gives an error
  test6(&vec);
  test7(&vec); //gives an error

  return 0;
}