#include <stdio.h>
#include "tokenizer.h"
#include <ctype.h>
#include <stdlib.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
 {
   if(c == ' ' || c == '\t')
     return 1;
   else
     return 0;
 }
 
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{   
     if(c != '\0'|| c=='\n')
       return 1;
     else
       return 0;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  while( (*str != ' ' && *str != '\t') && *str != '\0')
    {
      str++;
    }
  return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  char *wrd = word;
  while(*wrd != ' ')
    {
      wrd++;
    }
  *wrd='\0';
  
  return wrd;
}

/* Counts the number of words in the string argument. */
int count_words(char* str)
{
  char *p=str;
  int swtch=0;
  int count = 0;      
  for ( ; *p !='\0' ; *p++)
  {  
    if( (swtch == 0) && ((*p != ' ') && (*p != '\t')) )
      {
	swtch=1;
	count++;
      }
    if( (swtch == 1) && ((*p == ' ') || (*p == '\t')) )
      {
	swtch=0;
      }
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char* inStr, short len)
{
  short i=0;
  char* newStr=(char*) malloc(sizeof( (len+1) ) );
  while( ( (*newStr = *inStr) != '\0' ) && i < len )
    {
      newStr++;
      inStr++;
      i++;
    }
  return newStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
/////////////////////////////////////////////////////////////
char **tokenize(char* str)
{
  printf("a \n");
  int nowrds=count_words(str);//number of words in the string for the array
  printf("b \n");
  char **token_ptr= malloc( (nowrds+1)*sizeof(char*) );
  printf("c \n");
  for(int i=0;i<nowrds;i++)
    {
      printf("d \n");
      if(str[0]=' ') 
	{
	  printf("e \n");
	  str= word_start(str);//if the first char is space move to the first word
	}
      printf("f \n");
      int length = ( (word_terminator(str)) - (word_start(str)) );//end of word - start of word = length
      printf("g \n");
      token_ptr[i] = copy_str(str,length);
      printf("h \n");
      str=word_start(word_terminator(str));
      printf("i \n");
    }  
  return token_ptr;
  }

/* Prints all tokens. *///
///////////////////////////////////////////////////////////////////////
void print_tokens(char **tokens)
{
  while(**tokens != '\0')
    {
      printf("%s", *tokens);
      tokens++;
    }
}
/////////////////////////////////////////////////////////
/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  while(**tokens != '\0')
    {
      free(*tokens);
      tokens++;
    }
}
