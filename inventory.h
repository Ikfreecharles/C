#ifndef INVENTORY_H
#define INVENTORY_H

#define NAME_LEN 60

struct inventory_t *insert_part(struct inventory_t *);
void search_part(struct inventory_t *);
struct inventory_t *delete_part(struct inventory_t *);
void print_inventory(struct inventory_t *);
struct inventory_t *update_inventory(struct inventory_t *);
static int sort_ascending();

struct inventory_t {
  int part_number;
  char name[NAME_LEN + 1];
  int in_hand;
  struct inventory_t *next;
};

#endif