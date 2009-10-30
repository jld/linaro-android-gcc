/* Test that __builtin_prefetch can be disabled. */

/* { dg-do compile } */
/* { dg-options "-O2 -fdump-rtl-expand --param builtin-prefetch-override=1" } */

void
func (void *p)
{
  __builtin_prefetch (p, 0, 0);
}

/* { dg-final { scan-rtl-dump-not "prefetch \\(" "expand" } } */
/* { dg-final { cleanup-rtl-dump "*" } } */
