// { dg-do compile }
// { dg-options "-g"
namespace NS {
  int x = 0;
  int &ref = x;
}

using NS::ref;
