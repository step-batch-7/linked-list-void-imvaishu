#include "linkedlist.h"

void take_position(int *value)
{
  printf("Please enter position\n");
  scanf(" %d",value);
}

Element take_int_input()
{
  int input;
  int *number = malloc(sizeof(int));
  printf("Please enter number\n");
  scanf(" %d",&input);
  *number = input;
  return number;
}

void print_int(Element data)
{
  printf("%d ",*(int *)data);
}

Status is_int_equal(Element num1,Element num2)
{
  return *(int *)num1 == *(int *)num2;
}

void choose_operation(List_ptr list,char operation)
{
  Element value;
  int position;
  switch(operation)
  {
    case 'a':
      value = take_int_input();
      add_to_list(list,value);
      break;
    
    case 'b':
      value = take_int_input();
      add_to_start(list,value);
      break;

    case 'c':
      value = take_int_input();
      take_position(&position);
      insert_at(list,value,position);
      break;

    case 'd':
      value = take_int_input();
      add_unique(list,value,&is_int_equal);
      break;

    case 'e':
      remove_from_start(list);
      break;

    case 'f':
      remove_from_end(list);
      break;

    case 'g':
      take_position(&position);
      remove_at(list,position);
      break;

    case 'h':
      value = take_int_input();
      remove_first_occurrence(list,value,&is_int_equal);
      break;

    case 'k':
      clear_list(list);
      break;

    case 'l':
      display(list,&print_int);
      break;

    case 'm':
      printf("done");
      break;  

    default :
      printf("option not given");
      break;
  }
}

int main(void)
{
  List_ptr list = create_list();
  char operation;
  while(operation != 'm')
  {
   scanf(" %c", &operation);
   choose_operation(list,operation);
  }
  return 0;
}