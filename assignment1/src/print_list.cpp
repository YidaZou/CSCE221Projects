#include "NodeInfo.h"

void printList(){
  NodeInfo* pointer = head; //start pointer at head
  while(pointer != NULL) {  //while pointer points to a node
    cout << pointer->getNodeName() << " " << pointer->checkIfDir() << endl;
    pointer = pointer->next;
  }
}
