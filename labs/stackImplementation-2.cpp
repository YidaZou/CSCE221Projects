#include <iostream>
#include <vector>
using namespace std;

class CustomStack {
public:
    vector<int> stack;
    int n;
    CustomStack(int maxSize) {
         n = maxSize;
    }

    void push(int x);
    int pop();
    void increment(int k, int val);
    void print();
};

void CustomStack::push(int x) {
    //YOUR CODE HERE
    if(stack.size() < n)
      stack.push_back(x);
    }

int CustomStack::pop() {
    //YOUR CODE HERE
    if(stack.size() > 0){
      int temp = stack[stack.size()-1];
      stack.pop_back();
      return temp;
    }
    return -1;
    }

void CustomStack::increment(int k, int val){
    //YOUR CODE HERE
    if(k>stack.size()){
      k=stack.size();
    }
    for(int i=0; i<k; i++){
      stack.at(i) += val;
    }
    }

void CustomStack::print(){
    //YOUR CODE HERE
    for(int i=stack.size()-1; i>=0; i--){
      cout << stack.at(i) << endl;
    }
    }

int main(){
    int maxSize = 10;
    CustomStack* obj = new CustomStack(maxSize);
    // Use obj->push(ele) to push into the stack
    // Use int x = obj->pop() to pop an element from the stack
    // Print the stack after push and pop operations
    // Use obj->increment(k,val) to increment last k elements of stack by value = val

    obj->push(10);
    obj->push(20);
    obj->push(30);
    obj->push(40);
    obj->print();
    obj->increment(7,100);
    obj->print();

    return 0;
}
