#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <array>
using namespace std;

//EDIT LINE 85 WITH YOUR INPUTS

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



//EDIT THE ARRAY BELOW WITH YOUR OPERANDS {none, a, b, c, d, e, acc}
unsigned long long int operands[] = {0, 55, 20, 276, 100, 203, 0};

unsigned long long int opcodes[] = {0x601, 0x602, 0x604, 0x504, 0x502, 0x442, 0x603, 0x536, 0x605, 0x603, 0x503, 0x505, 0x335, 0x601, 0x516};
//arbiter
void operand(unsigned long long int num){
  unsigned long long int temp = 0;
  //60X push
  if(((num >> 8) & 0xf) == 0x6){
    pushS(operands[(num & 0x00f)]);
  //5XX pop
  }else if(((num >> 8) & 0xf) == 0x5){
    //0 or 6 in the middle
    if((num & 0x0f0) == 0x060 || (num & 0x0f0) == 0x000){
      temp = operands[(num & 0x00f)];  //give temp the value of the operand on the right

      if(temp == top()){ //check if operand is at the top of stack
        popS();
        pushQ(temp);
        cout << "popS, pushQ" << endl;
      }else{
        cout << "Stack Wrong operand requested" << endl;
        exit(0);
      }
    //1-5 in middle
    }else{
      temp = operands[((num & 0x0f0)>>4)];  //give temp value of operand in middle
      if(!(isEmptyQ()) && temp == front()){ //check if operand is at the front of the queue
        popQ();
        operands[((num & 0x0f0)>>4)] = operands[6];
      }else{  //not at front
        if(!(isEmptyS()) && temp == top()){  //check if operand is at the top of stack
          popS();
          operands[((num & 0x0f0)>>4)] = operands[6];
          cout << "popS, BypassQ" << endl;
        }else{  //not at top
          pushS(temp);
          popS();
          operands[((num & 0x0f0)>>4)] = operands[6];
        }
      }
    }
  //Arithmetic operations 1-4
  }else{
    unsigned long long int x = popQ();  //XxX 1st operand
    unsigned long long int y = popQ();  //XXy 2nd operand
    /*  //for testing
    cout<< "x: " << x << endl;
    cout<< "y: " << y << endl;
    cout<< "0x0f0: " << ((num & 0x0f0)>>4) << endl;
    cout<< "0x0f0: " << (num & 0x0f0) << endl;
    */
    if(x == operands[((num & 0x0f0)>>4)] && y == operands[(num & 0x00f)]){
      //1XX +
      if(((num >> 8) & 0xf) == 0x1){
        operands[6] = x+y;
      //2XX -
      }else if(((num >> 8) & 0xf) == 0x1){
        operands[6] = x-y;
      //3XX *
      }else if(((num >> 8) & 0xf) == 0x3){
        operands[6] = x*y;
      //4XX /
      }else if(((num >> 8) & 0xf) == 0x4){
        operands[6] = x/y;
      }
    }else{
      cout << "Arithmetic Wrong operand requested" << endl;
      exit(0);
    }
  }
}
int main() {
  unsigned long long int num;
  for(unsigned long long int i=0; i<sizeof(opcodes)/sizeof(opcodes[0]); i++){
    num = opcodes[i];
    operand(num);
    }
  for(unsigned long long int i=0; i<7; i++){
    cout << "Operand" << i << " " << operands[i] << " ";
  }
  cout << endl;
  return 0;
}
