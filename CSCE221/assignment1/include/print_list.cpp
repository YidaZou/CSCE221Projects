#include "NodeInfo.cpp"

void printList(NodeInfo*){
  NodeInfo* pointer = head;
  while(pointer != NULL) {
    cout << pointer->getNodeName() << " " << pointer->checkIfDir() << endl;
    pointer = pointer->next;
  }
}
