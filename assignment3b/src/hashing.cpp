#include <iostream>

using namespace std;
class NodeInfo  //nodes in hash table
{
  public:
    int num;
    int key;
};

//printing hash table
void printHash(int arr[]){
  for(int i=0; i<8; i++){
    cout << arr[i] << " ";
  }
  cout<<endl;
}

//sum of digits
//used for 1.3
int sumOfDigits(int n){
  int sum = 0;
  while(n!=0){
    sum += n%10;
    n = n/10;
  }
  return sum;
}

int main(int argc, char const *argv[]) {
  //converting input to int
  int keys[argc-1];
  for (int i=1; i<argc; i++){
		keys[i-1] = atoi(argv[i]);
	}
  //create Hash table of size 8
  int hash[8];
  int index;  //result of hash function
//1.1
  //set values to -1
  for(int i=0; i<8; i++){
    hash[i] = -1;
  }
  for(int i=0; i<argc-1; i++){  //for traversing keys
    for(int j=0; j<8; j++){
      index = (keys[i] + j)%8; //hash function
      if(hash[index] == -1){  //if index is empty
        hash[index] = keys[i];
        break;
      }
    }
  }
  printHash(hash);

//1.2
  //set values to -1
  for(int i=0; i<8; i++){
    hash[i] = -1;
  }
  for(int i=0; i<argc-1; i++){  //for traversing keys
    for(int j=0; j<8; j++){
      index = (keys[i] + j + 2*(j*j))%8; //hash function
      if(hash[index] == -1){  //if index is empty
        hash[index] = keys[i];
        break;
      }
    }
  }
  printHash(hash);

//1.3
  int sum = 0;  //used for hash function
  //set values to -1
  for(int i=0; i<8; i++){
    hash[i] = -1;
  }
  for(int i=0; i<argc-1; i++){  //for traversing keys
    sum = sumOfDigits(keys[i]); //sum of digits in key
    for(int j=0; j<8; j++){
      index = (keys[i] + j * sum)%8; //hash function
      if(hash[index] == -1){  //if index is empty
        hash[index] = keys[i];
        break;
      }
    }
  }
  printHash(hash);
  return 0;
}
