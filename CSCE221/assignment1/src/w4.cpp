#include <iostream>
using namespace std;
//cube_list struct
struct cube_list {
  int num;
  cube_list *prev;
  cube_list *next;
};
struct cube_list *head, *tail; //head and tail for struct

//function to add new cube at head
void insertHead(int newNum) {
  struct cube_list* newCube = (struct cube_list*)malloc(sizeof(struct cube_list));
  newCube->num = newNum;
  newCube->prev = NULL;
  newCube->next = head;
  head->prev = newCube;
  head = newCube;
  //newCube becomes the head and points next towards the old head
}

//function to add new cube at tail
void insertTail(int newNum) {
  struct cube_list* newCube = (struct cube_list*)malloc(sizeof(struct cube_list));
  newCube->num = newNum;
  newCube->prev = tail;
  newCube->next = NULL;
  tail->next = newCube;
  tail = newCube;
  //newCube becomes the tail and points prev towards the old tail
}

//function to add cube to middle of list
void insertMid(int newNum) {
  struct cube_list* newCube = (struct cube_list*)malloc(sizeof(struct cube_list));
  struct cube_list* pointer1 = head;
  struct cube_list* pointer2 = head;
  //find middle
  while (pointer1 != NULL) {
    pointer1 = pointer1->next;
    pointer2 = pointer2->next->next;
  }
  newCube->num = newNum;
  newCube->prev = pointer2;
  pointer2->next->prev = newCube;
  newCube->next = pointer2->next;
  pointer2->next = newCube;
}

//function to print cube_list
void print() {
  struct cube_list* pointer = head;
  while(pointer != NULL) {
    cout << pointer->num << endl;
    pointer = pointer->next;
  }
}

//CubeList class
class CubeList {
  public:
    int num;
    CubeList *next;
		CubeList *prev;
};
CubeList *headC, *tailC;

//function to add new cube at head
void insertHeadC(int newNum) {
  CubeList* newCube = (struct CubeList*)malloc(sizeof(struct CubeList));
  newCube->num = newNum;
  newCube->prev = NULL;
  newCube->next = headC;
  headC->prev = newCube;
  headC = newCube;
  //newCube becomes the head and points next towards the old head
}

//function to add new cube at tail
void insertTailC(int newNum) {
  CubeList* newCube = (struct CubeList*)malloc(sizeof(struct CubeList));
  newCube->num = newNum;
  newCube->prev = tailC;
  newCube->next = NULL;
  tailC->next = newCube;
  tailC = newCube;
  //newCube becomes the tail and points prev towards the old tail
}

//function to add cube to middle of list
void insertMidC(int newNum) {
  CubeList* newCube = (struct CubeList*)malloc(sizeof(struct CubeList));
  CubeList* pointer1 = headC;
  CubeList* pointer2 = headC;
  //find middle
  while (pointer1 != NULL) {
    pointer1 = pointer1->next;
    pointer2 = pointer2->next->next;
  }
  newCube->num = newNum;
  newCube->prev = pointer2;
  pointer2->next->prev = newCube;
  newCube->next = pointer2->next;
  pointer2->next = newCube;
}

//function to print CubeList
void printC() {
  CubeList* pointer = headC;
  while(pointer != NULL) {
    cout << pointer->num << endl;
    pointer = pointer->next;
  }
}


using namespace std;
int main () {
   //a
   //struct
   //initialize head and tail
   tail = (struct cube_list*)malloc(sizeof(struct cube_list));
   head = (struct cube_list*)malloc(sizeof(struct cube_list));
   tail->num = 30;
   tail->prev = head;
   tail->next = NULL;
   head = tail;
   for(int i=29;i>0;i--){
     insertHead(i);
   }
   //class
   //initialize head and tail
   tailC = (struct CubeList*)malloc(sizeof(struct CubeList));
   headC = (struct CubeList*)malloc(sizeof(struct CubeList));
   tailC->num = 30;
   tailC->prev = headC;
   tailC->next = NULL;
   headC = tailC;
   for(int i=29;i>0;i--){
     insertHeadC(i);
   }

   //b
   cout << "b" << endl;
   //struct
   insertHead(50*50);
   print();
   //class
   insertHeadC(50*50);
   printC();

   //c
   cout << "c" << endl;
   //struct
   insertTail(60*60);
   print();
   //class
   insertTailC(60*60);
   printC();

   //d

}
