#include <iostream>
#include <queue>

using namespace std;

int main() {

    int board[101][102][102];
    bool visit[102][102][102];
    int dx[6] = {1, 0, -1, 0, 0, 0};
    int dy[6] = {0, 1, 0, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    int m,n,h;
    cin >> m >> n >> h;
    queue<vector<int>> Q;
    int mx = 0;
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < n ; j++){
            fill(visit[i][j], visit[i][j]+m, false);
            for(int k = 0 ; k < m ; k++){
                cin >> board[i][j][k];
                if(board[i][j][k] == 1){
                    visit[i][j][k] = true;
                    Q.push({i,j,k,0});
                }
                if(board[i][j][k] == -1){
                    visit[i][j][k] = true;
                }
            }
        }
    }
    while(!Q.empty()){
        vector<int> cur = Q.front(); Q.pop();
        int cnt = cur[3];
        mx = max(mx, cnt);
        for(int idx = 0 ; idx < 6 ; idx++){
            int nz = cur[0] + dz[idx];
            int nx = cur[1] + dx[idx];
            int ny = cur[2] + dy[idx];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
            if(visit[nz][nx][ny]) continue;
            visit[nz][nx][ny] = true;
            Q.push({nz,nx,ny, cnt+1});
        }
    }
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < m ; k++){
                if(visit[i][j][k] == false) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << mx;
    return 0;
}
