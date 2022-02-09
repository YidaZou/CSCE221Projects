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
if(front = -1 && rear =-1){
  return true;
}
return false;
}


//function to insert element in queue
void enqueue (int value)
{
//YOUR CODE HERE
}


//function to remove element from queue
void dequeue ( )
{
//YOUR CODE HERE
}


//function to display element at front
void showfront()
{
//YOUR CODE HERE
}


//function to display elements of the queue
void displayQueue()
{
//YOUR CODE HERE
}

int main()
{
 cout<<"Inserting elements in queue\n";
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
 dequeue();

 return 0;
}
