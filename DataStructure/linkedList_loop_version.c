#include <stdio.h>
#include <time.h>

typedef struct node {
  int val;
  struct Node *next;
} Node;

Node *insert(Node *, int);
Node *init(Node*);
void search(Node*, int);
void print(Node*);
void delete(Node*, int);

Node * init(Node *root){
  root = calloc(1, sizeof(Node));
  root->val = NULL;
  root->next = NULL;
  return root;
}

Node * insert(Node *root, int val){
  if (root->val == NULL){
    root->val = val;
    return root;
  } else {
    Node *tmp, *tmp2;
    tmp = root;
    while(tmp->next != NULL){
      tmp = tmp->next;
    }
    tmp2 = init(tmp2);
    tmp2->val = val;
    tmp->next = tmp2;
    return root;
  }
}

void search(Node *root, int val){
  if (root->val == NULL){
    printf("List is empty\n");
  } else {
    for ( ; root->next != NULL ; root = root->next) {
      if (root->val == val) {
        printf("search value : %d  search state : success\n", val);
        break;
      }
    }
    if (root->next == NULL) {
      printf("search value : %d  search state : fail\n", val);
    }
  }
}

void print(Node *root){
  if (root->val == NULL){
    printf("List is empty\n");
  } else {
    for ( ; root->next != NULL ; root = root->next){
      printf("%d ", root->val);
    }
    printf("\n");
  }
}

void delete(Node *root, int val){
  if (root->val == NULL) {
    printf("List is empty\n");
  } else if (root->next == NULL) {
    if (root->val == val) {
      free(root);
      printf("delete value : %d  delete state : success\n", val);
    } else {
      printf("delete value : %d  delete state : fail (%d is not contained in list)\n", val, val);
    }
  } else {
    Node *tmp = root;
    Node *tmp2 = tmp->next;
    while(tmp2->next != NULL){
      if (tmp2->val == val) {
        tmp->next = tmp2->next;
        free(tmp2);
        printf("delete value : %d  delete state : success\n", val);
        break;
      } else {
        tmp = tmp->next;
        tmp2 = tmp2->next;
      }
    }
    if(tmp2->next == NULL){
      printf("delete value : %d  delete state : fail (%d is not contained in list)\n", val, val);
    }
  }
}

int main(void){
  clock_t start, end;
  Node *root;

  srand((unsigned int)time(NULL));
  start = clock();

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

  end = clock();

  printf("%.3lf ms\n", (double)end-start);
}
