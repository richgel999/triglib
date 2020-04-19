/* less(&a,r) - reduce angle to first revolution
                  &a - address of a double variable
                       containing the angle in spec'ed units
                  r -  size of a revolution in spec'ed units
The angle and the size of a rev must conform in
units, i.e, rads, grads, degrees etc. Unlike reduce.c , this 
one returns the equ of the basic FN LESS function,
not a fraction, but a value reconverted to the same units as
passed in "r" */

less(a,r) /* function declaration */
double *a,r; /* define and get from stack: a,r */
{
   double dfix(); /* define for this function that dfix returns doubles */
   *a /= r;
   *a -= dfix(*a);
   *a *= r;
}



