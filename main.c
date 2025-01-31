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

Element increment(Element data)
{
  int *number = malloc(sizeof(int));
  *number = *(int *)data + 1;
  return number;
}

Element add(Element num1,Element num2)
{
  int *result = malloc(sizeof(int));
  *result = *(int *)num1 + *(int *)num2;
  return result;
}

Status is_num_even(Element data)
{
  return !(*(int *)data % 2);
}

void increment_by_2(Element data)
{
  *(int *)data += 2;
}

void choose_operation(List_ptr list,char operation,Int_input_taker input,Print printer)
{
  Element value;
  int position;
  List_ptr elements;
  Element result;
  switch(operation)
  {
    case 'a':
      value = input();
      add_to_list(list,value);
      break;
    
    case 'b':
      value = input();
      add_to_start(list,value);
      break;

    case 'c':
      value = input();
      take_position(&position);
      insert_at(list,value,position);
      break;

    case 'd':
      value = input();
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
      value = input();
      remove_first_occurrence(list,value,&is_int_equal);
      break;

     case 'i':
      value = input();
      elements = remove_all_occurrences(list,value,&is_int_equal);
      display(elements,printer);
      break;

    case 'j':
      value = input();
      result = reduce(list,value,&add);
      print_int(result);
      printf("\n");
      break;
    
    case 'k':
      clear_list(list);
      break;

    case 'l':
      display(list,printer);
      break;

    case 'n':
      elements = map(list,&increment);
      display(elements,printer);
      break;

    case 'o':
      elements = filter(list,&is_num_even);
      display(elements,printer);
      break;  

    case 'p':
      forEach(list,&increment_by_2);
      display(list,printer);
      break;  

    case 'q':
      elements = reverse(list);
      display(elements,printer);
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
   choose_operation(list,operation,&take_int_input,&print_int);
  }
  return 0;
}