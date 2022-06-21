#include <iostream>
using namespace std;

//Resource used:
//https://www.cs.auckland.ac.nz/software/AlgAnim/red_black.html
typedef enum {red, black} Color;
struct Node
{
    Node* left;
    Node* right;
    Node* parent;
    Color color;
    int num;

    Node(int num){
      this->num = num;
      left = right = parent = NULL;
      this->color = red;
    }

};

class RBTree{
private:
  Node* root = NULL;

public:
  RBTree(){
    root = NULL;
  }

  void leftRotate(Node* &root, Node* &x){
    Node* y = x->right;
    x->right = y->left; //x's right = y's left
    if(y->right != NULL){
      y->right->parent = x;  //y's right node's parent = x
    }
    y->parent = x->parent;  // y's parent points to x's parent

    if(x->parent == NULL){  //check if at root
      root = y;
    }else if(x == x->parent->left){
      //x is left of its parent
      x->parent->left = y;
    }else{
      //x is right of its parent
      x->parent->right = y;
    }
    //y's left = x;
    y->left = x;
    x->parent = y;

  }

  void rightRotate(Node* &root, Node* &x){
    Node* y = x->left;
    x->left = y->right; //x's left = y's right
    if(y->left != NULL){
      y->left->parent = x;  //y's left node's parent = x
    }
    y->parent = x->parent;  // y's parent points to x's parent

    if(x->parent == NULL){  //check if at root
      root = y;
    }else if(x == x->parent->left){
      //x is left of its parent
      x->parent->left = y;
    }else{
      //x is right of its parent
      x->parent->right = y;
    }
    //y's right = x;
    y->right = x;
    x->parent = y;

  }

  void RBFix(Node* &root, Node* &x){  //corrects RB tree with new node
    Node* y;  //used for rotating nodes
    Node* p;  //parent
    Node* gp; //grandparent

    while((x != root) && (x->color != black) && (x->parent->color == red)){
      p = x->parent;
      gp = x->parent->parent;
      //x is red with a red parent;
      if(p == gp->left){ //x's parent is left child
        y = gp->right; //y = x's parent's sibling
        if(y != NULL && y->color == red){ //y is also red
          p->color = black; //parent = black
          y->color = black; //y = black
          gp->color = red; //x's grandparent = red
          x = gp;  //x = grandparent
        }else{  //y is black
          if(x == p->right){ //x is right child
            leftRotate(root,p);
            x = p;
            p = x->parent;
          }
          //x and its parent are still both red
          //x is left child
          rightRotate(root,gp);
          swap(p->color, gp->color);
          x = p;
        }
      }else{  //x's parent is right child
        //basically same as above but with right and left switched
        y = gp->left; //y = x's parent's sibling
        if(y != NULL && y->color == red){ //y is also red
          p->color = black; //parent = black
          y->color = black; //y = black
          gp->color = red; //x's grandparent = red
          x = gp;  //x = grandparent
        }else{  //y is black
          if(x == p->left){ //x is left child
            rightRotate(root,p);
            x = p;
            p = x->parent;
          }
          //x and its parent are still both red
          //x is right child
          leftRotate(root,gp);
          swap(p->color, gp->color);
          x = p;
        }
      }
    }
    root->color = black;  //make sure root is always black;
  }

  Node* insertBST(Node* &root, Node* &newNode){
    //empty tree
    if(root == NULL){
      return newNode;
    }

    if(newNode->num < root->num){ //less than
      root->left = insertBST(root->left, newNode);
      root->left->parent = root;
    }else if(newNode->num > root->num){ //greater than
      root->right = insertBST(root->right, newNode);
      root->right->parent = root;
    }

    return root;
  }

  void insertRBT(int &num){ //normal BST insert
    //make new node with num and red color
    Node* newNode = new Node(num);

    root = insertBST(root, newNode);

    RBFix(root, newNode);
  }

  void printNodes(Node* node){ //preorder traversal of tree
    if(node == NULL){
      return; //reached NULL leaf
    }
    cout << node->num << " ";
    printNodes(node->left);  //print left subtree
    printNodes(node->right); //print right subtree
  }

  void printTree(){ //preorder traversal of tree
    printNodes(root);
  }
};

int main(int argc, char const *argv[]) {
  //get inputs
  int input[argc-1];
  for (int i=1; i<argc; i++){
		input[i-1] = atoi(argv[i]);
	}

  //create tree
  RBTree rbt;
  for(int i=0; i<argc-1; i++){
    rbt.insertRBT(input[i]);
  }

  //print tree
  rbt.printTree();

  return 0;
}
