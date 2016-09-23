#include "listADTgen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list_type {
  void *data;
  int size;
  int capacity;
  int elementSize;
  int (*comparePtr) (void *d1, void *d2);
};


// returns the pointer to the list; NULL if list not created
ListType create(int elSize, int (*comp) (void *item1, void * item2)) {
  // allocate memory for a structure variable containing all
  // list components
  ListType listptr = malloc(sizeof(struct list_type));
  // if allocation was succesfull
  if (listptr != NULL) {
     listptr->size = 0;
     listptr->capacity = 10;
     listptr->elementSize = elSize;
     listptr->comparePtr = comp;
     // allocate memory for the actual array
     listptr->data = malloc(10*(listptr->elementSize));
     // if array not created, deallocate the list too
     if (listptr->data == NULL) {
       free(listptr);
       listptr = NULL;
     } 
  }
  return listptr;
}

void *get(int pos, ListType listptr) {
    return (listptr->data + pos * (listptr->elementSize));
}


void destroy(ListType listptr) {
  free(listptr->data);
  free(listptr);
  listptr = NULL;
}

void printl(ListType listptr, void (*printItem) (void *d)) {
  int i;
  for(i = 0; i < listptr->size; i++) {
    // since we cannot use data[i], we need to calculate the address
    // of the element to be sent to the client's print function
    // since data is of type void, the formula is:
    // the beginning address of the array + (offset x element size)
    printItem(listptr->data + i * (listptr->elementSize) );
    printf(" ");
  }
  printf("\n");
}
int size_is(ListType listptr) {
   return listptr->size;
}

int is_empty(ListType listptr) {
   return listptr->size == 0;
}

void make_empty(ListType listptr) {
  // if list is larger than 200 elements, create a smaller one
  if (listptr->capacity > 200)
    listptr->data = realloc(listptr->data, listptr->elementSize * 100);
  
  listptr->size = 0;
  listptr->capacity = 100;
}


// adds a component to the array, if enough memory available
void push(ListType listptr, void *item) {
  if (listptr->size >= listptr->capacity) {
    void *temp = realloc(listptr->data, listptr->elementSize * (listptr->capacity + 100));
    if (temp != NULL) {
      listptr->capacity += 100;
      listptr->data = temp;
      // copy the element, since we cannot use data[i], we need to copy the data using memcpy
      memcpy(listptr->data + (listptr->size) * (listptr->elementSize), item, sizeof(listptr->elementSize));
      listptr->size++;
     }
   }
   else {
     memcpy(listptr->data + (listptr->size) * (listptr->elementSize), item, listptr->elementSize);
     listptr->size++;
   }
}

int is_full(ListType listptr) {
   if (listptr->size < listptr->capacity) 
	return 0;

   else {
      void * temp = malloc(listptr->elementSize* (listptr->capacity + 100));
      if (temp != NULL) {
	   free(temp);
	   return 0; 
      }
      return 1;
   }
}
