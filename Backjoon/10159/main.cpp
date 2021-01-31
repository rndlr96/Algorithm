#include <iostream>
#include <queue>

using namespace std;

int board[1002][1002];
int copy_board[1002][1002];
bool visit[1002];
int n,m;

int main() {
    cin >> n;
    cin >> m;
    for(int i = 0 ; i < m ; i++){
        int x,y;
        cin >> x >> y;
        board[x][y] = 1;
        copy_board[x][y] = 1;
        copy_board[y][x] = 1;
    }
    for(int i = 1 ; i <= n ; i++){
        fill(visit, visit+1002, false);
        queue<int> q;
        q.push(i);
        visit[i] = true;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int j = 1 ; j <= n ; j++){
                if(!visit[j] && board[cur][j] == 1){
                    copy_board[i][j] = 1;
                    copy_board[j][i] = 1;
                    visit[j] = true;
                    q.push(j);
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        int answer = 0;
        for(int j = 1 ; j <= n ; j++){
            if(copy_board[i][j] == 1) answer++;
        }
        cout << n-answer-1 << '\n';
    }
    return 0;
}