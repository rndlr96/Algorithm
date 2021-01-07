#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <iostream>

using namespace std;

bool comp(vector<int> x, vector<int> y){
    return x[1] > y[1];
}

class Node{
    public:
    int value;
    int index;
    Node* left;
    Node* right;

    Node(){
        value = 0;
        index = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int _value, int _index){
        value = _value;
        index = _index;
        left = nullptr;
        right = nullptr;
    }
};

void Insert(Node* root, int _value, int _index){
    if (root->value == 0){
        root->value = _value;
        root->index = _index;
    } else{
        if (root->value < _value){
            if (root->right == nullptr){
                root->right = new Node(_value, _index);
            } else{
                Insert(root->right, _value, _index);
            }
        } else{
            if (root->left == nullptr){
                root->left = new Node(_value, _index);
            } else {
                Insert(root->left, _value, _index);
            }
        }
    }
}

void Preorder(Node* root, vector<int> &pre){
  if(!(root==nullptr)){
    pre.push_back(root->index);
    Preorder(root->left, pre);
    Preorder(root->right, pre);
  }
}

void Postorder(Node* root, vector<int> &post){
  if(!(root==nullptr)){
    Postorder(root->left, post);
    Postorder(root->right, post);
    post.push_back(root->index);
  }
}

vector< vector<int> > solution(vector< vector<int> > nodeinfo) {

  vector<vector<int>> answer;
  for(int i = 0 ; i < nodeinfo.size() ; i++){
      nodeinfo[i].push_back(i+1);
  }
  sort(nodeinfo.begin(), nodeinfo.end(), comp);
  Node* root = new Node();
  for(vector<int> i : nodeinfo){
      Insert(root, i[0], i[2]);
  }

  vector<int> pre, post;
  Preorder(root, pre);
  Postorder(root, post);

  answer.push_back(pre);
  answer.push_back(post);

  return answer;
}

int main(){
  vector<vector<int> > nodeinfo{{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};
  solution(nodeinfo);

}
