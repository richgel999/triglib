/* tst_lfactr.c - a routine to test the factr function.
*/
#include <stdio.h>
#include "lfactr.c"
main(argc,argv)
int argc;
char *argv[];
{
  int num, a;
  long ans;
  long lfactr();
  pflinit();
  if(argc != 2)
     exit(0);
  *++argv;
  num = atoi(*argv);
  printf("The number passed is %d\n",num);
  if(num>1)
     {
     for(a=2;a<=num;a++)
        {
        printf("In the tst_loop, a = %d\n",a);
        ans = lfactr(a);
        printf("The answer is %ld\n",ans);
        }
     }
  else
     printf("The number isn't big enough to bother with\n");
}

