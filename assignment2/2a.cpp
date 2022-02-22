#include "1b.cpp"
#include <iostream>
#include <vector>
using namespace std;

//2) pointer sorts
void pointerAscendingInsertionSort(int* p) {
  int temp;
  for(int i=1; i<300; i++){//loop through all elements staring from position 1;
    for(int j=i; j>0 && *(p+(j-1))>*(p+j); j--){//for sorted portion
      //shifting selected element to the left while pushing others to the right.
      temp = *(p+j);
      *(p+j) = *(p+(j-1));
      *(p+(j-1)) = temp;
    }
  }
}

int main() {
  //1
  //linked list //initializing head & tail
  tail = (struct numbersNode*)malloc(sizeof(struct numbersNode));
  head = (struct numbersNode*)malloc(sizeof(struct numbersNode));
  tail->num = 150;
  tail->prev = head;
  tail->next = NULL;
  head = tail;
  //pointer
  int *numbersPointer = (int*)malloc(300*sizeof(int));
  int j = 0; //position of pointer
  //vector
  vector<int> numbersVector;
  //adding integers
  for(int i=150; i<=448; i+=2){
    *(numbersPointer + j) = i;
    j++;
    numbersVector.push_back(i);
    if(j!=1)//first value is already entered
      insertTail(i);
  }
  for(int i=449; i>=151; i-=2){
    *(numbersPointer + j) = i;
    j++;
    numbersVector.push_back(i);
    insertTail(i);
  }

  //making copies of pointer to sort
  int sortedPointer1 =  *numbersPointer;
  int sortedPointer2 =  *numbersPointer;

  //2
  pointerAscendingInsertionSort(sortedPointer1);
  printPointer(sortedPointer1);
  printPointer(numbersPointer);

  return 0;
}
