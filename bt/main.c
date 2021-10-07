#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int key;
  Node *left;
  Node *right;
}Node;

Node *createNode(int key){
  Node *node;
  node = (Node *)malloc(sizeof(Node)) ;
  if(!node){
    return NULL;
  }
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int main(){
  
  Node *root = createNode(44);
  root->left = createNode(2);
  root->left->left = createNode(4);
  root->right = createNode(3);
  root->right->left = createNode(5);

  return 0;
}
