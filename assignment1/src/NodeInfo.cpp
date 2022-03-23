#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
//#include <bits/stdc++.h>
#include <NodeInfo.h>
#include "PrintList.cpp"

#define DEBUG 0

using namespace std;
vector<string>
tokenize_input_string(string line)
{
    char space_char = ' ';
    vector<string> words{};

    stringstream sstream(line);
    string word;
    while (std::getline(sstream, word, space_char))
    {
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        words.push_back(word);
        if (DEBUG) cout << "Word:" << word << endl;
    }
    if (DEBUG) cout << " " << endl;
    return words;
}

/*
 * appends a new node at the end
 */
void
append(NodeInfo** head_ref, vector<string> new_data)
{
  //making newNode and adding data from strList;
  NodeInfo* newNode = (NodeInfo*)malloc(sizeof(NodeInfo));
  newNode->setIfDir(new_data.at(0));
  newNode->setName(new_data.at(1));
  //newNode->setParent(strList.at(2));
  if(head == NULL && tail == NULL){ //if list is empty
    head = newNode;
    tail = head;
  }else{  //addes newNode to tail of list
    tail->next = newNode;
    newNode->parent = tail;
    tail = newNode;
    tail->next = NULL;
  }
}

#define MAXLNSZ 256

int main(int argc, char **argv)
{
    string line;
    char *filename = (char *) malloc(MAXLNSZ * sizeof(char));
    NodeInfo *tree_node = NULL;
    vector<string> lines{};
    vector<string> words;
    strcpy(filename, argv[1]);
    string files(filename);

    ifstream input_file(files);
    if (!input_file.is_open())
    {
        cerr << "Could not open the file - '"
             << files << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line))
    {
        lines.push_back(line);
        words = tokenize_input_string(line);
        append(&tree_node, words);
    }
    printList(tree_node);
    input_file.close();
    delete tree_node;
    free(filename);
    filename = NULL;
    if (DEBUG) cout << "Check Program Exiting " << endl;
    return EXIT_SUCCESS;
}
