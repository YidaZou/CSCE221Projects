#include <iostream>
#include <vector>

using namespace std;
int main () {
   //a
   //declaring and assigning eight 100000s to vector
   vector<int> numbers = {100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000};

   //b
   cout << "b:" << endl;
   //using push_back to add numbers to vector
   numbers.push_back(8000);
   numbers.push_back(9000);
   numbers.push_back(7000);
   //printing vector
   for(int i=0; i<numbers.size(); i++){
     cout << numbers.at(i) << endl;
   }

   //c
   cout << "c:" << endl;
   numbers.pop_back();
   numbers.pop_back();
   numbers.pop_back();
   numbers.pop_back();
   numbers.pop_back();
   //printing vector
   for(int i=0; i<numbers.size(); i++){
     cout << numbers.at(i) << endl;
   }

   //d
   cout << "d:" << endl;
   cout << numbers.size() << endl;

   //e
   //inserting a number into beginning of vector
   numbers.insert(numbers.begin(), 89748);

   //f
   //inserting a number into beginning of vector
   //emplace doesn't produce a copy of object
   numbers.emplace(numbers.begin(), 50000);

   //g
   //inserting a number at the end of vector
   //emplace doesn't produce a copy of object
   numbers.emplace_back(78);
   cout << "g" << endl;
   //printing vector
   for(int i=0; i<numbers.size(); i++){
     cout << numbers.at(i) << endl;
   }
   return 0;
}
