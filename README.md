## My practice implementation of a dynamically allocated vector

The idea is to have a vector in C that supports O(1) lookup, ammortized O(1) push_back, and ammortized O(1) pop.
The way this is done is through
```C
typedef struct {
  int* data;
  size_t cap; // capacity
  size_t size;
} ivec;
```

some testing
