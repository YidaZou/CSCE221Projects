#include "NodeInfo.h"

void append(NodeInfo**, vector<string> strList){
  NodeInfo newNode = (struct NodeInfo*)malloc(sizeof(struct NodeInfo));
  newNode.setIfDir(strList.at(0));
  newNode.setName(strList.at(1));
  newNode.setParent(strList.at(2));
};
