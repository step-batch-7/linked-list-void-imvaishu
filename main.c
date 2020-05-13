#include "linkedlist.h"

void display_done(Status current_status) {
  if(current_status == 1){
  printf("Done\n");
  }
  else
  {
  printf("Fail\n");
  }
} 

char take_operation_to_perform(void)
{
  char option;
  printf("Please enter the alphabet of the operation you would like to perform\n");
  scanf("%c", &option);
  while ((getchar()) != '\n');
  return option;
}

void *take_int_input()
{
  int input;
  int *number = malloc(sizeof(int));
  printf("Please enter number\n");
  scanf("%d",&input);
  while ((getchar()) != '\n'); 
  return number;
}

Status choose_operation(List_ptr list,char operation)
{
 Element value;
 switch (operation)
  {
  case 'a':
    value = take_int_input();
    return add_to_list(list, value);
    break;
  case 'b':
    value = take_int_input();
    return add_to_start(list,value);
    break;
  }
 return Failure;
}

int main(void)
{
  List_ptr list = create_list();
  char operation = take_operation_to_perform();
  Status status = 1;
  while(operation != 'm')
  {
  status = choose_operation(list,operation);
  display_done(status);
  operation = take_operation_to_perform();
  }
  display_done(status);
  return 0;
}