#include <iostream>
using namespace std;

#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;

int queueAmount = 0;
bool isempty()
{
  if(front == -1 && rear == -1){
    return true;
  }
  return false;
}

void enqueue ( int value )
{
  if(queueAmount>=5){
    cout<<"Queue Full"<<endl;
    return;
  }
  if(front == -1){
      front = 0;
      rear = 0;
    }else{
      if(rear == SIZE-1)
        rear = 0;
      else
        rear += 1;
   }
   A[rear] = value;
   queueAmount++;
}

void dequeue ( )
{
  if(front == -1){
      cout<<"Empty Queue";
      return;
    }
  if(front == rear){
    front = -1;
    rear = -1;
  }else{
    if(front == SIZE-1)
      front = 0;
    else
      front += 1;
  }
  queueAmount--;

}

int showfront( )
{
  cout << A[front] << endl;
  return front;
}

void modifyElements()
{
  int mult = A[front];
  for(int i=front+1; i<=rear; i++){
    A[i] *= mult;
  }
}

void displayQueue()
{
  int f = front;
  int r = rear;
  if(front == -1){
    cout<<"Empty Queue"<<endl;
    return;
  }
  if(f <= r){
    while (f <= r){
       cout<<A[f]<<" ";
       f++;
    }
  }else{
    while(f <= SIZE-1){
       cout<<A[f]<<" ";
       f++;
    }
    f = 0;
    while (front <= rear){
       cout<<A[f]<<" ";
       f++;
    }
  }
  cout << endl;
}

void displayArray()
{
  for(int i=0; i<5; i++){
    cout << A[i] << " ";
  }
}

int main()
{
 cout<<"Inserting elements in queue\n";
 enqueue(2);
 enqueue(3);
 enqueue(5);
 enqueue(7);
 enqueue(8);
 cout<<"Displaying queue\n";
 displayQueue();

 cout<<"Removing elements from queue\n";
 dequeue();
 cout<<"Displaying Queue\n";
 displayQueue();

 modifyElements();
 cout<<"Queue after modifying\n";
 displayQueue();

 cout<<"Inserting elements into queue\n";
 enqueue(9);
 enqueue(10);
 cout<<"Displaying Array\n";
 displayArray();

 cout << "Showfront\n";
 showfront();

 return 0;
}
