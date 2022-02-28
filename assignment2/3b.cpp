#include "functions.h"

int main() {
  vector<int> numbersVector;
  //adding integers
  for(int i=150; i<=448; i+=2){
    numbersVector.push_back(i);
  }
  for(int i=449; i>=151; i-=2){
    numbersVector.push_back(i);
  }

  //3
  vector<int> sortedVector1 = numbersVector;

  vectorDescendingBubbleSort(&sortedVector1);

  //printing
  printVector(sortedVector1);

}
