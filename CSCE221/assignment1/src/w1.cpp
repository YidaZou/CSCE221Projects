#include <iostream>

using namespace std;
int main () {
   int *intPointer [8];

   *intPointer = 65536, 78890, 12345, 98765, 87906, 45637, 863248, 4632768;
   cout << *intPointer << endl;
   cout << intPointer << endl;
   return 0;
}
