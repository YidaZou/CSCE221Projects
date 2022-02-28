#include "functions.h"

int main() {
  //1
  //linked list //initializing head & tail
  struct numbersNode *head1, *tail1, *head2, *tail2;
  tail1 = (struct numbersNode*)malloc(sizeof(struct numbersNode));
  head1 = (struct numbersNode*)malloc(sizeof(struct numbersNode));
  tail1->num = 150;
  tail1->prev = head1;
  tail1->next = NULL;
  head1 = tail1;
  tail2 = (struct numbersNode*)malloc(sizeof(struct numbersNode));
  head2 = (struct numbersNode*)malloc(sizeof(struct numbersNode));
  tail2->num = 150;
  tail2->prev = head2;
  tail2->next = NULL;
  head2 = tail2;
  //pointer
  int *numbersPointer1 = (int*)malloc(300*sizeof(int));
  int j = 0; //position of pointer
  //vector
  vector<int> numbersVector1;
  //adding integers
  for(int i=150; i<=448; i+=2){
    *(numbersPointer1 + j) = i;
    j++;
    numbersVector1.push_back(i);
    if(j!=1)//first value is already entered
      insertTail(&tail1,i);
      insertTail(&tail2,i);
  }
  for(int i=449; i>=151; i-=2){
    *(numbersPointer1 + j) = i;
    j++;
    numbersVector1.push_back(i);
    insertTail(&tail1,i);
    insertTail(&tail2,i);
  }
  //copying
  int *numbersPointer2 = (int*)malloc(300*sizeof(int));
  memcpy(numbersPointer2, numbersPointer1, 300*sizeof(int));
  vector<int> numbersVector2 = numbersVector1;
  //sorting
  struct timeval start, end;
  //2a
  gettimeofday(&start, NULL);

  pointerAscendingInsertionSort(numbersPointer1);

  gettimeofday(&end, NULL);
  printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
  //2b
  gettimeofday(&start, NULL);

  pointerAscendingInsertionSort(numbersPointer2);

  gettimeofday(&end, NULL);
  printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
  //3a
  gettimeofday(&start, NULL);

  vectorDescendingSelectionSort(&numbersVector1);

  gettimeofday(&end, NULL);
  printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
  //3b
  gettimeofday(&start, NULL);

  vectorDescendingBubbleSort(&numbersVector2);

  gettimeofday(&end, NULL);
  printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
  //4a
  gettimeofday(&start, NULL);

  listAscendingInsertionSort(&head1);

  gettimeofday(&end, NULL);
  printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
  //4b
  gettimeofday(&start, NULL);

  listAscendingBubbleSort(&head2);

  gettimeofday(&end, NULL);
  printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
  return 0;


}
