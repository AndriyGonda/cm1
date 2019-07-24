#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	 char str[64];
   printf("Please enter string\n");
  fgets(str,64,stdin);
  int i=0;
 while(str[i])
  {
    printf("%04x\n",str[i]);
    i++;
  }
 return 0;
}
