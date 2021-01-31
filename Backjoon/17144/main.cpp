#include <iostream>
#include <queue>

int board[102][102];
int visit[102];


int n, start, target, m;

using namespace std;

int main() {
    cin >> n;
    cin >> start >> target;
    cin >> m;
    int answer = 0;
    for(int i = 0 ; i < m ; i++){
        int x,y;
        cin >> x >> y;
        board[x][y] = 1;
        board[y][x] = 1;
    }
    fill(visit, visit+102, 0);
    queue<int> Q;
    visit[start] = 1;
    Q.push(start);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int i = 1 ; i <= n ; i++){
            if(visit[i] == 0 && board[cur][i] == 1){
                visit[i] = visit[cur]+1;
                Q.push(i);
            }
        }
    }
    cout << visit[target]-1;
    return 0;
}
