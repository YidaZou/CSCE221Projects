/*
 * This function prints contents of the linked list
 */

void printList(NodeInfo *node)
{
  NodeInfo* pointer = head; //start pointer at head
  while(pointer != NULL) {  //while pointer points to a node
    cout << pointer->getNodeName() << " " << pointer->checkIfDir() << endl;
    pointer = pointer->next;
  }
  /* Follow the format of the output given in the documentation */
}
