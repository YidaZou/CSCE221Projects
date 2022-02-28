#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//linked list
struct numbersNode {
  int num;
  numbersNode *prev;
  numbersNode *next;
};
struct numbersNode *head, *tail;
void insertTail(int newNum) {
  //linked list
  struct numbersNode* newNode = (struct numbersNode*)malloc(sizeof(struct numbersNode));
  newNode->num = newNum;
  newNode->prev = tail;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
  //newNode becomes the tail and points prev towards the old tail
}

//printing
void printNodes(){
  struct numbersNode* pointer = head;
  while(pointer != NULL) {
    cout << pointer->num << " ";
    pointer = pointer->next;
  }
  cout<<endl;
}
void printPointer(int* p){
  for(int i=0; i<300; i++){
    cout << *(p + i) << " ";
  }
  cout<<endl;
}
void printVector(vector<int> v){
  for(int i=0; i<300; i++){
    cout << v.at(i) << " ";
  }
  cout<<endl;
}

int main() {
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
  //printing
  printPointer(numbersPointer);
  printVector(numbersVector);
  printNodes();
  return 0;
}
