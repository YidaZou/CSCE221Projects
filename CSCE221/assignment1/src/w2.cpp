#include <iostream>

using namespace std;
int main () {
   int numbers[8] = {65536, 78890, 12345, 98765, 87906, 45637, 863248, 4632768};
   for(int i=7; i>=0; i--){
     //numbers in reverse
     cout << numbers[i] << endl;
   }
   for(int i=7; i>=0; i--){
     //addresses in reverse
     cout << &numbers[i] << endl;
   }
   return 0;
}
