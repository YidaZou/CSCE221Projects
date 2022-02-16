#include <iostream>
using namespace std;

#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;

//Hint : Update Front and Rear

//function to check if queue is empty
bool isempty()
{
//YOUR CODE HERE
if(front == -1 && rear == -1){
  return true;
}
return false;
}


//function to insert element in queue
void enqueue (int value)
{
//YOUR CODE HERE
if(rear-front < 4){
  rear++;
  A[rear] = value;
  if(front == -1){
    front = 0;
  }
}else{
  cout << "Queue is full" << endl;
  return;
}

}


//function to remove element from queue
void dequeue ( )
{
//YOUR CODE HERE
if(front == -1){
  cout << "Queue is empty" << endl;
  return;
}
front++;
if(front > rear){
  front = rear = -1;
}
}


//function to display element at front
void showfront()
{
//YOUR CODE HERE
cout << A[front] << endl;
}


//function to display elements of the queue
void displayQueue()
{
//YOUR CODE HERE
if(front == -1 && rear == -1){
  cout << "Queue is empty" << endl;
  return;
}
for(int i=front; i<=rear; i++){
  cout << A[i] << " ";
}
cout << endl;
}

int main()
{
 cout<<"Inserting elements in queue\n";
 cout << sizeof(A) << endl;
 enqueue(2);
 displayQueue();
 enqueue(3);
 displayQueue();
 enqueue(5);
 displayQueue();
 enqueue(7);
 displayQueue();
 enqueue(8);

 displayQueue();
 enqueue(9);

 showfront();

 cout<<"Removing elements from queue\n";
 dequeue();
 displayQueue();
 dequeue();
 displayQueue();
 dequeue();
 displayQueue();
 dequeue();
 displayQueue();
 //dequeue();
 //displayQueue();

 enqueue(2);
 displayQueue();
 enqueue(3);
 displayQueue();
 cout << sizeof(A) << endl;

 return 0;
}
