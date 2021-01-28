#include <iostream>
#include <queue>

using namespace std;

int main() {
    string board[1002];
    int visit1[1002][1002];
    int visit2[1002][1002];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int R,C;
    queue<pair<int,int>> F;
    queue<pair<int,int>> J;
    cin >> R >> C;
    for(int i = 0 ; i < R ; i++){
        cin >> board[i];
        fill(visit1[i], visit1[i]+C, -1);
        fill(visit2[i], visit2[i]+C, -1);
    }
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            if(board[i][j] == 'F'){
                F.push({i,j});
                visit1[i][j] = 0;
            }
            if(board[i][j] == 'J'){
                J.push({i,j});
                visit2[i][j] = 0;
            }
        }
    }
    while(!F.empty()){
        pair<int,int> cur = F.front(); F.pop();
        for(int idx = 0 ; idx < 4 ; idx++){
            int nx = cur.first + dx[idx];
            int ny = cur.second + dy[idx];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(visit1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            visit1[nx][ny] = visit1[cur.first][cur.second] + 1;
            F.push({nx,ny});
        }
    }
    while(!J.empty()){
        pair<int,int> cur = J.front(); J.pop();
        for(int idx = 0 ; idx < 4 ; idx++){
            int nx = cur.first + dx[idx];
            int ny = cur.second + dy[idx];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << visit2[cur.first][cur.second]+1;
                return 0;
            }
            if(visit2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(visit1[nx][ny] != -1 && visit1[nx][ny] <= visit2[cur.first][cur.second]+1) continue;
            visit2[nx][ny] = visit2[cur.first][cur.second] + 1;
            J.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
