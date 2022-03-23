#ifndef _MERGE_VECTOR_CPP
#define _MERGE_VECTOR_CPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using std::cout; using std::endl;
using std::string; using std::vector;

void printVector(vector<char *> vec) {
    for (auto &i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

void 
merge(vector<char *> *vec, vector<char *> v1, vector<char *> v2)
{
}

void 
mergeSort(vector<char *> *vec) 
{
	/* Recursion should be done here */
}

int
main(int argc, char**argv)
{
	vector<char *> list;
	for (int i = 0; i < argc; i++)
	{
		list.push_back(argv[i]);
	}
	list.erase(list.begin());
	mergeSort(&list);
	printVector(list);
	return 0;
}
#endif
