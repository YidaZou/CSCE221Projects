#include <iostream>
using namespace std;
//cube_list struct
struct cube_list {
  int num;
  cube_list *prev;
  cube_list *next;
};
struct cube_list *head, *tail; //head and tail for struct

//function to add new cubes
void insert(int newNum) {
   struct cube_list* newCube = (struct cube_list*)malloc(sizeof(struct cube_list));
   newCube->num = newNum;
   newCube->prev = NULL;
   newCube->next = head;
   if(head != NULL)
   head->prev = newCube;
   head = newCube;
}

//function to print cube_list
void print() {
   struct cube_list* pointer;
   pointer = head;
   while(pointer != NULL) {
      cout << pointer->num << endl;
      pointer = pointer->next;
   }
}

//CubeList class
class CubeList {
	private:
    int num;
    CubeList *next;
		CubeList *prev;
};


using namespace std;
int main () {
   //a
   cout << head << endl;
   for(int i=30;i>0;i--){
     insert(i);
   }
   print();

   //b
   cout << "b" << endl;
   insert(50*50);
   print();

}
