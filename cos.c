/* cos(x) - cosine of a real number.
          argument x must be a double
          returns a double in radians */
#include <trigcons.h>
double cos(x)
double x;
{
     double _sincos();
     reduce(&x,TWO_PI);
     return(_sincos(0.25 - x));
}

