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

void printList(NodeInfo *);
void append(NodeInfo**, vector<string>);
vector<string> tokenize_input_string(string);

#endif
