#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size() == 0){
          return res;
        }
        //YOUR CODE HERE : Refer to the Hint given in the PDF
        unordered_map<string,int> seq;
        int a = 0;
        for(int i = 0; i <= s.size()-10; i++){
          string sub = s.substr(i,10);
          seq[sub]++;
        }

        for(auto i: seq){
          if(i.second>1){
            res.push_back(i.first);
            a++;
          }
        }
        return res;
    }

int main()
{
    string s = "";
    vector<string> output = findRepeatedDnaSequences(s);

    //YOUR CODE HERE : Print the output vector
    if(output.empty()){
      cout << "NO REPEATED SEQUENCE OF LENGTH 10" << endl;
    }else{
      for(int i=0; i<output.size(); i++){
        cout<< output.at(i) << " ";
      }
    }
    return 0;
}
