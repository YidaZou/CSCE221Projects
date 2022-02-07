#include "NodeInfo.h"

void printList(){
  NodeInfo* pointer = head;
  while(pointer != NULL) {
    cout << pointer->getNodeName() << " " << pointer->checkIfDir() << endl;
    pointer = pointer->next;
  }
}
