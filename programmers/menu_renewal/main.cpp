#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

char arr[28];
bool visit[28];
map<string,int>  lists[12];
int mxs[10];
int mx;

void func(int num, int cnt, int k, string order){
    if(cnt == k){

        if(lists[k].find(arr) == lists[k].end()){
            lists[k][arr] = 1;
        }
        else {
            lists[k][arr] += 1;
            mx = max(mx,lists[k][arr]);
        }
        return;
    }
    for(int i = num ; i < order.size() ; i++){
        if(!visit[i]){
            visit[i] = true;
            arr[cnt] = order[i];
            func(i, cnt+1, k, order);
            visit[i] = false;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for(int i = 0 ; i < orders.size() ; i++){
        vector<char> tmp(orders[i].begin(), orders[i].end());
        sort(tmp.begin(), tmp.end());
        string word = "";
        for(int j = 0 ; j < tmp.size() ; j++){
            word += tmp[j];
        }
        orders[i] = word;
    }
    vector<string> answer;

    for(auto i : course){
        mx = 0;
        for(auto j : orders){
            if(j.size() < i) continue;
            fill(visit, visit+28, false);
            func(0, 0,i,j);
        }
        mxs[i] = mx;
    }

    for(auto i : course) {
        if(mxs[i] < 2) continue;
        while(!lists[i].empty()) {
            if(lists[i].begin()->second == mxs[i]){
                answer.push_back(lists[i].begin()->first);
            }
            lists[i].erase(lists[i].begin());
        }
    }
    sort(answer.begin(), answer.end());
    for(auto i : answer){
        cout << i << endl;
    }
    return answer;
}

int main() {
    solution({"XYZ", "XWY", "WXA"}, {2,3,4});
    return 0;
}
