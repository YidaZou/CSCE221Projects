/*Question: Create two linked lists l1 and l2 such that l1 and l2 are sorted.
            Use the concept of recursion to merge these two sorted lists into a single list
  Example : l1 = [1,3,4] l2 = [2,5,6] Expected output: [1,2,3,4,5,6]
            l1 = []      l2 = [4,7,8] Expected output: [4,7,8]
*/

 #include <iostream>
 using namespace std;
 struct ListNode {
     int data;
     ListNode *next;
  };


ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
// YOUR CODE HERE : Merge the two lists given
  if(l1==NULL)//l1 is empty
      return l2;
  if(l2==NULL)//l2 is empty
      return l1;

  if(l1->data < l2->data){//find smaller value
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
  }else{
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
  }
}

void printList(ListNode* node){
// YOUR CODE HERE : Print the merged list
  ListNode* pointer = node;
  while(pointer!=NULL){
    cout << pointer->data << " ";
    pointer = pointer->next;
  }
  cout << endl;
}

int main(){

    ListNode* result;

    ListNode* head1 = new ListNode();
    ListNode* head2 = new ListNode();

    // YOUR CODE HERE - Create two linked lists (sorted ones)
    head1->data = 7;
    head1->next = NULL;
    head2->data = 6;
    head2->next = NULL;
    for(int i=2; i>=1; i--){
      //head1
      ListNode* newNode = new ListNode();
      newNode->data = i;
      newNode->next = head1;
      head1 = newNode;

      //head2
      ListNode* newNode2 = new ListNode();
      newNode2->data = i+3;
      newNode2->next = head2;
      head2 = newNode2;
    }

    cout << "Before merging"<<endl;
    printList(head1);
    printList(head2);


    result = mergeTwoLists(head1,head2);

    cout << "After merging"<<endl;
    printList(result);
}
