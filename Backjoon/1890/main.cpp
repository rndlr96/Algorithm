#include <iostream>

using namespace std;

int board[102][102];
long long visit[102][102];


int main() {
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> board[i][j];
        }
    }
    visit[0][0] = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(board[i][j] == 0 || i > n-1 || j > n-1){
                continue;
            }
            int down = i+board[i][j];
            int left = j+board[i][j];
            if(down < n) visit[down][j] += visit[i][j];
            if(left < n) visit[i][left] += visit[i][j];
        }
    }
    cout << visit[n-1][n-1];
    return 0;
}
