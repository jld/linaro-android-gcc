// Test -Wicf to warn about function pointers used in comparisons.
// Origin: Sriraman Tallam <tmsriram@google.com>

// { dg-do compile}
// { dg-options "-Wicf" }

struct A
{
  int foo (int);
  int bar (int);
};

extern int foo (int);
extern int baz (int);

int (*funcptr) (int);
int (A::*Aptr) (int);
void
bar (int a)
{
  funcptr = baz;
  Aptr = &A::foo;
  if (foo == funcptr)  // { dg-warning "Function pointer used" "correct warning" }
    foo (10); 
  if (funcptr == baz)  // { dg-warning "Function pointer used" "correct warning" }
    foo (10); 
  if (&A::foo == &A::bar) // { dg-warning "Method pointer used" "correct warning" }
    foo (10);
  if (Aptr == &A::foo) // { dg-warning "Method pointer used" "correct warning" }
    foo (10);
}
