#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

struct node{
  unsigned long long int data;
  node *next;
};

//Stack stuff
struct Node* top = NULL;
void pushS(int x){
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = x;
  newNode->next = top;
  top = newNode;
}
void popS(){
  if(top==NULL){
    cout << "empty stack" << endl;
  }else{
    cout << top->data <<endl;
    top = top->next;
  }
}
void topS(){
  cout << top->data << endl;
}
void isEmptyS(){
  if(top==NULL){
    cout << "empty stack" << endl;
  }else{
    cout << "not empty" << endl;
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  if ((num >> 8) & 0xf == 0x6)
  return 0;
}
