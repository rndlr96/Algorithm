#include <iostream>
#include <queue>

int board[1002][1002];
bool visit[1002];
int n,m;

using namespace std;

int main() {
    cin >> n >> m;
    fill(visit, visit+n, false);
    for(int i = 0 ; i < m ; i++){
        int x,y;
        cin >> x >> y;
        board[x][y] = 1;
        board[y][x] = 1;
    }
    int answer = 0;
    for(int i = 1 ; i <= n ; i++){
        if(visit[i]) continue;
        answer++;
        queue<int> Q;
        visit[i] = true;
        Q.push(i);
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(int j = 1 ; j <= n ; j++){
                if(!visit[j] && board[cur][j] == 1){
                    visit[j] = true;
                    Q.push(j);
                }
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
