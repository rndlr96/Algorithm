//
// Created by 정구익 on 2020/12/23.
//
using namespace std;

#include "Tree.h"
#include "iostream"
#include "queue"
#include "stack"

template<typename T>
class Node {

public:
    T value;
    Node* left;
    Node* right;

    Node(){
        value = 0;
        left = nullptr;
        right = nullptr;
    }
    Node(T _value){
        value = _value;
        left = nullptr;
        right = nullptr;
    }
    Node(T _value, Node* _left, Node* _right){
        value = _value;
        left = _left;
        right = _right;
    }
};

template<typename T>
Node<T>* Search(Node<T>* root, T _value){
    while(root == nullptr){
        if (root->value == _value){
            return root;
        }
        else if (root->value < _value){
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return nullptr;
}

template<typename T>
void Insert(Node<T>* root, T _value){
    if (Search(root, _value) == nullptr){
        if (root->value < _value){
            if (root->right == nullptr){
                root->right = new Node<T>(_value);
            } else{
                Insert(root->right, _value);
            }
        } else{
            if (root->left == nullptr){
                root->left = new Node<T>(_value);
            } else{
                Insert(root->left, _value);
            }
        }
    }
}

template<typename T>
void Preorder(Node<T>* root){
    if (root != nullptr){
        cout << root->value << ' ';
        Preorder(root->left);
        Preorder(root->right);
    }
}

template<typename T>
void Inorder(Node<T>* root){
    if (root != nullptr){
        Inorder(root->left);
        cout << root->value << ' ';
        Inorder(root->right);
    }
}
template<typename T>
void Postorder(Node<T>* root){
    if (root != nullptr){
        Postorder(root->left);
        Postorder(root->right);
        cout <<root->value << ' ';
    }
}

template<typename T>
void BFS(Node<T>* root){

    queue< Node<T>* > q;
    q.push(root);

    while(!q.empty()){
        root = q.front();
        q.pop();
        cout << root->value << ' ';
        if (root->right != nullptr){
            q.push(root->right);
        }
        if (root-> left != nullptr){
            q.push(root->left);
        }
    }
}

template<typename T>
void DFS(Node<T>* root){
    stack< Node<T>* > s;
    s.push(root);

    while(!s.empty()){
        root = s.top();
        s.pop();
        cout << root->value << ' ';
        if (root->right != nullptr){
            s.push(root->right);
        }
        if (root-> left != nullptr){
            s.push(root->left);
        }
    }
}


int main(){
    Node<int>* root = new Node<int>(5);
    Insert(root, 3);
    Insert(root, 7);
    Insert(root, 10);
    Insert(root, 20);
    Insert(root, 6);
/*
    Preorder(root);
    cout << '\n';
    Inorder(root);
    cout << '\n';
    Postorder(root);
*/
    BFS(root);
    cout << '\n';
    DFS(root);



}