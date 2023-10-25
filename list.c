#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void add(node *head, int x) {
  // pre:  head points to the first, empty element.
  //       The last element's next is NULL
  // post: A new node containing x is added to the end of the list
  assert(head != NULL);
  node *p = head;
  while (p->next != NULL) {
    p = p->next;
  } // p points to the last element
  node *element = malloc(sizeof(node));
  element->next = NULL;
  element->data = x;
  p->next = element;
}

// exersice 3.b
int size(node *l) {
 //Implement a function with the following signature: int size(node *l). It has the same
// precondition as add and returns the number of elements in the list. E.g. if size(list) was
// printed out at the first // show list here) in main, the result would be 3

  assert(l != NULL);
    int numberOfElements = 0;
    node *current = l->next;
    
    while (current != NULL) {
        numberOfElements++;
        current = current->next;
    }
    
	return numberOfElements;
}

// exersice 3.c and 3.d
void printout(node *l) {
  // pre:  head points to the first, empty element.
  //       The last element's next is NULL
  // post: The values of the list are printed out
  node *p = l->next;
  while (p != NULL) {
    printf("%d", p->data);
    p=p->next;

    if(p != NULL){
    printf(", ");
  }
  }

  

  printf("\n");
}

// exersice 3.e
int largest(node *l) {
  // pre:  head poinst to the first, empty element.
  // 	     The last element's next is NULL.
  // post: Returns the largest value of the list
assert(l->next != NULL);  // Check if the list is not empty

  node *p = l->next;

  int max = p->data;
  while (p != NULL) {
    int dataCurrent = p->data;
    if(dataCurrent>max){
      max = dataCurrent;
    }
       p=p->next;


  }
  


  return max;
}

#ifndef TEST
int main() {
  node *list = malloc(sizeof(node));
  list->next = NULL; // create first empty element

  add(list, 1);
  add(list, 55);
  add(list, 2);
  // Show list here
  int nOfElements1 = size(list);
  printf("%d\n",nOfElements1);
  add(list, 2);
  // Show list here
  add(list, 45);
  int nOfElements2 = size(list);
  printf("%d\n",nOfElements2);
  printout(list);
  int maxValue = largest(list);
  printf("%d\n",maxValue);
  return 0;
}

#endif
