#include "NodeInfo.cpp"

int main() {
  fstream file;
  file.open(test_case_1);
  ifstream input_file(filename);

  if (!file.is_open()) {
     cerr << "Could not open the file - '"
          << filename << "'" << endl;
     return EXIT_FAILURE;
  }

  while (getline(input_file, line)){
     lines.push_back(line);
  }

  for (const auto &i : lines)
     cout << i << endl;

  input_file.close();
  return EXIT_SUCCESS;
  return 0;
}
