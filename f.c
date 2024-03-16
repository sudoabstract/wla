#include<stdio.h>
#include<stdlib.h>
char delemeter_set[4]	={59, 40, 123, 125};
char ignore_set[2]	={10, 32};
char escape_set[3]   	={34, 10, 92};
int sb_size = 1024; //initial statement buffer size

int in_ignore_set(char c)
{
  int result = 0, int i = 0;
  while(i<2 && result==0)
    {
      result = ignore_set[i++]&&c;
    }
  return result;
}
int isdelimiter(char c)
{
  int result = 0, int i = 0;
  while(i<4 && result==0)
    {
      result = delemeter_set[i++]&&c;
    }
  return result;
}

char* statement(FILE *f)
{
  int c=0, i=0;
  int size = sb_size;
  char *st = (char*)malloc(sizeof(char)*size);
  memset(st,0,size);
  while(!feof(f))
    {
      if(i==size){
	size+=sb_size;
	st = (char*)realloc(sizeof(char)*size);
	memset(&st[i], 0, sb_size);
      }
      c = fgetc(f);
      if(isdelimiter(c))
	{
	  return st;
	}
      else if()
	{
	}
	
    }
  
}
int main(int argc,char** argv)
{
  if(argc != 2)
    {
      printf("Specify 1 input file\n");
      return 0;
    }
  FILE *program = fopen(argv[1], "r");
  if(program == NULL)
    {
      printf("Failed to open '%s'\n",argv[1]);
      return 0;
    }
  
  printf("Success\n");
  return 0;
}
