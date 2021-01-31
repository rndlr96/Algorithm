#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};



int solution(int m, int n, vector<string> board) {
    int answer = 0;
    queue<pair<int,int>> Q;
    int count = 0;
    for(int i = 0 ; i < m-1 ; i++){
        for(int j = 0 ; j < n-1 ; j++){
            char cur = board[i][j];
            if(cur == ' ') continue;
            if(cur == board[i][j+1] && cur == board[i+1][j] && cur == board[i+1][j+1]){
                Q.push({i,j});
                count++;
            }
        }
    }
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int idx = 0 ; idx < 4 ; idx++){
            int nx = cur.first + dx[idx];
            int ny = cur.second + dy[idx];
            board[nx][ny] = ' ';
        }
    }
    if(count == 0){
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] != ' ') answer++;
            }
        }
        return m*n-answer;
    }
    else {
        for(int i = 0 ; i < n ; i++){
            for(int j = m-2 ; j >= 0 ; j--){
                for(int k = j ; k < m-1 ; k++){
                    if(board[k+1][i] == ' '){
                        board[k+1][i] = board[k][i];
                        board[k][i] = ' ';
                    }
                }
            }
        }
        return solution(m,n,board);
    }
}

int main() {
    vector<string> input;
    stack<string> s;
    int m,n;
    cin >> m >> n;
    for(int i = 0 ; i < m ; i++){
        string tmp;
        cin >> tmp;
        input.push_back(tmp);
    }

    cout << solution(m,n,input);
    return 0;
}

