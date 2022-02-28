#include "functions.h"

int main() {
  //linked list //initializing head & tail
  struct numbersNode *head, *tail;
  tail = (struct numbersNode*)malloc(sizeof(struct numbersNode));
  head = (struct numbersNode*)malloc(sizeof(struct numbersNode));
  head->num = 150;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
  //adding integers
  for(int i=150; i<=448; i+=2){
    if(i!=150)//first value is already entered
      insertTail(&tail,i);
  }
  for(int i=449; i>=151; i-=2){
    insertTail(&tail,i);
  }
  
  listAscendingExchangeSort(&head);
  printNodes(head);
  return 0;
}
