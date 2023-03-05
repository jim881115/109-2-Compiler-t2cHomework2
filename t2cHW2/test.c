#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f2 ( int x, int y)
{ int z;
z = x*x - y*y;
return z;
}
int main ( )
{ int x;
printf("A41.input");
printf("\n");
scanf("%d", &x);
int y;
printf("A42.input");
printf("\n");
scanf("%d", &y);
int z;
z = f2(x,y)
 + f2(y,x)
;
printf("A4.output");
printf("%d", z);
}
