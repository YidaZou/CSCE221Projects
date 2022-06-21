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
merge(vector<char *> *vec, int l, int m, int r)
{

  //size of left and right vectors
  int lSize = m-l+1;
  int rSize= r-m;

  vector<char*> L(lSize);
  vector<char*> R(rSize);

  //fill left and right vectors;
  for(int i=0; i<lSize; i++){
    L.at(i) = vec->at(l+i);
  }
  for(int j=0; j<rSize; j++){
    R.at(j) = vec->at(m+1+j);
  }
  //merge L and R vectors into vec
  int lIndex=0, rIndex=0, vIndex=l;
  while(lIndex<lSize && rIndex<rSize) {
    if(strcmp(L.at(lIndex), R.at(rIndex)) <= 0){  //Check if the left string is lower alphabetically than the right string
      vec->at(vIndex) = L.at(lIndex);
      lIndex++;
    }else{
      vec->at(vIndex) = R.at(rIndex);
      rIndex++;
    }
    vIndex++;
  }
  while(lIndex<lSize){ //L vec extra element
    vec->at(vIndex) = L.at(lIndex);
    lIndex++;
    vIndex++;
  }
  while(rIndex<rSize){ //R vec extra element
    vec->at(vIndex) = R.at(rIndex);
    rIndex++;
    vIndex++;
  }

}

void
mergeSort(vector<char *> *vec, int l, int r)
{
	if(r<=l){
    return; //endless loop otherwise
  }
  int mid = l + (r-l)/2;  //middle index
  mergeSort(vec, l, mid);
  mergeSort(vec, mid+1, r);
  merge(vec, l, mid, r);
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
	mergeSort(&list, 0, list.size()-1);
	printVector(list);
	return 0;
}
#endif
