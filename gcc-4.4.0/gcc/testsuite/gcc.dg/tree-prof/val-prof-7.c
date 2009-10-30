/* { dg-options "-O2 -fdump-tree-tree_profile" } */

#include <strings.h>

int foo(int len)
{
  char array[1000];
  bzero(array, len);
  return 0;
}

int main() {
  int i;
  for (i = 0; i < 1000; i++)
    {
      if (i > 990)
	foo(16);
      else
	foo(32);
    }
}

/* { dg-final-use { scan-tree-dump "Single value 32 stringop transformation on bzero" "tree_profile"} } */
/* { dg-final-use { cleanup-tree-dump "tree_profile" } } */
