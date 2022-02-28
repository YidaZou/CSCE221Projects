#include "functions.h"

int main() {
  //1
  //linked list //initializing head & tail
  struct numbersNode *head, *tail;
  tail = (struct numbersNode*)malloc(sizeof(struct numbersNode));
  head = (struct numbersNode*)malloc(sizeof(struct numbersNode));
  head->num = 150;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
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
      insertTail(&tail,i);
  }
  for(int i=449; i>=151; i-=2){
    *(numbersPointer + j) = i;
    j++;
    numbersVector.push_back(i);
    insertTail(&tail,i);
  }
  //printing
  printPointer(numbersPointer);
  printVector(numbersVector);
  printNodes(head);

}
