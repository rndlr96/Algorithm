#include <iostream>
#include <queue>

int visit[302][302];
int test_size, n;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

using namespace std;

int main() {
    cin >> test_size;
    for(int i = 0 ; i < test_size ; i++){
        cin >> n;
        for(int j = 0 ; j < 302 ; j++){
            fill(visit[j], visit[j]+302, 0);
        }
        queue<pair<int,int>> Q;
        pair<int,int> start, target;
        cin >> start.first >> start.second;
        cin >> target.first >> target.second;

        visit[start.first][start.second] = 1;
        Q.push(start);

        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            if(cur.first == target.first && cur.second == target.second) {
                cout << visit[target.first][target.second] - 1 << '\n';
                break;
            }
            for(int idx = 0 ; idx < 8 ; idx++){
                int nx = cur.first+dx[idx];
                int ny = cur.second+dy[idx];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(!visit[nx][ny]){
                    visit[nx][ny] = visit[cur.first][cur.second] + 1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    return 0;
}
