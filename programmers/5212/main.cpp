#include <iostream>
#include <queue>

using namespace std;

string board[12];
string copy_board[12];

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c;

bool isValid(int y, int x)
{
    return y >= 0 && y < r && x >= 0 && x < c;
}

int main() {
    cin >> r >> c;
    for(int i = 0 ; i < r ; i++){
        cin >> board[i];
        copy_board[i] = board[i];
    }

    int max_x = -1, min_x = r, max_y = -1, min_y =r;

    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            if(board[i][j] == 'X') {
                int cnt = 0;

                for (int idx = 0; idx < 4; idx++) {
                    int nx = i + dx[idx];
                    int ny = j + dy[idx];
                    if (not(isValid(nx, ny)) || board[nx][ny] == '.') {
                        cnt++;
                    }
                }
                if (cnt >= 3) copy_board[i][j] = '.';
                else {
                    max_x = max(max_x, i);
                    min_x = min(min_x, i);
                    max_y = max(max_y, j);
                    min_y = min(min_y, j);
                }
            }
        }
    }
    for(int i = min_x ; i <= max_x ; i++){
        for(int j = min_y ; j <= max_y ; j++){
            cout << copy_board[i][j];
        }
        cout << '\n';
    }
    return 0;
}
