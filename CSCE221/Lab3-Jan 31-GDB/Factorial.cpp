#include <iostream>
#include <string>
using namespace std;

int factorial(int n);

int main(int argc, char** argv){
	// cout << "You have entered " << argc << " arguments:" << "\n";
 //    for (int i = 0; i < argc; ++i)
 //        cout << argv[i] << "\n";

	cout << "First breakpoint here!";

	if(argc!=2){
		cout<< "Please enter 2 arguments in the format: ./yourExec number";
	}

	int number = stoi(argv[1]);
	cout << "Number whose factorial should be found:" << number << endl;
	
	int answer = factorial(number);
	cout << "The factorial of " << number << " is: " << answer << endl;

    return 0;
}

int factorial(int n){
	int fact = 1;
	for(int i=n;i>=1;i--){
		fact = fact * i;
	}
	return fact;
}