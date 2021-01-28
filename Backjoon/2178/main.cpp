#include <iostream>
#include <queue>

using namespace std;

int main() {
    string board[101];
    int visit[101][101];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m,n;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) fill(visit[i], visit[i]+m, -1);
    for(int i = 0 ; i < n ; i++){
        cin >> board[i];
    }
    queue<pair<int, int>> Q;
    visit[0][0] = 0;
    Q.push({0,0});
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int idx = 0 ; idx < 4 ; idx++){
            int nx = cur.first + dx[idx];
            int ny = cur.second + dy[idx];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visit[nx][ny] >= 0 || board[nx][ny] != '1') continue;
            visit[nx][ny] = visit[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    cout << visit[n-1][m-1] + 1 << endl;
    return 0;
}
