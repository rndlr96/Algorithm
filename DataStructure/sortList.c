#include <stdio.h>

typedef struct node {
  int val;
  struct Node *next;
} Node;

typedef struct list {
  Node *head;
  Node *cur;
  Node *tail;
} List;


Node * init(Node *root){
  root = calloc(1, sizeof(Node));
  root->val = NULL;
  root->next = NULL;
  return root;
}

void insert (List *list, int val) {
  Node *node;
  node = init(node);
  node->val = val;

  if (list->head == NULL){ // 리스트가 비어있을 경우
    list->head = node;
    list->tail = node;
  }
  else {
    list->cur = list->head;
    Node *tmp1 = list->cur;
    Node *tmp2 = tmp1->next;
    // 조건 1 : 가장 작은 값인 경우
    if (node->val < tmp1->val) {
      node->next = tmp1;
      list->head = node;
    } else {
      while(1) {
        // 조건 2 : cur->next가 NULL일 경우
        if (tmp2 == NULL) {
          tmp1->next = node;
          list->tail = node;
          break;
        } // 조건 3 : 중간에 삽입될 경우
        else if (node->val < tmp2->val) {
          node->next = tmp1->next;
          tmp1->next = node;
          break;
        }
        else {
          tmp2 = tmp2->next;
          tmp1 = tmp1->next;
        }
      }
    }
  }
}

void print(List *list){
  Node *tmp;
  if (list->head == NULL){
    printf("List is empty\n");
  } else {
    for ( tmp = list->head ; tmp != list->tail ; ){
      printf("%d ", tmp->val);
      tmp = tmp->next;
    }
    printf("%d ", tmp->val);
    printf("\n");
  }
}

int main(void){
  List *list = calloc(1,sizeof(List));
  list->head = NULL;
  list->cur = NULL;
  list->tail = NULL;

  insert(list, 3);
  insert(list, 2);
  insert(list, 4);
  insert(list, 5);
  print(list);
}
