#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* data;
  size_t cap; // capacity
  size_t size;
} ivec;

void init(ivec* vec) {
  vec->size = 0;
  vec->cap = 1;
  vec->data = (int*)malloc(sizeof(int));
  if(vec->data == NULL) {
    perror("couldn't allocate memory\n");
    exit(EXIT_FAILURE);
  }
}

//push back x to the vector
void pb(ivec* vec, int x) {
  if(vec->size < vec->cap) {
    vec->data[vec->size]=x;
    vec->size++;
    return;
  }
  
  int* new_data = (int*)malloc(2*sizeof(int)*vec->size);
  if(new_data == NULL) {
    perror("couldn't allocate memory\n");
    exit(EXIT_FAILURE);
  }

  for(int i=0;i<vec->size;i++) {
    new_data[i] = vec->data[i];
  }

  free(vec->data);
  
  vec->data = new_data;

  vec->data[vec->size]=x;
  vec->size++;
  vec->cap = 2*vec->cap;
}

void pop(ivec* vec) {
  if(vec->size == 0) {
    perror("can't pop, vector is empty\n");
    exit(EXIT_FAILURE);
  }
  vec->size--;
  if(vec->size < vec->cap/4) {
    int* new_data = (int*)malloc(sizeof(int)*vec->size*2);
    vec->cap = 2*vec->size;
    if(new_data == NULL) {
      perror("couldn't allocate memory\n");
      exit(EXIT_FAILURE);
    }
    for(int i=0;i<vec->size;i++) {
      new_data[i] = vec->data[i];
    }

    free(vec->data);
    vec->data = new_data;
  }
}

int get(ivec* vec, size_t i) {
  if(i<0 || i>=vec->size) {
    perror("index out of bounds\n");
    exit(EXIT_FAILURE);
  }
  return vec->data[i];
}

int main() {
  ivec vec;
  init(&vec);

  for(int i=0;i<40;i++) pb(&vec, i);
  for(int i=0;i<15;i++) pop(&vec);

  printf("The vector has capacity %zu and size %zu\n", vec.cap, vec.size);

  for(size_t i=0;i<vec.size;i++) printf("vec[i] = %d\n",get(&vec,i));

  printf("vec[100] = %d\n", get(&vec,100));
  printf("did I make it this far? blah\n");


  return 0;
}
