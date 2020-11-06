
#include <stdio.h>

extern int is_same_diagonals(int n, int A[]);

#define A(i, j) A[(i)*n + j]
#define B(i, j) B[(i)*n + j]
#define
#define n 4

int main()
{
  int i,j,t;
  int A[n*n] = {1,2,3,5,6,1,2,3,9,6,1,2,5,9,6,1};
  int B[n*n] = {1,2,3,4,5,1,3,4,2,3,1,2,3,4,5,1};
  int C[n*n] = {5,3,2,1,3,2,1,6,2,1,6,9,1,6,9,5};
  int *list[] = {A,B,C};
  
  for(t = 0;t<3;t++) {
    for (i = 0; i<n; i++) {
      for (j = 0; j<n; j++){printf("%d ", list[t][(i)*n + j]);}
      printf("\n");
    }
    printf("\n");
    if (is_same_diagonals(n, list[t]))
      printf("Same diagonals\n");
    else
      printf("Different diagonals\n");
  }
  return 0;
}
