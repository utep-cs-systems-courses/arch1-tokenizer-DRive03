#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char wrd[100];
  printf("$Please enter your word \n");

  fgets(wrd, 100, stdin);

   char *p;
   p=wrd;

  //  printf("\n");

  //  printf("%s",wrd);

  //  printf("\n");
  
  //  printf("Spaces %d \n", space_char(wrd[0]));

  //  printf("Empty? %d \n", non_space_char(wrd[0]));

  //  int c=count_words(p);
   
  char *d=&wrd[1];
  *d=*word_start(d);
  //  printf("Second word starts with:\n",d);  
  printf("No. of Wordsx %d \n", count_words(p));
  return 0;
}
