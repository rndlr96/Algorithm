#include <iostream>
#include <queue>

using namespace std;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[10][10];
int temp[10][10];
int n,m;
int mx = 0;

void BFS(){
    bool visit[10][10];
    queue<pair<int,int>> Q;
    for(int i = 0 ; i < n ; i++) {
        fill(visit[i], visit[i] + m, false);
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 2) {
                visit[i][j] = true;
                Q.push({i, j});
            }
            if (temp[i][j] == 1) {
                visit[i][j] = 1;
            }
        }
    }
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int idx = 0 ; idx < 4 ; idx++){
            int nx = cur.first + dx[idx];
            int ny = cur.second + dy[idx];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visit[nx][ny]) continue;
            visit[nx][ny] = true;
            Q.push({nx,ny});
        }
    }
    int empty = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(visit[i][j] == false) empty++;
        }
    }
    mx = max(mx, empty);
    return;
}

void Makewall(int cnt){
    if(cnt == 3){
        BFS();
        return;
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(temp[i][j] == 0){
                temp[i][j] = 1;
                Makewall(cnt+1);
                temp[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(board[i][j] == 0){
                for(int k = 0 ; k < n ; k++){
                    for(int t = 0 ; t < m ; t++){
                        temp[k][t] = board[k][t];
                    }
                }
                temp[i][j] = 1;
                Makewall(1);
                temp[i][j] = 0;
            }
        }
    }
    cout << mx;

    return 0;
}
