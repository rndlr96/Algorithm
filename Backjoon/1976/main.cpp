#include <iostream>
#include <queue>

using namespace std;

int board[202][202];
bool visit[202];
int course[1002];
int n, m;

int main() {
    cin >> n;
    cin >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            board[j][i] = tmp;
        }
    }
    fill(visit, visit+202, false);
    for(int i = 1 ; i <= m ; i++){
        cin >> course[i];
    }
    queue<int> q;
    q.push(course[1]);
    visit[course[1]] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 1 ; i <= n ; i++){
            if(!visit[i] && board[cur][i] == 1){
                visit[i] = true;
                q.push(i);
            }
        }
    }
    int answer = 0;
    for(int i = 1 ; i <= m ; i++){
        if(!visit[course[i]]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
