#include <iostream>
#include <vector>
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

//3) vector sorts
void vectorDescendingSelectionSort(vector<int> *v){
  int maxIndex;
  for(int i=0; i<300-1; i++){
    maxIndex = i;
    for(int j=i+1; j<300; j++){
      if(v->at(maxIndex) < v->at(j)){//finding the biggest unsorted element
        maxIndex = j;
      }
    }
    swap(v->at(i), v->at(maxIndex));//placing element into sorted portion
  }
}
void vectorDescendingBubbleSort(vector<int> *v){
  bool swapped = 1; //check if a swap has been made
  while (swapped){
    swapped = 0;
    for(int i=0; i<300-1; i++){
      if(v->at(i) > v->at(i+1)){
        swap(v->at(i), v->at(i+1));
        swapped = 1;
      }
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
  //printing
  printPointer(numbersPointer);
  printVector(numbersVector);
  printNodes();
  //making copies of datatypes to sort
  int *sortedPointer1 = (int*)malloc(300*sizeof(int));
  int *sortedPointer2 = (int*)malloc(300*sizeof(int));
  memcpy(sortedPointer1, numbersPointer, 300*sizeof(int));
  memcpy(sortedPointer2, numbersPointer, 300*sizeof(int));

  //2
  pointerAscendingInsertionSort(sortedPointer1);
  printPointer(sortedPointer1);
  printPointer(numbersPointer);

  //3
  /*
  vectorDescendingSelectionSort(&numbersVector);
  printVector(numbersVector);
  vectorDescendingSelectionSort(&numbersVector);
  printVector(numbersVector);
  */
  return 0;
}
