#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> primeList(int n);
bool isPrime(int x);

int main(int argc, char** argv){

// cout << "You have entered " << argc << " arguments:" << "\n";
//    for (int i = 0; i < argc; ++i)
//        cout << argv[i] << "\n";

	cout << "First breakpoint here!";

	if(argc!=2){
		cout<< "Please enter 2 arguments in the format: ./yourExec number";
	}

	int n = stoi(argv[1]);

	cout << "We need to find prime numbers till  " << n << "\n" << endl;

	vector<int> res = primeList(n);
	cout << "The prime numbers are:  " << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}

vector<int> primeList(int n){
    vector<int> primeNumbers;
    int i=0;
    while(i<n)
    {
        if(isPrime(i))
        {
            primeNumbers.push_back(i);
        }
				i++;
    }
    return primeNumbers;
}


bool isPrime(int x){
	if(x%2==0){
		return false;
	}

    for(int i = 3; i <= x/2; i++)
    {
        if(x%i == 0)
        {
            return false;
        }
    }
    return true;
}
