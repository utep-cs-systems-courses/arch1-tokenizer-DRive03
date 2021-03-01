#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include <stdlib.h>

int main(){
  char* wrd=malloc( (100+1)*sizeof(char) );
  
  printf("$Please enter your word \n");

  fgets(wrd, 100, stdin);

  printf("%s \n",wrd);  
  char** toke;
  toke=(char**) tokenize(wrd);
  
  //  char *rows=*tokens;
  // printf("%p",*tokens);

  /*while(*tokens !='\0')
    {
      while(**tokens != '\0')
	{
	  
	};
      
	}*/
  
  //scanf("%[^\n]%c");

  //  printf("\n");

  //  printf("%s",wrd);

  //  printf("\n");
  //char s=' ';
  // printf("Spaces %d \n", space_char(s));

  // char p='\0';
  //printf("Empty? %d \n", non_space_char(p));

  //  int c=count_words(p);
   
  //char d[]="daretsa";
  //char *f=copy_str(d,3);
  //printf("%s", f);
 /* for (int x=0 ; x<3 ; x++)
    {
      f++;
      }*/
  
  //char *g= word_start(d);
  //printf("Second word starts with:\n %c",*g);  
  // printf("No. of Words %d \n", count_words(p));
  return 0;
}
