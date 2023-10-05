#include "max.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



int max(int *numbers, int size) {
  if(size <= 0){
    printf("size of array must be greater than 0\n");
    assert(size > 0);
  }

  // insert your code here
  int max = numbers[0];
  for (int i = 0;i < size;i++) {
    if(numbers[i]>max)
    max = numbers[i];
  }
    
  return max;
}



#ifndef TEST

int main() {
  int numbers[]={5,45,78,34,1,54,56,9,21};
  int *numbers_point = &numbers;
  int size = sizeof(numbers) / (numbers[0]);
  int max_value = max(numbers_point, size);
  printf("%d\n", max_value);

  return 0;
}

#endif
