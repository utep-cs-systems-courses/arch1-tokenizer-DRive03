#include <stdio.h>
#include "tokenizer.h"
#include <ctype.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
 {
   int x = isspace(c);
   return x;
 }
 
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
     if(c != '\0')
       printf("%s its not an empty character (not a space)");
     else
       printf("%s its an empty character (not a space)");
}
/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  char prev=*str;
  int i=0;
  while (i==0)
  {
    if (isspace(prev) && !isspace(*str+1))
      {
	i++;
      }
    *str++;
    prev=*str;
  }
  
  return str;
}
/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  int swch=0;
  while(*word!='\0')
    {
      word++;
    }
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  char prev;
  int count = 0;
  for (prev=*str ; *str!='\0' ; *str++)
  {  
    if (isspace(prev) && !isspace(*(str+1)))
      {
	count++;
      }
   prev=*str; 
   // printf("C: %c \n",prev);
  }
  
  return count+1;
}
/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char newStr[len];
  for(int i=0;i<len;i++)
    {
      newStr[i]=*inStr;
      inStr++;
    }
  char *p=newStr;
  return p;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);
