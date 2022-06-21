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
#include <queue>
#include <cstring>
//#include <bits/stdc++.h>

#define PRINTLIST 0

using namespace std;

class NodeInfo
{
    private:
        bool is_dir;
        string name;
        string p_name;

    public:
        NodeInfo *parent; // This can be public or private
        NodeInfo *next;
        vector<NodeInfo *> children; // This can be public or private
        void setIfDir(string);
        void setName(string);
        void setParentName(string);
        //void setParent(string); // Will need to use this if parent is private
        void setNodeType(bool);
        bool checkIfDir();
        string getNodeName();
        string getParentName();
        NodeInfo *nextDir; //for list of directories
        //NodeInfo* getParent(); // Will need to use this if parent is private
		//void addChild(NodeInfo *); // Will need to use this if children is private
        //vector<NodeInfo *> getChildren(); // Will need to use this if children is private
};
NodeInfo *head, *tail;  //head and tail of tree
/* I needed these two lists for my implementation */
//extern NodeInfo *dir_list;
//extern NodeInfo *file_list;

inline string
NodeInfo::getParentName()
{
    // should return current object's p_name
    return p_name;
}

inline void
NodeInfo::setNodeType(bool nType)
{
	// might have been set in assignment 1; depends on implementation.
  is_dir = nType;

}

inline void
NodeInfo::setParentName(string par_name)
{
    // should set current object's p_name to par_name
    p_name = par_name;
}
/*
inline void
NodeInfo::setParent(string par_name)
{
    // Will need to use this if parent is private
}
*/

inline void
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

inline void
NodeInfo::setName(string name_str)
{
	/* Set name to name_str */
  name = name_str;
}

inline bool
NodeInfo::checkIfDir()
{
	/* Return the value of is_dir */
  return is_dir;
}

inline string
NodeInfo::getNodeName()
{
	/* Return the value of name */
  return name;
}

/*
inline NodeInfo*
NodeInfo::getParent()
{
    // Will need to use this if parent is private
}

inline vector<NodeInfo *>
NodeInfo::getChildren()
{
    // Will need to use this if parent is private
}
*/
void printList(NodeInfo *);
void append(NodeInfo**, vector<string>);
vector<string> tokenize_input_string(string);

#endif
