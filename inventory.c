#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "readline.h"
#include "inventory.h"

struct inventory_t *inventory_list = NULL;

int main (int argc, char *argv[]) {
  
  char code;

  for (;;){
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while(getchar() != '\n')
      ;
    switch (code)
    {
    case 'i':
      inventory_list = insert_part(inventory_list);
      break;
    case 's':
      search_part(inventory_list);
      break;
    case 'd':
      inventory_list = delete_part(inventory_list);
      break;
    case 'u':
      inventory_list = update_inventory(inventory_list);
      break;
    case 'p':
      print_inventory(inventory_list);
      break;
    case 'q':
      return 0;

    default:
      printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct inventory_t *insert_part(struct inventory_t *list) {
  /*
  - first sort list with the part_number. Then update the remaining properties
    - ask user to enter part_number first e.g. 50
    - insert this part into its right position
      * between 49 and 51 or
      * as the first item if list is empty or if the curr->next is 51
      * as the last item if curr->next is NULL and prev->next is 49
      HOW TO DO THIS
      - maintain a trailing pointer prev which starts by pointing to NULL and curr which is the first item in the list
      - traverse sequentially until new_node->part_number > curr->part_number. Then exit loop. At this point, prev points to address of item with part_number 49 and curr points to the address with part_number 51

    - ask user to enter the part name and quantity on hand and update those fields in the node
      * update the new_node->name and new_node->in_hand
    - update new_node->next
      * new_node->next now points to *curr
      * prev->next now points to *new_node
  */
  struct inventory_t *curr, *prev, *new_node;
  new_node = malloc(sizeof(struct inventory_t));

  printf("Enter part number: ");
  scanf("%d", &new_node->part_number);

  for (curr = list, prev = NULL;
    curr != NULL && new_node->part_number > curr->part_number;
    prev = curr, curr = curr->next ) /*
    @48
    50 > 48
    incr. prev = 48, curr = 49


    @49
    50 > 49
    incr. prev =49, curr = 51
    */
    ;
  if (curr != NULL && new_node->part_number == curr->part_number) {
    printf("Part already exists");
    free(new_node);
    return list;
  }
  printf("Enter the name of the part: ");
  read_line(new_node->name, NAME_LEN);

  printf("Enter the quantity on hand: ");
  scanf("%d", &new_node->in_hand);

  new_node->next = curr;
  if (prev == NULL)
    list = new_node;
  else
    prev->next = new_node;
  return list;
}

void search_part(struct inventory_t *list) {
  /*
  - user passes in the part number to search
  - traverse the list until the first part number that matches. Because the list is sorted, we don't have to traverse the entire linked list.
  - print out the details in a print statement
  OTHER conditions:
    - part does not exist
  */
  int number;
  struct inventory_t *part;

  printf("Enter part number to search: ");
  scanf("%d", &number);

  for (part = list; part != NULL && number > part->part_number; part = part->next)
    ;
  if (part != NULL && number == part->part_number){
      printf("%d : Item is %s. %d quantity in hand", list->part_number, list->name, list->in_hand
      );
  } else
    printf("Part not found");
}

struct inventory_t *delete_part(struct inventory_t *list) {
  /*
  - user passes the part_number 50 to delete
  - program traverse the list until the part_number is found while using a prev and curr to trail the respective addresses to reconstruct the linked list.

  delete 50:
  before: 49->ox11, next:ox12... 50->ox12, next:0x13... 52->ox13, next:NULL
  after: 49->ox11, next:ox13... 52->ox13, next:NULL

  delete 52:
  before: 49->ox11, next:ox12... 50->ox12, next:0x13... 52->ox13, next:NULL
  after: 49->ox11, next:ox13... 50->ox12, next:NULL
  OTHER Conditions:
    - if part_number is not found, print part number not found
    - if there is only one item in the list or N is first node meaning prev=NULL and curr == exist
  */
  struct inventory_t *prev, *curr;
  int part_number;

  printf("Enter part number to delete: ");
  scanf("%d", &part_number);

  for (prev = NULL, curr = list; curr != NULL && part_number != curr->part_number ; prev = curr, curr = curr->next)
    ;
  if (curr == NULL) {
      printf("Part not found");
      return list;
  }
  if (prev == NULL) {
    printf("Part %d successfully removed from inventory", part_number);
    list = list->next;
  }
  else {
    prev->next = curr->next;
    printf("Part %d successfully removed from inventory", part_number);
  }
  free(curr);
  return list;
}

void print_inventory(struct inventory_t *list){
/*
traverse the list to print the ordered parts
OTHER Conditions:
  - Database is empty
*/

if (list == NULL)
  printf("Database is empty");
else {
  printf("Qty\tName\t\tOn_hand\n");
  for (; list != NULL ; list = list->next) 
    printf("%d\t%s\t\t%d\n", list->part_number, list->name, list->in_hand);
}
}

struct inventory_t *update_inventory (struct inventory_t *list) {
  /*
  - user provides the part number to update
  - user provide what to update i.e. name or on_hand qty
  - program traverse the list. Find the matching part number. If found, Update property e.g. item->part_number
  OTHER Conditions:
    - part not found if part is not found
  */
  struct inventory_t *curr;
  int part_number;

  printf("Enter part number to update: ");
  scanf("%d", &part_number);

  if (list == NULL)
    printf("Database is empty");
  else {
    for (curr = list; curr != NULL && curr->part_number != part_number ; curr = curr->next)
      ;
    if (curr == NULL)
      printf("Part not found");
    else {
      printf("Update name: ");
      read_line(curr->name, NAME_LEN);

      printf("Update quantity: ");
      scanf("%d", &curr->in_hand);

      printf("Part updated\n");
    }
  }
  return list;  
}