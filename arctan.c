/* arctan(x) - angle, in radians, whose tanget is x.
               Argument, x, must be of type double.
               The value returned is of type double.

               The value returned range is:
                -pi/2 <= arctan(x) <= pi/2
*/
#define INDEX 12  /* table size for power series calculation */
#define F27  -3.703703703703704e-02

#include <trigcons.h>

double arctan(x)
double x;
{
   double a, r = 0.0, x2, dabs();
   register int n;
   int s = 0;
   static double f[INDEX] = {
   -3.333333333333333e-01,
    2.000000000000000e-01,
   -1.428571428571429e-01,
    1.111111111111111e-01,
   -9.090909090909091e-02,
    7.692307692307692e-02,
   -6.666666666666667e-02,
    5.882352941176471e-02,
   -5.263157894736842e-02,
    4.761904761904762e-02,
   -4.347826086956522e-02,
    4.000000000000000e-02 };

/* determine sign of result */
   if ( x < 0.0)
   {
      x = -x;
      s = -1;
   }
   else if ( x > 0.0 )
      s = 1;

/* if angle > pi/4, calc arcot(x) series */
   if ( x > 1.0 )
   {
      x = 1.0 / x;
      r = -HALF_PI;
      s = -s;
   }

/* relax the series to accelerate convergence */
   if ( x > TAN15 )
   {
      x = ( SQRT3 * x - 1.0 ) / ( x + SQRT3 );
      r += SIXTH_PI;
   }

/* calculate arctan(x) */
   if ( dabs(x) <= 1.0e-09 ) /* check for very small values */
      a = x;
   else
   {
      x2 = x * x;
      a = x2 * F27;
      for ( n = INDEX - 1; n >= 0; --n )
         a = ( a + f[n] ) *x2;
      a = ( a + 1.0 ) * x;
   }
   a += r;
   if ( s == -1 )
      a = -a;
   return(a);
}


