#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "commands.h"
#include "architecture.h"
#include "functional.h"
FILE *src;
char path[256];
char line[75];
int line_number=0;
int main(int argc, char **argv)
{
 if (argc<=1) input_program();
  else
  {
    for( int i=0; i<argc;i++)
       {
         strcpy(path,argv[i]);
       }
    src=fopen(path,"r");
    if(src==NULL) puts("File does not open!");
     else
      {
        while(fgets(line,sizeof(line),src))
        {
        memory[line_number]=(int)strtol(line,NULL,16);
        line_number++;
        }
       fclose(src);
     }

  }
 exec_comand();
 system("pause");
 return 0;
}
