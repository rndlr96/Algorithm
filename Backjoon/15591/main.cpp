#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> board[5002];
int n,q,k,v;

void BFS(int k, int v){
    int answer = 0;
    bool visit[5002];
    fill(visit, visit+5002, false);
    queue<int> q;
    q.push(v);
    visit[v] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 0 ; i < board[cur].size() ; i++){
            int next = board[cur][i].first;
            if(!visit[next] && board[cur][i].second >= k){
                visit[next] = true;
                q.push(next);
                answer++;
            }
        }
    }
    cout << answer << '\n';
    return;
}

int main() {
    cin >> n >> q;
    for(int i = 0 ; i < n-1 ; i++){
        int x,y,r;
        cin >> x >> y >> r;
        board[x].push_back({y,r});
        board[y].push_back({x,r});
    }
    for(int i = 0 ; i < q ; i++){
        cin >> k >> v;
        BFS(k,v);
    }
    return 0;
}
