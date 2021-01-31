#include <iostream>
#include <queue>

using namespace std;

int arr[1002][1002];
bool visit[1002];
int n,m,v;

void DFS(int start, int cnt){
    if(cnt == n){
        return;
    }
    cout << start << " ";
    for(int i = 1 ; i <= n ; i++){
        if(!visit[i] && arr[start][i] == 1){
            visit[i] = true;
            DFS(i, cnt);
        }
    }
}

void BFS(int start){
    queue<int> Q;

    cout << start << " ";

    for(int i = 1 ; i <= n ; i++){
        if(!visit[i] && arr[start][i] == 1){
            visit[i] = true;
            cout << i << " ";
            Q.push({i});
        }
    }
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int i = 1 ; i <= n ; i++){
            if(visit[i] || arr[cur][i] != 1) continue;
            visit[i] = true;
            cout << i << " ";
            Q.push({i});
        }
    }
}


int main() {
    cin >> n >> m >> v;
    for(int i = 0 ; i < m ; i++){
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    fill(visit, visit+n+1, false);
    visit[v] = true;
    DFS(v, 0);

    cout << '\n';

    fill(visit, visit+n+1, false);
    visit[v] = true;
    BFS(v);

    return 0;
}
