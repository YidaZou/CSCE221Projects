#include <iostream>

using namespace std;
int main () {
  //a
  unsigned long long numbers[8] = {65536, 78890, 12345, 98765, 87906, 45637, 863248, 4632768};
  //declaring pointer and allocating memory;
  unsigned long long *numbersPointer = (unsigned long long *)malloc(8*sizeof(unsigned long long));
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
  numbersPointer = (unsigned long long *)realloc(numbersPointer, 12*sizeof(unsigned long long));
  //adding more integers
  *(numbersPointer + 8) = 768;
  *(numbersPointer + 9) = 765;
  *(numbersPointer + 10) = 92034;
  *(numbersPointer + 11) = 65789;
  //printing the numbers
  for(unsigned long long i=0; i<12; i++){
    cout << *(numbersPointer + i) << endl;
  }
  return 0;
}
