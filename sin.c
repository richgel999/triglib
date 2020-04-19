/* sin(x) - sine of a real number.
            argument must be a double.
            argument must be in radians
*/

#include <trigcons.h>

double sin(x)
double x;
{
   double _sincos();
   reduce(&x,TWO_PI);
   return(_sincos(x));
}


