#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int getParent(vector<int>& parent, int x){
    if(parent[x] == x)      return x;
    return parent[x] = getParent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int a, int b){
    a = getParent(parent,a);
    b = getParent(parent,b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

bool find_parent(vector<int>& parent, int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b) return false;
    return true;
}

bool comp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> cycle_table;
    for(int i = 0 ; i < costs.size() ; i++){
        cycle_table.push_back(i);
    }
    sort(costs.begin(), costs.end(), comp);
    for(auto i : costs){
        if(find_parent(cycle_table, i[0], i[1])){
            union_parent(cycle_table, i[0], i[1]);
            answer += i[2];
        }
    }
    return answer;
}

int main() {
    solution(4, {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}});
    return 0;
}
