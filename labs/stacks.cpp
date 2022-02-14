#include <iostream>
#include <vector>
using namespace std;

class CustomStack {
public:
    vector<int> stack, inc;
    int n;
    CustomStack(int maxSize) {
         n = maxSize;
    }

    void push(int x);
    int pop();
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

int main(){
    int maxSize = 10;
    CustomStack* obj = new CustomStack(maxSize);
    obj->push(10);
    obj->push(9);
    obj->push(8);
    int param_1 = obj->pop();
    int param_2 = obj->pop();
    int param_3 = obj->pop();

    //YOUR CODE HERE
    //PRINT param_1,param_2,param_3
    cout << param_1 << endl;
    cout << param_2 << endl;
    cout << param_3 << endl;
    //Feel free to push/pops numbers of your choice

    return 0;
}
