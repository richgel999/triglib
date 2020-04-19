/* reduce(&a,r) - reduce angle to first revolution
                  &a - address of a double variable
                       containing the angle
                  r -  size of a revolution
                  The angle and the size of a rev
                  must conform in units, i.e, rads,
                  grads, degrees etc.
*/
reduce(a,r)
double *a,r;
{
   double dfix();
   *a /= r;
   *a -= dfix(*a);
}



