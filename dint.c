/* dint(x) - integer, floor, of a real number
               argument musr be a double.
*/
double dint(x)
double x;
{
   double a,dfix();
   a = dfix(x);
   if ((x < 0.0) && (a != x ))
      a -= 1.0;
   return(a);
}


