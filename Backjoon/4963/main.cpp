#include <iostream>
#include <queue>

using namespace std;

int board[52][52];
bool visit[52][52];
int w, h;

int dx[8] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int main() {
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        for(int i = 0 ; i < h ; i++){
            fill(board[i], board[i]+52, 0);
            fill(visit[i], visit[i]+52, false);
        }
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                cin >> board[i][j];
            }
        }
        queue<pair<int,int>> Q;
        int answer = 0;
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                if(!visit[i][j] && board[i][j] == 1){
                    visit[i][j] = true;
                    Q.push({i,j});
                    answer++;
                }
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int idx = 0 ; idx < 8 ; idx++){
                        int nx = cur.first+dx[idx];
                        int ny = cur.second+dy[idx];
                        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                        if(visit[nx][ny] || board[nx][ny] != 1) continue;
                        visit[nx][ny] = true;
                        Q.push({nx,ny});
                    }
                }
            }
        }
        cout << answer << '\n';
    }
    return 0;
}
