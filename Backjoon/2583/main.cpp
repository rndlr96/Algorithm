#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int board[102][102];
    int visit[102][102];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 0 ; i < k ; i++){
        int x1,x2,y1,y2;
        cin >> y1 >> x1 >> y2 >> x2;
        for(int j = x1 ; j < x2 ; j++){
            for(int k = y1 ; k < y2 ; k++){
                board[j][k] = 1;
                visit[j][k] = 1;
            }
        }
    }
    int count = 0;
    vector<int> counts;
    counts.pop
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int mx = 0;
            queue<pair<int,int>> Q;
            if(board[i][j] == 0 && visit[i][j] == 0){
                count++;
                visit[i][j] = 1;
                Q.push({i,j});
            }
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                mx++;
                for(int idx = 0 ; idx < 4 ; idx++){
                    int nx = cur.first + dx[idx];
                    int ny = cur.second + dy[idx];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(visit[nx][ny] || board[nx][ny] != 0) continue;
                    visit[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            if(mx > 0) counts.push_back(mx);
        }
    }
    cout << count << endl;
    sort(counts.begin(), counts.end(), less<int>());
    for(auto i : counts){
        cout << i << " ";
    }
    return 0;
}
