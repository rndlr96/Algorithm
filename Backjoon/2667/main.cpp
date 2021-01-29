#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string board[27];
    int visit[27][27];
    vector<int> maxs;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> board[i];
    }
    for(int i = 0 ; i < N ; i++) fill(visit[i], visit[i]+N, 0);
    int count = 0;
    queue<pair<int,int>> Q;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(visit[i][j] == 0 && board[i][j] == '1'){
                count++;
                visit[i][j] = 1;
                Q.push({i,j});
            }
            int num = 0;
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                num++;
                for(int idx = 0 ; idx < 4 ; idx++){
                    int nx = cur.first + dx[idx];
                    int ny = cur.second + dy[idx];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(visit[nx][ny] || board[nx][ny] != '1') continue;
                    visit[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            if(num > 0) maxs.push_back(num);
        }
    }
    cout << count << endl;
    sort(maxs.begin(), maxs.end(), less<int>());
    for(auto i : maxs){
        cout << i << endl;
    }
    return 0;
}
