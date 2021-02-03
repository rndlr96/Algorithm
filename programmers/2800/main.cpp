#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

stack<pair<char,int>> col;
vector<pair<int,int>> pairs;
pair<int,int> arr[12];
bool visit[12];
set<string> answers;
string input;

void func(int num, int cnt, int k){
    if(cnt == k){
        string tmp = input;
        for(int i = 0 ; i < k ; i++){
            tmp[arr[i].first] = ' '; tmp[arr[i].second] = ' ';
        }
        string tmp2 = "";
        for(auto i : tmp){
            if(i != ' ') tmp2 += i;
        }
        answers.insert(tmp2);
        return;
    }
    for(int i = num ; i < pairs.size() ; i++){
        if(!visit[i]){
            visit[i] = true;
            arr[cnt] = pairs[i];
            func(i, cnt+1, k);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> input;
    for(int i = 0 ; i < input.size() ; i++){
        if(input[i] == '('){
            col.push({input[i],i});
        } else if(input[i] == ')'){
            int before = col.top().second;
            pairs.push_back({before,i});
            col.pop();
        }
    }
    for(int i = 1 ; i <= pairs.size() ; i++){
        fill(visit, visit+12, false);
        func(0, 0,i);
    }
    for(auto i : answers){
        cout << i << endl;
    }
    return 0;
}
