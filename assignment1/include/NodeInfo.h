#ifndef _NODEINFO_H
#define _NODEINFO_H

#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

class NodeInfo
{
    private:
        bool is_dir;
        string name;
        string p_name;

    public:
        NodeInfo *parent;
        NodeInfo *next;
        vector<NodeInfo> children;
        void setIfDir(string);
        void setName(string);
        void setParentName(string);
        void setParent(string);
        bool checkIfDir();
        string getNodeName();
        string getParentName();
        NodeInfo* getParent();
        vector<NodeInfo> getChildren();
};
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

void printList();
void append(vector<string>);
vector<string> tokenize_input_string(string);

#endif
