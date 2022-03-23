#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int countWords(string list[], int n,int k)
{
map<string,int> m;
int count=0;
// YOUR CODE HERE
}

int main(){

	string words[11] = {"The", "first", "second", "was", "alright", "but", "the",  "second", "second", "was", "not"};
	int k = 2;
	int size = sizeof(words)/sizeof(words[0]);
	int result = countWords(words,size,k);
	cout << "Number of words appearing exactly " << k << " times =  " << result; 
	return 0;
}