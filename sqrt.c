/* sqrt(x) - square root of a real number.
             Argument x must be type double.
*/
#define SOLVE 1
#define FALSE 0
#define TRUE 1
#define ESQRTNEG 43 /* negative argument for sqrt */
double sqrt(x)
double x;
{  double b, dabs();
   union
   {  double a;
      char c[8];
   } x0;

   int err = FALSE;
   extern int errno;
   if ( x == 0.0 )
      return(x);
   if ( x < 0.0 ) 
   {
      err = TRUE;
      x = -x;
      errno = ESQRTNEG;
   }
   x0.a = x; /* set initial approximation */
   x0.c[7] = ( ( x0.c[7] >> 1 ) & 0x7f ) + 64;
   b = x / x0.a;
   do 
   {
   x0.a = ( x0.a + b ) * .5;
   b = x / x0.a;
   if (dabs( x0.a - b ) < ( 0.5e-16 * b ) )
      break;
   }
   while ( SOLVE );
      if ( err )
         x0.a = -x0.a;
      return(x0.a);
}


