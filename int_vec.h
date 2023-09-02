#ifndef INT_VEC_H
#define INT_VEC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* data;
  size_t cap; // capacity
  size_t size;
} ivec;

void init(ivec* vec);
void pb(ivec* vec, int x);
void pop(ivec* vec);
int get(ivec* vec, size_t i);

#endif