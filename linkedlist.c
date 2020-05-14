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

Status add_unique(List_ptr list, Element element, Matcher matcher)
{
  Node_ptr p_walk = list->first;
  for(int i = 0 ; i < list->length ; i++ )
  {
    if(matcher(p_walk->element,element)){
      return Failure;
    }
      p_walk = p_walk->next;
    }
    return add_to_list(list,element);
}

void display(List_ptr list,ElementProcessor elementProcessor)
{
  Node_ptr p_walk = list->first;
  while(p_walk != NULL)
  {
    elementProcessor(p_walk->element);
    p_walk = p_walk->next;
  }
  printf("\n");
}

Element remove_from_start(List_ptr list)
{
  Node_ptr first_element = list->first;
  if(list->first == NULL)
  {
    return NULL;
  }
  if(list->length == 1)
  {
    list->last = NULL;
  }
  list->first = first_element->next;
  list->length--;
  return first_element;
}


Element remove_from_end(List_ptr list)
{
  if(list->first == NULL)
  {
    return NULL;
  }

  if(list->length == 1)
  {
   return remove_from_start(list);
  }
  Node_ptr previous_element = list->first;
  Node_ptr p_walk = list->first;
  int position = 0;
  while(position < list->length)
  {
    previous_element = p_walk;
    p_walk = p_walk->next;
    position++;
  }
  list->last = previous_element;
  previous_element->next = NULL;
  list->length--;
  return p_walk->element;
}

Element remove_at(List_ptr list, int position)
{
  Node_ptr p_walk = list->first;
  Node_ptr previous_element;
  Node_ptr remove_element;
  if(position < 0 || position >= list->length)
  {
    return NULL;
  }
  if(position == 0)
  {
    return remove_from_start(list); 
  }
  if(position == (list->length - 1))
  {
    return remove_from_end(list);
  }
  int count = 0;
  while(count <= position){
    if(count == position - 1)
    {
     previous_element = p_walk;
     remove_element = p_walk->next;
    }
    p_walk = p_walk->next;
    count++;
  }
  previous_element->next = p_walk;
  list->length--;
  return remove_element;
}

Element remove_first_occurrence(List_ptr list, Element element, Matcher matcher)
{
  Node_ptr p_walk = list->first;

  for(int index = 0 ; index < list->length; index++)
  {
    if(matcher(p_walk->element,element))
    {
      return remove_at(list,index);
    }
    p_walk = p_walk->next;
  }
  return NULL;
}