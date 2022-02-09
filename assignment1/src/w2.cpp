#include <iostream>

using namespace std;
int main () {
   //a
   //putting numbers into array
   unsigned long long numbers[8] = {65536, 78890, 12345, 98765, 87906, 45637, 863248, 4632768};

   //b
   cout << "b:" << endl;
   for(int i=7; i>=0; i--){
     //printing numbers in reverse
     cout << numbers[i] << endl;
   }

   //c
   cout << "c:" << endl;
   for(int i=0; i<8; i++){
     //printing addresses in reverse
     cout << &numbers[i] << endl;
   }
   //d
   //you can't add a 9th element to the array
   return 0;
}
