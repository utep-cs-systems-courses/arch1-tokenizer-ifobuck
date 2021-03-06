#include <stdio.h>
#include <stdlib.h>
#include "history.h"


List *init_history()
{

  List *list = (List *) malloc(sizeof(List));

  list->root = malloc(sizeof(Item));

  list->last = malloc(sizeof(Item));

  return list;

}


void add_history(List *list, char *str)
{

  if (list->root->str == 0) {

    list->root->str = str;

    list->root->id = 0;

    list->last = list->root;

  } else
    {

    list->last->next = malloc(sizeof(Item));
    list->last->next->str = str;
    list->last->next->id = list->last->id+1;
    list->last = list->last->next;
    list->last->next = 0;

  }

}


char *get_history(List *list, int id)
{

  Item *dummy = malloc(sizeof(Item));

  dummy = list->root;

  while (dummy != 0) {

    if (dummy->id == id)
      {

      char *s = dummy->str;
      printf("the item at %d is: ", id);
      printf("%s", dummy->str);
      free(dummy);

      return s;

    }

    dummy = dummy->next;

  }

  free(dummy);

  return "item not found";

}


void print_history(List *list)
{

  Item *itr = list->root;

  while (itr) {

    printf("> at id %d: %s\n", itr->id, itr->str);

    itr = itr->next;

  }

  printf("finished printing history\n");

}


void free_history(List *list)
{

  Item *p = list->root;

  Item *temp;

  while (temp)
    {

    temp = p->next;
    free(p->str);
    free(p);
    p = temp;

  }

  list->root = 0;

}

