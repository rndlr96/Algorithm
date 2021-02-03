#include <iostream>
#include <queue>

using namespace std;

bool board[10002][10002];
bool visit[10002];
int n,m;

int main() {
    cin >> n >> m;
    int mx = 0;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        fill(board[i], board[i]+n, false);
    }
    fill(visit, visit+n, false);
    for(int i = 0 ; i < m ; i++){
        int x,y;
        cin >> x >> y;
        board[y][x] = true;
    }
    for(int i = 1 ; i <= n ; i++){
        fill(visit, visit+10002, false);
        visit[i] = true;
        queue<int> Q;
        for(int j = 1 ; j <= n ; j++){
            if(!visit[j] && board[i][j]){
                visit[j] = true;
                Q.push(j);
            }
            while(!Q.empty()){
                int cur = Q.front(); Q.pop();
                if(!visit[cur]) continue;
                for(int k = 1 ; k <= n ; k++){
                    if(!visit[k] && board[cur][k]){
                        visit[k] = true;
                        board[i][k] = true;
                        Q.push(k);
                    }
                }
            }
        }
        int sum = 0;
        for(int j = 1 ; j <= n ; j++){
            sum += board[i][j];
        }
        arr[i] = sum;
        mx = max(mx, sum);
    }
    for(int i = 1 ; i <= n ; i++){
        if(arr[i] == mx) cout << i << " ";
    }

    return 0;
}
