/* dfix(x) - integer portion of a real number.
               argument x must be a double.
            any use of dint.c will find an
            include to this file
*/
double dfix(x)
double x;
{
   union
   {
      double a;
      char c[8];
   } z;
   register int n;
   int exp,mask=0xff;
   z.a = x;
   exp = ( z.c[7] & 0xff ) - 0x80;
   if ( exp >= 56 )
      return(x);
   if ( exp <= 0 )
      return(0.0);

   for ( n = 48; n > exp; n -= 8 )
      z.c[n>>3] = 0;

   for ( n += 8; n > exp; --n )
      mask <<= 1;

   z.c[n>>3] &= mask;
   return(z.a);
}


