#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int connectRopes(vector<int> v) {

    // The documentation attached is for MaxHeap.
    // What would we require in our case? MinHeap or MaxHeap?
    // If we want to implement minheap, a simple trick would be to use the corresponding negative values of the vector elements?
    // Think about why that would work?
    for (int i=0; i<v.size(); i++){
      v[i] = -v[i];
    }


    int mincost=0;


    // Use make_heap. Refer to the documentation and the example present in it.
    make_heap(v.begin(),v.end());


    // Loop through the vector elements. In each iteration, we will have to pick the first and the second lowest, connect them
    // What would be the exit condition for this loop? How many elements should be present in the heap at the end?
    while (v.size()>1)  {



      //get first minimum value in heap
      int x = v.front();
      pop_heap(v.begin(),v.end()); v.pop_back();

      //get second minimum value in heap
      int y = v.front();
      pop_heap(v.begin(),v.end()); v.pop_back();


      //add the values and put in again in heap
      mincost+= x + y;
      v.push_back(x+y); push_heap(v.begin(),v.end());
    }

    //return minimum cost
    return -mincost;


}
int main()
{
  vector<int> ropes={5};
  cout << connectRopes(ropes);
  return 0;
}
