#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool comp(vector<string> a, vector<string> b){
    return a[1] < b[1];
}

void DFS(string start, vector<vector<string>> tickets, bool *visit, vector<string> &answer, queue<string> q){
    if (q.size() == tickets.size()+1){
        while(!q.empty()){
            answer.push_back(q.front());
            q.pop();
        }
    }
    for (int i = 0 ; i < tickets.size() ; i++){
        if(start == tickets[i][0] && visit[i] == false){
            visit[i] = true;
            q.push(tickets[i][1]);
            DFS(tickets[i][1], tickets, visit, answer, q);
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end(), comp);
    bool visit[tickets.size()];
    queue<string> q;
    fill_n(visit, tickets.size(), false);
    q.push("ICN");
    DFS("ICN", tickets, visit, answer, q);

    return answer;
}

int main() {
    vector<vector<string>> tickets{{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
    solution(tickets);
    return 0;
}
