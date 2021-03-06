
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_font_opentype_truetype_Point__
#define __gnu_java_awt_font_opentype_truetype_Point__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace awt
      {
        namespace font
        {
          namespace opentype
          {
            namespace truetype
            {
                class Point;
            }
          }
        }
      }
    }
  }
}

class gnu::java::awt::font::opentype::truetype::Point : public ::java::lang::Object
{

public:
  Point();
  virtual ::gnu::java::awt::font::opentype::truetype::Point * getNext();
  virtual void setNext(::gnu::java::awt::font::opentype::truetype::Point *);
  virtual ::gnu::java::awt::font::opentype::truetype::Point * getPrev();
  virtual void setPrev(::gnu::java::awt::font::opentype::truetype::Point *);
  virtual jint getOrigX();
  virtual void setOrigX(jint);
  virtual jint getOrigY();
  virtual void setOrigY(jint);
  virtual jint getInDir();
  virtual void setInDir(jint);
  virtual jint getOutDir();
  virtual void setOutDir(jint);
  virtual jshort getFlags();
  virtual void setFlags(jshort);
  virtual void addFlags(jshort);
  virtual jboolean isControlPoint();
  virtual jint getU();
  virtual void setU(jint);
  virtual jint getV();
  virtual void setV(jint);
  virtual ::java::lang::String * toString();
  virtual jint getX();
  virtual void setX(jint);
  virtual jint getY();
  virtual void setY(jint);
  virtual jint getScaledX();
  virtual void setScaledX(jint);
  virtual jint getScaledY();
  virtual void setScaledY(jint);
  static const jshort FLAG_TOUCHED_X = 1;
  static const jshort FLAG_TOUCHED_Y = 2;
  static const jshort FLAG_ON_CURVE = 4;
  static const jshort FLAG_CONTOUR_END = 8;
  static const jshort FLAG_WEAK_INTERPOLATION = 16;
  static const jshort FLAG_INFLECTION = 32;
  static const jshort FLAG_DONE_X = 64;
  static const jshort FLAG_DONE_Y = 128;
  static const jint DIR_RIGHT = 1;
  static const jint DIR_LEFT = -1;
  static const jint DIR_UP = 2;
  static const jint DIR_DOWN = -2;
public: // actually package-private
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) origX;
  jint origY;
  jint scaledX;
  jint scaledY;
  jint x;
  jint y;
  jint u;
  jint v;
  jshort flags;
private:
  ::gnu::java::awt::font::opentype::truetype::Point * prev;
  ::gnu::java::awt::font::opentype::truetype::Point * next;
public: // actually package-private
  jint inDir;
  jint outDir;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_font_opentype_truetype_Point__
