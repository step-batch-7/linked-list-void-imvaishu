#include "linkedlist.h"

List_ptr create_list(void)
{
  List_ptr linkedList = malloc(sizeof(LinkedList));

  linkedList->first = NULL;
  linkedList->last = NULL;
  linkedList->length = 0;
  return linkedList;
}

Node *create_node(Element element)
{
  Node *node = malloc(sizeof(Node));
  node->element = element;
  node->next = NULL;
  return node;
}

Status add_to_list(List_ptr list, Element element)
{
  Node_ptr new_node = create_node(element);
  if (list->first == NULL)
  {
    list->first = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->length++;

  return Success;
}

Status add_to_start(List_ptr list, Element element)
{
  Node_ptr new_node = create_node(element);
  if(list->first == NULL){
    list->first = new_node;
    list->last = new_node;
  } else {
  Node_ptr previous_node = list->first;
  list->first = new_node;
  new_node->next = previous_node;
  }
  list->length++;
  
  return Success;
}

Status insert_at(List_ptr list, Element element, int position)
{
  if(position < 0 || position > list->length){
    return Failure;
  }
  if(position == 0) {
    return add_to_start(list, element);
  }
  if(position == list->length) {
    return add_to_list(list, element);
  }
  int count = 1;
  Node_ptr new_node = create_node(element);
  Node_ptr p_walk = list->first;
  while (count != position) {
    p_walk = p_walk->next;
    count++;
  }
  new_node->next = p_walk->next;
  p_walk->next = new_node;
  list->length++;
  
  return Success;
}
