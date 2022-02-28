#include "functions.h"

int main() {
  //pointer
  int *numbersPointer = (int*)malloc(300*sizeof(int));
  int j = 0; //position of pointer
  //adding integers
  for(int i=150; i<=448; i+=2){
    *(numbersPointer + j) = i;
    j++;
  }
  for(int i=449; i>=151; i-=2){
    *(numbersPointer + j) = i;
    j++;
  }

  //making copies of pointer to sort
  int *sortedPointer1 = (int*)malloc(300*sizeof(int));
  memcpy(sortedPointer1, numbersPointer, 300*sizeof(int));

  //2
  pointerAscendingInsertionSort(sortedPointer1);

  printPointer(sortedPointer1);

  return 0;
}
