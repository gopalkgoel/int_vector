## My practice implementation of a dynamically allocated vector

The idea is to have a vector in C that supports $O(1)$ lookup, ammortized $O(1$) push_back, and ammortized $O(1)$ pop.
The way this is done is through
```C
typedef struct {
  int* data;
  size_t cap; // capacity
  size_t size;
} ivec;
```

The idea is we maintain $\texttt{cap} <= 4\cdot\texttt{size}$. When we push and we are going to exceed capacity, then we double capacity. When we pop and we are going to violate $\texttt{cap} <= 4\cdot\texttt{size}$, we reduce capacity to be just 2*size. This preserves memory usage linear in vector size, while giving ammortized $O(1)$ pop and push_back.

To run the testing, run `make`. To get rid of executables, run `make clean`.
