#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <array>
using namespace std;

struct node{
  unsigned long long int data;
  node *next;
};

//Stack stuff
struct node* t = NULL;  //top of stack
void pushS(unsigned long long int val){
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = val;
  newNode->next = t;
  t = newNode;
}
unsigned long long int popS(){
  unsigned long long int out = t->data; //store top to return;
  t = t->next;
  return out;
}
unsigned long long int top(){
  return t->data;
}
bool isEmptyS(){
  if(t==NULL){
    return true;
  }else{
    return false;
  }
}

//Queue stuff
struct node* f = NULL;  //front of queue
struct node* r = NULL;  //rear of queue

void pushQ(unsigned long long int val){
  if(r == NULL){ //empty queue
    r = (struct node *)malloc(sizeof(struct node));
    r->next = NULL;
    r->data = val;
    f = r;
  }else{
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    r->next = newNode;
    newNode->data = val;
    newNode->next = NULL;
    r = newNode;
  }
}
unsigned long long int popQ(){
  struct node* temp = f;
  unsigned long long int out = f->data;
  if(temp->next != NULL){ //more than one element in queue
    temp = temp->next;
    free(f);
    f = temp; //reassigning front;
    return out;
  }else{  //only 1 element in queue;
    free(f);
    f = NULL;
    r = NULL;
    return out;
  }
}
unsigned long long int front(){
  return f->data;
}
bool isEmptyQ(){
  if(f==NULL){
    return true;
  }else{
    return false;
  }
}

//arbiter
unsigned long long int opcodes[] = {0x601, 0x602, 0x604, 0x504, 0x502, 0x442, 0x603, 0x536, 0x605, 0x603, 0x503, 0x505, 0x335, 0x601, 0x516};
unsigned long long int a = 55, b = 20, c = 276, d = 100, e = 203, acc = 0;
void operand(unsigned long long int num){
  unsigned long long int temp;
  if (((num >> 8) & 0xf) == 0x6){
    if ((num & 0x00f) == 0x001)
      pushS(a);
    else if ((num & 0x00f) == 0x002)
      pushS(b);
    else if ((num & 0x00f) == 0x003)
      pushS(c);
    else if ((num & 0x00f) == 0x004)
      pushS(d);
    else if ((num & 0x00f) == 0x005)
      pushS(e);
    else if ((num & 0x00f) == 0x006)
      pushS(acc);
  }
  //5XX
  else if (((num >> 8) & 0xf) == 0x5){
    if ((num & 0x0f0) == 1){
    //0 or 6 in the middle
    }else{
      if ((num & 0x00f) == 0x001)
        temp = a;
      else if ((num & 0x00f) == 0x002)
        temp = b;
      else if ((num & 0x00f) == 0x003)
        temp = c;
      else if ((num & 0x00f) == 0x004)
        temp = d;
      else if ((num & 0x00f) == 0x005)
        temp = e;
      else if ((num & 0x00f) == 0x006)
        temp = acc;

      if(temp == top()){ //check if top of stack matches
        popS();
        pushQ(temp);
      }else{
        cout << "Stack Wrong operand requested" << endl;
        exit(0);
      }
    }
  }
}
int main() {
  unsigned long long int num;
  for(unsigned long long int i=0; i<sizeof(opcodes)/sizeof(opcodes[0]); i++){
    num = opcodes[i];
    operand(num);
    cout << "Operand" << i << " " << opcodes[i] << endl;
    }
  return 0;
}
