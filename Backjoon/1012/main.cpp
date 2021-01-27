#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int main() {
    int board[502][502];
    bool visit[502][502];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int test_size;
    cin >> test_size;
    for(int test_num = 0 ; test_num < test_size ; test_num++){
        int answer = 0;
        int N, M, K;
        cin >> M >> N >> K;
        for(int i = 0 ; i < N ; i++) fill(board[i],board[i]+M, 0);
        for(int i = 0 ; i < N ; i++) fill(visit[i],visit[i]+M, false);
        for(int i = 0 ; i < K ; i++) {
            int x,y;
            cin >> y >> x;
            board[x][y] = 1;
        }
        queue<pair<int,int>> q;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(board[i][j] == 1 && visit[i][j] == false){
                    visit[i][j] = true;
                    q.push({i,j});
                    answer++;
                }
                while(!q.empty()){
                    pair<int,int> cur = q.front(); q.pop();
                    for(int dir = 0 ; dir < 4 ; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if(visit[nx][ny] || board[nx][ny] != 1) continue;
                        visit[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}
