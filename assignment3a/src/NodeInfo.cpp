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
/*
 * In my approach, I split the linked list into a directory list and a file list.
 * If you use a different approach, you can remove this function.
void
split_into_lists(NodeInfo *tree_node)
{
}
*/

/* Here I create sub-trees with directory as the parent, and files as the children.
 * If you use a different approach, you can remove this function.
void
create_subtrees()
{
	// Here, I traverse the directory and file lists, and add the files to the directories
}
 */

void
printTree(NodeInfo *dir_node)
{
	// I do BF Traversal here using STL queue.
	// get the first element from the queue, and push all the children into the queue.
	// print the popped element for printing in BF traversal
	// https://en.cppreference.com/w/cpp/container/queue
	queue<NodeInfo *> q;

        //cout << u->getNodeName() << " "; // Prints the popped element (the one in the front)
	//cout << endl;
}

void
nullify_seq()
{
	// Set the next pointer that we used in order to create the linked list in assignment 1 to NULL.
	// No matter what strategy to use, at the end of 3a, the only pointers that need to have an
	// address associated with them are parent and children nodes.
}

void
create_tree()
{
	/*
	 * I create my tree using the directory list. I create parent-children relationships
	 * between directories here. Here, I need the next pointer to traverse the list.
	 */
	nullify_seq(); // After the use of the next pointer is served, I set all next pointers to NULL.
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
    //cout<< "test" << endl;
    printList();
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
