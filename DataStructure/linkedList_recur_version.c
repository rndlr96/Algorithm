#include <stdio.h>

// typedef == 닉네임 설정 || 없다면 대괄호 옆은 변수 선
typedef struct node {
  int val;
  struct Node *next;
} Node ;

Node *insert(Node*, int);
Node *init(Node*);
void search(Node*, int);
void print(Node*);
void delete(Node*, int);

Node * init(Node *root) {
  root = calloc(1, sizeof(Node));
  root->val = NULL;
  root->next = NULL;
  return root;
}

Node * insert(Node *root, int val){
  if (root->val == NULL) {
    root->val = val;
    return root;
  } else if (root->next == NULL){
    Node *tmp;
    tmp = init(tmp);
    root->next = tmp;
    root->next = insert(root->next, val);
    return root;
  } else {
    root->next = insert(root->next, val);
  }
  return root;
}

void search(Node *root, int val){
  if (root->val == NULL) {
    printf("List is empty\n");
  } else if (root->next == NULL){
    if (root->val == val) {
      printf("search value : %d  search state : success\n", val);
    } else {
      printf("search value : %d  search state : fail\n", val);
    }
  } else {
    if (root->val == val) {
      printf("search value : %d  search state : success\n", val);
    } else {
      search(root->next, val);
    }
  }
}

void print(Node *root){
  if (root->val == NULL){
    printf("List is empty\n");
  } else if (root->next == NULL){
    printf("%d \n", root->val);
  } else {
    printf("%d -> ", root->val);
    print(root->next);
  }
}

void delete(Node * root, int val){
  if (root->val == NULL) {
    printf("List is empty\n");
  } else if (root->next == NULL){
    if (root->val == val) {
      free(root);
      printf("delete value : %d  delete state : success\n", val);
    } else {
      printf("delete value : %d  delete state : fail (%d is not contained in list)\n", val, val);
    }
  } else {
    Node *tmp;
    tmp = root->next;
    if (tmp->val == val) {
      root->next = tmp->next;
      free(tmp);
      printf("delete value : %d  delete state : success\n", val);
    } else {
      delete(root->next, val);
    }
  }
}

void swap(Node * root, int val1, int val2){
  
}

int main() {
  Node *root;

  root = init(root);

  root = insert(root, 3);
  root = insert(root, 5);
  root = insert(root, 7);
  root = insert(root, 9);

  printf("print list : ");
  print(root);

  search(root, 7);
  search(root, 8);

  delete(root, 8);
  delete(root, 7);
  search(root, 7);
}
