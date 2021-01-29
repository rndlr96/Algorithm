#include <iostream>
#include <queue>

using namespace std;


int board[102][102];
int copy_board[102][102];
int visit[102][102];
queue<pair<int,int>> melt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

void board_copy(void){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            copy_board[i][j] = board[i][j];
        }
    }
}

void Air_check(){
    queue<pair<int,int>> Q;
    Q.push({0,0});
    visit[0][0] = 1;
    board[0][0] = -1;
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int idx = 0 ; idx < 4 ; idx++){
            int nx = cur.first + dx[idx];
            int ny = cur.second + dy[idx];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                if(board[nx][ny] == 0 && visit[nx][ny] == 0){
                    board[nx][ny] = -1;
                    visit[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
        }
    }
}

void init_melt(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(board[i][j] == -1){
                for(int idx = 0 ; idx < 4 ; idx++){
                    int nx = i+dx[idx];
                    int ny = j+dy[idx];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                        if(board[nx][ny] == 1){
                            melt.push({i,j});
                            break;
                        }
                    }
                }
            }
        }
    }
}

void Melting_Cheese()
{
    queue<pair<int, int>> Q = melt;
    while (melt.empty() == 0) melt.pop();
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m)
            {
                if (board[nx][ny] == 1)
                {
                    board[nx][ny] = 0;
                    melt.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    queue<pair<int,int>> Q;
    for(int i = 0 ; i < n ; i++){
        fill(visit[i], visit[i]+m, 0);
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
        }
    }
    Air_check();
    init_melt();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << visit[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
