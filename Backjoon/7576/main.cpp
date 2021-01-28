#include <iostream>
#include <queue>

using namespace std;

int main() {
    int board[1002][1002];
    int visit[1002][1002];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n,m;
    cin >> m >> n;
    queue<pair<int,int>> Q;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
            if (board[i][j] == 1){
                Q.push({i,j});
            }
            if (board[i][j] == 0){
                visit[i][j] = -1;
            }
        }
    }
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int idx = 0 ; idx < 4 ; idx++){
            int nx = cur.first + dx[idx];
            int ny = cur.second + dy[idx];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visit[nx][ny] >= 0) continue;
            visit[nx][ny] = visit[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(visit[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans,visit[i][j]);
        }
    }
    cout << ans;
    return 0;
}
