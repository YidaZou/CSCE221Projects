#include <iostream>

using namespace std;
int main () {
  //a
  int numbers[8] = {65536, 78890, 12345, 98765, 87906, 45637, 863248, 4632768};
  //declaring pointer and allocating memory;
  int *numbersPointer = (int *)malloc(8*sizeof(int));
  //assigning the numbers into the memory pointed to by the pointer
  for(int i=0; i<8; i++){
    *(numbersPointer + i) = numbers[i];
  }

  //b
  cout << "b:" << endl;
  //printing the numbers
  for(int i=0; i<8; i++){
    cout << *(numbersPointer + i) << endl;
  }

  //c
  cout << "c:" << endl;
  //printing the adresses of the numbers
  for(int i=0; i<8; i++){
    cout << (numbersPointer + i) << endl;
  }

  //d
  cout << "d:" << endl;
  //reallocating memory
  numbersPointer = (int *)realloc(numbersPointer, 12*sizeof(int));
  //adding more integers
  *(numbersPointer + 8) = 768;
  *(numbersPointer + 9) = 765;
  *(numbersPointer + 10) = 92034;
  *(numbersPointer + 11) = 65789;
  //printing the numbers
  for(int i=0; i<12; i++){
    cout << *(numbersPointer + i) << endl;
  }
  return 0;
}
