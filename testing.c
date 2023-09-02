#include "int_vec.h"

void test1(ivec* vec) {
  init(vec);
  for(int i=0;i<40;i++) pb(vec, i);
  for(int i=0;i<15;i++) pop(vec);
  print_vector(vec);
}

int main() {
  ivec vec;

  test1(&vec);

  return 0;
}