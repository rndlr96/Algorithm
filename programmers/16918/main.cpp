#include <iostream>
#include <queue>

using namespace std;

string board[202];
int timer[202][202];
int r,c,n;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};

void Print(int r, int c){
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}


int main() {
    cin >> r >> c >> n;
    for(int i = 0 ; i < r ; i++){
        cin >> board[i];
    }
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            if(board[i][j] != '.'){
                timer[i][j] = 2;
            }
        }
    }
    for(int i = n ; i > 0 ; i--){
        if(i == 1){
            Print(r,c);
        }
        queue<pair<int,int>> Q;
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                timer[i][j] -= 1;
                if(timer[i][j] == -1){
                    board[i][j] = 'O';
                    timer[i][j] = 3;
                }
                if(timer[i][j] == 0){
                    Q.push({i,j});
                }
            }
        }
        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            board[cur.first][cur.second] = '.';
            timer[cur.first][cur.second] = 0;
            for(int idx = 0 ; idx < 4 ; idx++){
                int nx = cur.first+dx[idx];
                int ny = cur.second+dy[idx];
                if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                board[nx][ny] = '.';
                timer[nx][ny] = 0;
            }
        }

    }
    return 0;
}
