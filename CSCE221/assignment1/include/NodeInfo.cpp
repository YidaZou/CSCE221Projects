#include "NodeInfo.h"

NodeInfo *head, *tail;

string
NodeInfo::getParentName()
{
    // Not needed in assignment 1
}

void
NodeInfo::setParentName(string par_name)
{
    // Not needed in assignment 1
}

void
NodeInfo::setParent(string par_name)
{
    // Not needed in assignment 1
}

void
NodeInfo::setIfDir(string dir_str)
{
	/*
	 * If it is a directory "dir", set is_dir to true
	 * Otherwise, set is_dir to false
	 * Study "this->"
	 */
  if(dir_str == "dir"){
    is_dir = true;
  }else{
    is_dir = false;
  }
}

void
NodeInfo::setName(string name_str)
{
	/* Set name to name_str */
  name = name_str;
}

bool
NodeInfo::checkIfDir()
{
	/* Return the value of is_dir */
  return is_dir;
}

string
NodeInfo::getNodeName()
{
	/* Return the value of name */
  return name;
}

NodeInfo*
NodeInfo::getParent()
{
	// Not needed in assignment 1
}

vector<NodeInfo>
NodeInfo::getChildren()
{
    // Not needed in assignment 1
}

vector<string> tokenize_input_string(string line){
  vector<string> inputs;
  string temp;
  for(int i=0; i<line.size(); i++){
    //detects separate string to add to inputs vector
    if(line[i].compare("  ")){
      inputs.push_back(temp);
      temp = " ";
    }else{
      temp += line[i];
    }
  }
};

void append(NodeInfo** Nodes, vector<string> strList){
  //making newNode and adding data from strList;
  NodeInfo* newNode = (struct NodeInfo*)malloc(sizeof(struct NodeInfo));
  newNode->setIfDir(strList.at(0));
  newNode->setName(strList.at(1));
  newNode->setParent(strList.at(2));
  if(head == NULL && tail == NULL){
    head = newNode;
    tail = head;
  }else{
    tail->next = newNode;
    newNode->parent = tail;
    tail = newNode;
  }
};
