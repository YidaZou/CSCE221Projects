#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
   vector<vector<int>> cost;

   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

      //Create adjacency list of this form : adj[u] - {v,w} by iterating over flights Step 2
       vector<vector<pair<int,int>>> adj(n);

       //Your Code Here
       for(auto f : flights){
         adj[f.at(0)].push_back({f.at(1), f.at(2)});
       }

       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // Step 1. Done.

      // Push {cost to reach the node, node, remainingstops} for the source node. Refer to PDF. Algorithm (Step .3)

      //Your Code Here
      pq.push({0, src, k+1});

       while(!pq.empty()){

           //Fetch and pop from priority queue. From this we can get cost, node, remainingStops (Step 5)

            //Your code here
            int node = pq.top().at(1);
            int cost = pq.top().at(0);
            int stepsLeft = pq.top().at(2);
            pq.pop();


           // When do we return the cost. When node== ?. Refer to Step 4
           if(node == dst){
               return cost;
           }

           // Implement Step 6 of the algorithm here
           if(stepsLeft>0){
             for(int i=0; i<adj.at(node).size(); i++){
               int nextCost = adj.at(node).at(i).second;
               int nextNode = adj.at(node).at(i).first;
               pq.push({cost + nextCost, nextNode, stepsLeft-1});
             }
           }

       }
      return -1;
   }
};

int main(){
   Solution obj;
   vector<vector<int>> v = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
   int n = 4;
   int src = 0;
   int dest = 3;
   int kstops = 0;
   cout << (obj.findCheapestPrice(n, v, src, dest, kstops));
   return 0;
}
