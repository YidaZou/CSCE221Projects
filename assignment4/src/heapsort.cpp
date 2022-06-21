#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <climits>

using namespace std;

class City{ //vertexes
    public:
    string name;
    vector<pair<City*, int>> edge;  //connected city and distance
    City(string name){
        this->name = name;
    }

};

struct Node{  //nodes in heap
  int key;
  City* name;

  Node(City* name, int key){
    this->name = name;
    this->key = key;
  }
};

class heap{ //min heap

  vector<Node*> heapList;
  
public:

  void minHeapify(unsigned int i){ //fix min heap
    //indexes
    unsigned int min = i;    //root
    unsigned int l = 2*i+1;  //left
    unsigned int r = 2*i+2;  //right

    if(l<heapList.size() && heapList[l]->key < heapList[min]->key) 
      min = l; //left child is less than parent
    if(r<heapList.size() && heapList[r]->key < heapList[min]->key) 
      min = r; //right child is less than parent
    
    if(min != i){ //if min changed
      swap(heapList[i], heapList[min]);

      minHeapify(min);
    }
  }

  void insert(Node* &newNode){  //insert into heap
    heapList.push_back(newNode);  //add to end
    minHeapify(0);  //fix heap

  }

  void removeMin(){
    swap(heapList[heapList.size()-1], heapList[0]); //swap root with last node
    heapList.pop_back();  //delete last element
    minHeapify(0);  //fix heap
  }

  Node* min(){return heapList[0];}  //returns root of heap
  int size(){return heapList.size();}  //returns size of heap
  bool isEmpty(){return (heapList.empty());} //returns true is heap is empty, false otherwise

};
