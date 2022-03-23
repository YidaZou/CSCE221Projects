#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


//Program to find the number of good pairs
//Good pairs are those in which nums[i] == nums[j] and i<j

int numGoodPairs(vector<int>& nums)
{

    //Initializing a Hash Table
    unordered_map<int,int> pairMap;

    //Iterate through the vector, count the occurences of a number and store it in value.

    //YOUR CODE HERE
    for(int i=0; i<nums.size(); i++){
      pairMap[nums[i]]++;
    }

    //Iterate through the values in the Hash Table or pairMap.
    // Apply the formula mentioned in the document to find the number of good pairs.
    int pairs = 0;
    for(auto j: pairMap){
      int n = j.second;
      pairs += n*(n-1)/2;
    }
    //YOUR CODE HERE


    //return the number of good pairs
    return pairs;
}

int main(){
    int output;
    vector<int> nums = {1,2,3};
    output = numGoodPairs(nums);
    cout << "Result:" << output;
}
