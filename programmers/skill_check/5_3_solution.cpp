#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> x, vector<int> y){
    return x[1] > y[1];
}

class Node {
public:

    int value;
    int index;
    Node* left;
    Node* right;

    Node(){
        value = 0; index = 0; left = nullptr; right = nullptr;
    }
    Node(int _value, int _index){
        value = _value;
        index = _index;
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

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for(int i = 0 ; i < nodeinfo.size() ; i++){
        nodeinfo[i].push_back(i+1);
    }
    sort(nodeinfo.begin(), nodeinfo.end(), comp);
    Node* root = new Node();
    for(vector<int> i : nodeinfo){
        Insert(root, i[0], i[2]);
    }

    return answer;
}

int main(void){
    vector<vector<string>> nodeinfo = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
    vector<string> a = solution(tmp);
    cout << a[0] << ' ' << a[1] << endl;
}
