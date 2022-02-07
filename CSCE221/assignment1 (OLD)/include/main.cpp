#include "NodeInfo.cpp"
#include "print_list.cpp"

int main() {
  fstream file;
  file.open("test_cases/test_case_1");

  if (!file.is_open()) {
     cout << "not open" << endl;
     return 1;
  }
  string line;
  vector<string> inputs;
  while (getline(file, line)){
     inputs = tokenize_input_string(line);
     append(inputs);
  }

  printList();

  file.close();
  return 0;
}
