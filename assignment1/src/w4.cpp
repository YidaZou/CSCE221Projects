#include <iostream>
using namespace std;

//cube_list struct
struct cube_list {
  unsigned long long num;
  cube_list *prev;
  cube_list *next;
};
struct cube_list *head, *tail; //head and tail for struct

//function to add new cube at head
void insertHead(unsigned long long newNum) {
  struct cube_list* newCube = (struct cube_list*)malloc(sizeof(struct cube_list));
  newCube->num = newNum;
  newCube->prev = NULL;
  newCube->next = head;
  head->prev = newCube;
  head = newCube;
  //newCube becomes the head and points next towards the old head
}

//function to add new cube at tail
void insertTail(unsigned long long newNum) {
  struct cube_list* newCube = (struct cube_list*)malloc(sizeof(struct cube_list));
  newCube->num = newNum;
  newCube->prev = tail;
  newCube->next = NULL;
  tail->next = newCube;
  tail = newCube;
  //newCube becomes the tail and points prev towards the old tail
}

//function to add cube to middle of list
void insertMid(unsigned long long newNum) {
  struct cube_list* newCube = (struct cube_list*)malloc(sizeof(struct cube_list));
  struct cube_list* pointer1 = head;
  struct cube_list* pointer2 = head;
  //find middle
  while (pointer2 != NULL && pointer2->next != NULL) {
    pointer1 = pointer1->next;
    pointer2 = pointer2->next->next;
  }
  newCube->num = newNum;
  newCube->prev = pointer1->prev;
  pointer1->prev->next = newCube;
  newCube->next = pointer1;
  pointer1->prev = newCube;
}

//function to remove cube from middle of list
void removeMid() {
  struct cube_list* pointer1 = head;
  struct cube_list* pointer2 = head;
  //find middle
  while (pointer2 != NULL && pointer2->next != NULL) {
    pointer1 = pointer1->next;
    pointer2 = pointer2->next->next;
  }
  pointer1->prev->next = pointer1->next;
  pointer1->next->prev = pointer1->prev;
  delete pointer1;
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
    unsigned long long num;
    CubeList *next;
		CubeList *prev;
};
CubeList *headC, *tailC;

//function to add new cube at head
void insertHeadC(unsigned long long newNum) {
  CubeList* newCube = (CubeList*)malloc(sizeof(CubeList));
  newCube->num = newNum;
  newCube->prev = NULL;
  newCube->next = headC;
  headC->prev = newCube;
  headC = newCube;
  //newCube becomes the head and points next towards the old head
}

//function to add new cube at tail
void insertTailC(unsigned long long newNum) {
  CubeList* newCube = (CubeList*)malloc(sizeof(CubeList));
  newCube->num = newNum;
  newCube->prev = tailC;
  newCube->next = NULL;
  tailC->next = newCube;
  tailC = newCube;
  //newCube becomes the tail and points prev towards the old tail
}

//function to add cube to middle of list
void insertMidC(unsigned long long newNum) {
  CubeList* newCube = (CubeList*)malloc(sizeof(CubeList));
  CubeList* pointer1 = headC;
  CubeList* pointer2 = headC;
  //find middle
  while (pointer2 != NULL && pointer2->next != NULL) {
    pointer1 = pointer1->next;
    pointer2 = pointer2->next->next;
  }
  newCube->num = newNum;
  newCube->prev = pointer1->prev;
  pointer1->prev->next = newCube;
  newCube->next = pointer1;
  pointer1->prev = newCube;
}

//function to remove cube from middle of list
void removeMidC() {
  CubeList* pointer1 = headC;
  CubeList* pointer2 = headC;
  //find middle
  while (pointer2 != NULL && pointer2->next != NULL) {
    pointer1 = pointer1->next;
    pointer2 = pointer2->next->next;
  }
  pointer1->prev->next = pointer1->next;
  pointer1->next->prev = pointer1->prev;
  delete pointer1;
}

//function to print CubeList
void printC() {
  CubeList* pointer = headC;
  while(pointer != NULL) {
    cout << pointer->num << endl;
    pointer = pointer->next;
  }
}

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
   tailC = (CubeList*)malloc(sizeof(CubeList));
   headC = (CubeList*)malloc(sizeof(CubeList));
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
   cout << "d" << endl;
   //struct
   insertMid(40*40);
   print();
   //class
   insertMidC(40*40);
   printC();

   //e
   cout << "e" << endl;
   //struct
   removeMid();
   print();
   //class
   removeMidC();
   printC();

   //f
   cout << "f" << endl;
   //struct
   struct cube_list* temp = head->next;
   head->next = temp->next;
   temp->next->prev = head;
   delete temp;
   print();
   //class
   CubeList* tempC = headC->next;
   headC->next = tempC->next;
   tempC->next->prev = headC;
   delete tempC;
   printC();

}
