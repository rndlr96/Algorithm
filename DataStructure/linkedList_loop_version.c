#include <stdio.h>

typedef struct node {
  int val;
  struct Node *next;
} Node;

Node *insert(Node *, int);
Node *init(Node*);
void search(Node*, int);
void print(Node*);
void delete(Node*, int);

Node * insert(Node *root, int val){
  if (root->val == NULL){
    
  } else {
    for ( ; root->next == NULL ; root = root->next){

    }
  }
}

int main(void){
  Node *root;
}
