#include <iostream>
#include <stack>

using namespace std;

int n,m;
int board[502][502];
int visit[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int mx = 0;
void DFS(pair<int,int> cur, int cnt,int sum){
    if(cnt == 3){
        mx = max(mx, sum);
        return;
    }
    for(int idx = 0 ; idx < 4 ; idx++){
        int nx = cur.first + dx[idx];
        int ny = cur.second + dy[idx];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(visit[nx][ny]) continue;
        visit[nx][ny] = true;
        DFS({nx,ny}, cnt+1, sum+board[nx][ny]);
        visit[nx][ny] = false;
    }
}

void except(pair<int,int> cur){
    int sum = 0;
    int x = cur.first;
    int y = cur.second;
    // case ㅜ
    if(x>=0 && x+1 < n && y >=0 && y+2 < m){
        sum = board[x][y] + board[x][y+1] + board[x][y+2] + board[x+1][y+1];
        mx = max(mx,sum);
    }
    // case ㅗ
    if(x-1>=0 && x < n && y >=0 && y+2 < m){
        sum = board[x][y] + board[x-1][y+1] + board[x][y+1] + board[x][y+2];
        mx = max(mx,sum);
    }
    // case ㅏ
    if(x>=0 && x+2 < n && y >=0 && y+1 < m){
        sum = board[x][y] + board[x+1][y] + board[x+1][y+1] + board[x+2][y];
        mx = max(mx,sum);
    }
    // case ㅓ
    if(x>=0 && x+2 < n && y-1 >=0 && y < m){
        sum = board[x][y] + board[x+1][y-1] + board[x+1][y] + board[x+2][y];
        mx = max(mx,sum);
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
            visit[i][j] = true;
            DFS({i,j},0,board[i][j]);
            except({i,j});
            visit[i][j] = false;
        }
    }
    cout << mx;
    return 0;
}
