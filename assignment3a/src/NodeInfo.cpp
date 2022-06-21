#ifndef _NODEINFO_CPP
#define _NODEINFO_CPP

#include <NodeInfo.h>
#include "PrintList.cpp"

using namespace std;

/* I needed these two lists for my implementation */

// NodeInfo *dir_list = NULL;
// NodeInfo *file_list = NULL;

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
    }
    return words;
}

/*
 * appends a new node at the end
 */
void
append(vector<string> new_data)
{
  //making newNode and adding data from new_data;
  NodeInfo* newNode = new NodeInfo;	//create a new node
  newNode->setIfDir(new_data.at(0));
  newNode->setName(new_data.at(1));
  newNode->setParentName(new_data.at(2));
  if((head != NULL) && (tail != NULL)){
    //append to tail
    tail->next = newNode;
    tail = newNode;
    tail->next = NULL;
  }else{  //if list is empty
    head = newNode;
    head->next = NULL;
    tail = head;
  }
}

void makeTree() {
  NodeInfo* ptr = head; //ptr to find parent
  NodeInfo* node = head->next;
  while(node!=NULL){
    while(ptr != NULL){ //looping through list to find parents
      if(ptr->getNodeName() == node->getParentName()){
        node->parent = ptr;
        //add node to parent’s vector of children
        ptr->children.push_back(node);
      }
      ptr = ptr->next;
    }
    node = node->next;
    ptr = head; //reset ptr;
  }
}
#define MAXLNSZ 256

void
printTree(NodeInfo* nodeRef)
{
  queue<NodeInfo *> q;  //queue for BF traversal
  q.push(nodeRef); // push nodeRef (head of tree) into queue
  while(!q.empty()){
    int n = q.size();
    while(n>0){
      //Pop node and print it;
      NodeInfo* node = q.front();
      q.pop();
      cout << node->getNodeName() << " ";
      //Push the children of the node that was popped and printed
      for(unsigned int i=0; i<node->children.size(); i++){
        q.push(node->children[i]);
      }
      n--;
    }
  }
}

int
main(int argc, char **argv)
{
    string line;
    char *filename = (char *) malloc(MAXLNSZ * sizeof(char));
	if (argc != 2)
	{
		cerr << "Please input a file to read from" << endl;
		return EXIT_FAILURE;
	}
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
        append(words);
    }
    makeTree();
    printTree(head);
	//split_into_lists(tree_node); // Used in my way of creating the tree
	//create_subtrees(); // Used in my way of creating the tree
  /*
#if PRINTLIST
	printf("Printing Directories\n");
    printList(dir_list);
	printf("Printing Files\n");
    printList(file_list);
#endif
	create_tree();
  */
	//printTree(head/*dir_list*/); // Breadth First Traversal code should go here.
							 // dir_list has the start node of the tree for me.
    input_file.close();
    //delete head;
    free(filename);
    filename = NULL;
    return EXIT_SUCCESS;
}

#endif
