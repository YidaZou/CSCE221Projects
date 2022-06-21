#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:

vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans = nums1; // ans is the index mapping array that you should return(Refer to PDF for definition)
    
    //Declare a map<x,y> where x and y are data types based on your solution. 
    map<int,int> index;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans.size(); j++){
            if(nums1[i] == nums2[j]){
                index.insert({i,j});
            }
        }
    }
    for(auto m: index){
        ans[m.first] = m.second;
    }

    return ans;
}
};

int main(){
    vector<int> nums1 = {12,28,46,32,50};
    vector<int> nums2 = {12,28,46,32,50};
    Solution obj;
    //Call the function anagramMappings and print out the output vector(index mapping array)
    vector<int> ans = obj.anagramMappings(nums1, nums2);
    for(auto out : ans){
        cout << out << " ";
    }

    return 0;
}