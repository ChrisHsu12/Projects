void add(const char a[], const char b[], char res[]);
/* Adds two decimal numbers stored as strings and returns their sum.
   Input
     a: an array of characters storing decimal digits; a[0] != '0'.
     b: an array of characters storing decimal digits; b[0] != '0'.
   Output
     res: an array of characters storing a decimal number that is the sum of the numbers represented in a and b.
 */
void sub(const char a[], const char b[], char res[]);
/* Subtracts two decimal numbers stored as strings and returns their difference.
   Input
     a: an array of characters storing decimal digits; a[0] != '0'.
     b: an array of characters storing decimal digits; b[0] != '0'.
   Output
     res: an array of characters storing a decimal number that is the difference of the numbers represented in a and b. 
 */

#include <stdio.h>
#include <string.h>

#define N 80
char a[N], b[N], res[N + 1];

int main()
{
  char op;
  scanf("%s %s %c", a, b, &op);
  switch (op)
  {
  case '+':
    add(a, b, res);
    break;
  case '-':
    sub(a, b, res);
  }

   /* print result */
   char buf[20];
   int l1 = strlen(a), l2 = strlen(b), l3 = strlen(res);
   int m = l1 > l2 ? l1 : l2;
   m = m > l3 ? m : l3;
   sprintf(buf, "%% %ds\n%% %ds\n%% %ds\n", m, m, m);
   printf(buf, a, b, res);
}
