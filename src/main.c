#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main()
{
  char input[100];
 
  while(1)
    {
      printf("Pick one: \n");
      printf("1. 't' to tpe\n 2. 'q' to quit\n 3. 'h' for the history");
      printf("$");
      fgets(input,100,stdin);
      if(input[0] == 't')
	{
	printf("Enter here: \n");
	fgets(input,100,stdin);
	char **p = tokenize(input);
	print_tokens(p);
      }
      else if(input[0] == 'q')
	{
	  printf("Now exiting\n");
	  free_history(history);
	  return 0;
	}
      else if(input[0] == 'h')
	{
	  print_history(history);
	}
      else{
	printf("Erro, please pick from above\n");
      }
    }
}

