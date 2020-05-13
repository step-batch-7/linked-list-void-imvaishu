  
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

List_ptr create_list(void)
{
  List_ptr linkedList = malloc(sizeof(LinkedList));

  linkedList->first = NULL;
  linkedList->last = NULL;
  linkedList->length = 0;
  return linkedList;
}