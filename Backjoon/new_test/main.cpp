#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int board[102][102];
int copyboard[102][102];
bool visit[102];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i = 0 ; i < results.size() ; i++){
        int x = results[i][0];
        int y = results[i][1];
        board[x][y] = 1;
        copyboard[x][y] = 1;
        copyboard[y][x] = 1;
    }
    for(int i = 1 ; i <= n ; i++){
        queue<int> q;
        fill(visit,visit+102,false);
        for(int j = 1 ; j <= n ; j++){
            if(board[i][j] == 1){
                visit[i] = true;
                q.push(j);
            }
        }
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int j = 1 ; j <= n ; j++){
                if(!visit[j] && board[cur][j] == 1){
                    visit[j] = true;
                    copyboard[i][j] = 1;
                    copyboard[j][i] = 1;
                    copyboard[cur][j] = 1;
                    copyboard[j][cur] = 1;
                    q.push(j);
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        int count = 0;
        for(int j = 1 ; j <= n ; j++){
            if(copyboard[i][j] == 0){
                count += 1;
            }
        }
        if(count == 1){
            answer++;
        }
    }
    return answer;
}

int main(){
    solution(5, {{4,3},{4,2},{3,2},{1,2},{2,5}});
}