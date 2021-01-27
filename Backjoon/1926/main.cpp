#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int main() {
    int board[502][502];
    int visit[502][502];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m,n;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
        }
    }

    int mx = 0;
    int picture = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            queue<pair<int,int>> Q;
            if(visit[i][j] == 0 && board[i][j] == 1){
                visit[i][j] = 1;
                Q.push({i,j});
                picture++;
            }
            int area = 0;
            while(!Q.empty()){
                area++;
                pair<int,int> cur = Q.front(); Q.pop();
                for(int idx = 0 ; idx < 4 ; idx++){
                    int nx = cur.first + dx[idx];
                    int ny = cur.second + dy[idx];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(visit[nx][ny]  || board[nx][ny] != 0) continue;
                    visit[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            mx = max(mx, area);
        }
    }
    cout << picture << '\n' << mx;
    return 0;
}
