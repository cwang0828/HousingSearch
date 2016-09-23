#ifndef LISTADT_H
#define LISTADT_H

typedef struct list_type *ListType;

ListType create(int elSize, int (*compare) (void *item1, void *item2));
void destroy(ListType listP);
void make_empty(ListType listP);
int is_empty(ListType listP);
int is_full(ListType listP);
int size_is(ListType listP);
void push(ListType listP, void *item);
//void delete(ListType listP, void* item);
void printl(ListType listP, void (*printItem) (void *item));
void *get(int pos, ListType listP);

#endif



