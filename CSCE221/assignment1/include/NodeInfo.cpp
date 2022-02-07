#include "NodeInfo.h"

vector<string> tokenize_input_string(string line){
  vector<string> inputs;
  string temp;
  for(int i=0; i<line.size(); i++){
    //detects separate string to add to inputs vector
    if(line[i] == ' '){
      inputs.push_back(temp);
      temp = "";
    }else{
      temp += line[i];
    }
  }
  return inputs;
}

void append(vector<string> strList){
  //making newNode and adding data from strList;
  NodeInfo* newNode = (struct NodeInfo*)malloc(sizeof(struct NodeInfo));
  newNode->setIfDir(strList.at(0));
  newNode->setName(strList.at(1));
  //newNode->setParent(strList.at(2));
  if(head == NULL && tail == NULL){
    head = newNode;
    tail = head;
  }else{
    tail->next = newNode;
    newNode->parent = tail;
    tail = newNode;
  }
}
