#ifndef _PRINTLIST_CPP
#define _PRINTLIST_CPP

//#include <NodeInfo.h>

/*
 * This function prints contents of the linked list
 */
void printList()
{
  NodeInfo* pointer = head; //start pointer at head
  while(pointer != NULL) {  //while pointer points to a node
    cout << pointer->getNodeName() << " " << pointer->checkIfDir() << endl;
    pointer = pointer->next;
  }
}

#endif
