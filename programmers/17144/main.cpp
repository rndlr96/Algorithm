#include <iostream>
#include <queue>

using namespace std;

int board[52][52];
int R,C,T;
int air_up, air_down;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dust(){
    int copy_board[52][52] = {0,};
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            int cnt = 0;
            if(board[i][j] > 0){
                for(int idx = 0 ; idx < 4 ; idx++){
                    int nx = i+dx[idx];
                    int ny = j+dy[idx];
                    if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                    if(board[nx][ny] == -1) continue;
                    copy_board[nx][ny] += int(board[i][j]/5);
                    cnt++;
                }
            }
            copy_board[i][j] += (board[i][j] - int(board[i][j]/5) * cnt);
        }
    }
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            board[i][j] = copy_board[i][j];
        }
    }
}

void air(){
    int copy_board[52][52] = {0,};
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ;j++){
            copy_board[i][j] = board[i][j];
        }
    }
    if(air_up == 0){
        for(int i = 1 ; i < C ; i++){
            copy_board[air_up][i-1] = board[air_up][i];
        }
    } else {
        for(int i = 0 ; i < C-1 ; i++) copy_board[0][i] = board[0][i+1];
        for(int i = 0 ; i < C-1 ; i++) copy_board[air_up][i+1] = board[air_up][i];
        for(int i = 0 ; i < air_up ; i++) copy_board[i+1][0] = board[i][0];
        for(int i = 0 ; i < air_up ; i++) copy_board[i][C-1] = board[i+1][C-1];
        copy_board[air_up][1] = 0;
    }
    if(air_down == R){
        for(int i = 1 ; i < C ; i++){
            copy_board[air_down][i-1] = board[air_down][i];
        }
    } else {
        for(int i = 0 ; i < C-1 ; i++) copy_board[air_down][i+1] = board[air_down][i];
        for(int i = 0 ; i < C-1 ; i++) copy_board[R-1][i] = board[R-1][i+1];
        for(int i = air_down ; i < R-1 ; i++) copy_board[i][0] = board[i+1][0];
        for(int i = air_down ; i < R-1 ; i++) copy_board[i+1][C-1] = board[i][C-1];
        copy_board[air_down][1] = 0;
    }
    copy_board[air_up][0] = -1;
    copy_board[air_down][0] = -1;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
           board[i][j] = copy_board[i][j];
        }
    }
}

int main() {
    cin >> R >> C >> T;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cin >> board[i][j];
            if(board[i][j] == -1 && i > 0){
                air_up = i-1;
                air_down = i;
            }
        }
    }
    for(int i = 0 ; i < T ; i++) {
        dust();
        air();
    }
    int sum = 0;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            if(board[i][j] != -1) sum += board[i][j];
        }
    }
    cout << sum;
    return 0;
}
