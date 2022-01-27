#include <iostream>

//cube_list struct
struct cube_list {
  int num;
  cube_list *prev;
  cube_list *next;
};

//CubeList class
class CubeList {
	private:
    int num;
    CubeList *next;
		CubeList *prev;
};

using namespace std;
int main () {
   //a
   struct cube_list *head, *tail;

}
