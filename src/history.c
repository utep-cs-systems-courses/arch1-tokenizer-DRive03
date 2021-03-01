#include <stdio.h>
#include "tokenizer.h"
#include <ctype.h>
#include <stdlib.h>

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/*Initialize the linked list to keep the history. */
List* init_history()
{
  Item* head=NULL;
  List* list;
  list->root=head;
  list->root->id=1;
  return list;
}

/*Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  int i=0;
  Item *p=NULL;
  p= list->root;
  while(p != NULL)
    {     
      p=p->next;
      i++;
    }
  p->str=str;
  p->id=i;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  int i=0;
  Item *p=NULL;
  p= list->root;
  while( (p != NULL) && (i==id) )
    {     
      p=p->next;
      i++;
    }
  char *his=p->str;
  return his;
}

/* Print the entire contents of the list. */
void print_history(List *list)
{
  int i=0;
  Item *p=NULL;
  char *s;
  char **ss=&s;
  p= list->root;
  while(p != NULL)
    {
      s=p->str;
      print_tokens(ss);
      p=p->next; 
    }
}

/* Free the history list and the strings it references. */
void free_history(List *list)
{
  int i=0;
  Item *p=NULL;
  char *s;
  char **ss=&s;
  p= list->root;
  while(p != NULL)
    {
      s=p->str;
      free_tokens(ss);
      p=p->next; 
    }
  list->root=NULL;
}
