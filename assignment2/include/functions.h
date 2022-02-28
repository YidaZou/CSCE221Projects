#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
/*

  HEADER FILE FOR ALL THE FUNCTIONS FOR ASSIGNMENT 2 (1-8) - Yida Zou

*/


//linked list
struct numbersNode {
  int num;
  numbersNode *prev;
  numbersNode *next;
};
//insertion for linked list
void insertTail(struct numbersNode **t, int newNum) {
  struct numbersNode* newNode = (struct numbersNode*)malloc(sizeof(struct numbersNode));
  newNode->num = newNum;
  newNode->prev = *t;
  newNode->next = NULL;
  (*t)->next = newNode;
  *t = newNode;
  //newNode becomes the tail and points prev towards the old tail
}

//1b) printing
void printNodes(struct numbersNode* h){
  struct numbersNode* pointer = h;
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
  int temp; //for swapping
  for(int i=1; i<300; i++){//loop through all elements staring from position 1;
    for(int j=i; j>0 && *(p+(j-1))>*(p+j); j--){//for sorted portion
      //shifting selected element to the left while pushing others to the right.
      temp = *(p+j);
      *(p+j) = *(p+(j-1));
      *(p+(j-1)) = temp;
    }
  }
}

void pointerAscendingExchangeSort(int *p){
  int temp; //for swapping
  for(int i=0; i<300; i++){ //selecting element
		for (int j=i+1; j<300; j++){  //comparing to all other elements;
			if(*(p+i) > *(p+j)){
				temp = *(p+i);
				*(p+i) = *(p+j);
				*(p+j) = temp;
			}
		}
	}
}

//3)vector sorts
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
      if(v->at(i) < v->at(i+1)){
        swap(v->at(i), v->at(i+1));
        swapped = 1;
      }
    }
  }
}

//4)linked list sorts
void listAscendingInsertionSort(struct numbersNode** h) {
  //sorted list
  struct numbersNode* sortedNodes = NULL;
  //pointer to traverse inputted list
  struct numbersNode* pointer = *h;
  while(pointer!=NULL){//loop through all elements staring from position 1;
    struct numbersNode* nextPointer = pointer->next;  //store next element
    pointer->prev = pointer->next = NULL;

    struct numbersNode* sortedPointer;  //for sorted portion of list
    if(sortedNodes == NULL){//empty sorted list
      sortedNodes = pointer;
    }else if(sortedNodes->num >= pointer->num){ //for inserting at beginnning
      pointer->next = sortedNodes;
      pointer->next->prev = pointer;
      sortedNodes = pointer;
    }else{
      sortedPointer = sortedNodes;
      while(sortedPointer->next != NULL && sortedPointer->next->num < pointer->num){//locate where to insert after
        sortedPointer = sortedPointer->next;
      }
      pointer->next = sortedPointer->next;
      if(sortedPointer->next != NULL){  //check not end of list
        pointer->next->prev = pointer;
      }
      sortedPointer->next = pointer;
      pointer->prev = sortedPointer;

    }
    pointer = nextPointer;
  }
  //update tail

}

void listAscendingExchangeSort(struct numbersNode** h) {
  for(numbersNode* p1=*h; p1!=NULL; p1=p1->next){ //selecting element
		for(numbersNode* p2=p1->next; p2!=NULL; p2=p2->next){  //comparing to all other elements;
			if(p1->num > p2->num){
				swap(p1->num, p2->num);
			}
		}
	}
}

void pointerLinearSearch(int *p, int find){
  for(int i=0; i<300; i++){
    if(*(p+i) == find){
      cout << (p+i) << " " << i << endl;
    }
  }
}

void vectorLinearSearch(vector<int> v, int find){
  for(int i=0; i<300; i++){
    if(v.at(i) == find){
      cout << &(v.at(i)) << " " << i << endl;
    }
  }
}

void listLinearSearch(numbersNode* h, int find){
  numbersNode *pointer = h;
  while(pointer != NULL){
    if(pointer->num == find){
      cout << &pointer << endl;
    }
    pointer = pointer->next;
  }
}

//ascending pointer
void pointerAscendingBinarySearch(int *p, int find, int left, int right){
  if(right >= left){
      int mid = left + (right-left)/ 2;
      if (*(p+mid) == find){ //the element to find is the middle
        cout << (p+mid) << " " << mid << endl;
        return;
      }

      if (find < (*p+mid)) //the element is less than mid
        return pointerAscendingBinarySearch(p, find, left, mid-1);

      //the element is greater than mid
      return pointerAscendingBinarySearch(p, find, mid+1, right);
    }
  //element not found
  cout << "element not in pointer" << endl;
  return;
}

//descending vector
void vectorDescendingBinarySearch(vector<int> v, int find, int left, int right){
  if(right >= left){
      int mid = left + (right-left)/ 2;
      if (v.at(mid) == find){ //the element to find is the middle
        cout << &(v.at(mid)) << " " << mid << endl;
        return;
      }

      if (find > v.at(mid)) //the element is greater than mid
        return vectorDescendingBinarySearch(v, find, left, mid-1);

      //the element is less than mid
      return vectorDescendingBinarySearch(v, find, mid+1, right);
    }
  //element not found
  cout << "element not in vector" << endl;
  return;
}

numbersNode* findMid(numbersNode* h, numbersNode* t){
  numbersNode* pointer1 = h;  //will be middle
  numbersNode* pointer2 = h->next;  //twice as fast as pointer1
  //find middle
  while(pointer2 != t){
    pointer2 = pointer2->next;
    if(pointer2 != t){
      pointer1 = pointer1->next;
      pointer2 = pointer2->next;
    }
  }
  return pointer1;
}

//ascending list
void listAscendingBinarySearch(int find, numbersNode *h){
  numbersNode* start = h;
  numbersNode* end = NULL;
  do{
    numbersNode* mid = findMid(start, end);
    if(mid->num == find){ //element to find is mid
      cout << &mid << endl;
      return;
    }else if(mid->num < find){ //element to find is less than mid
      start = mid->next;
    }else{  //element to find is greater than mid
      end = mid;
    }
   }
   while(end == NULL || start != end);
  //element not found
  cout << "element not in list" << endl;
  return;
}
