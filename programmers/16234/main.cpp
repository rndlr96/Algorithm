#include <iostream>
#include <queue>

using namespace std;

int board[52][52];
bool visit[52][52];
int N, L, R;
int answer;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void open(){
    queue<pair<int,int>> Q;
    vector<pair<int,int>> list;
    while(true) {
        for(int i = 0 ; i < N ; i++) fill(visit[i], visit[i]+52, false);
        answer++;
        int fin=0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int sum; int cnt = 1;
                if (!visit[i][j]) {
                    visit[i][j] = true;
                    sum = board[i][j];
                    Q.push({i, j});
                    list.push_back({i, j});
                    fin++;
                } else continue;
                if(fin == N*N) return;
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int idx = 0; idx < 4; idx++) {
                        int nx = cur.first + dx[idx];
                        int ny = cur.second + dy[idx];
                        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                        int dif = abs(board[cur.first][cur.second] - board[nx][ny]);
                        if (!visit[nx][ny] && dif >= L && dif <= R) {
                            visit[nx][ny] = true;
                            sum += board[nx][ny];
                            cnt++;
                            Q.push({nx, ny});
                            list.push_back({nx, ny});
                        }
                    }
                }
                for (auto i : list) {
                    board[i.first][i.second] = sum / cnt;
                }
                list.clear();
            }
        }
    }
}

int main() {
    cin >> N >> L >> R;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> board[i][j];
        }
    }
    answer = 0;
    open();
    cout << answer-1;
    return 0;
}
