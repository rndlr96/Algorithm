#include <iostream>
#include <vector>

using namespace std;

vector<int> board[10002];
bool visit[10002];
vector<int> answers;

int n,m;
int cnt;
int mx;


void DFS(int num){
    visit[num] = true;
    for(auto i : board[num]){
        if(!visit[i]){
            DFS(i);
            cnt++;
        }
    }
}

int main() {
    cin >> n >> m;
    mx = 0;
    for(int i = 0 ; i < m ; i++){
        int x,y;
        cin >> x >> y;
        board[y].push_back(x);
    }
    for(int i = 1 ; i <= n ; i++){
        fill(visit, visit+10002, false);
        cnt = 0;
        DFS(i);
        answers.push_back(cnt);
        mx = max(mx, cnt);
    }
    for(int i = 0 ; i < answers.size() ; i++){
        if(answers[i] == mx){
            cout << i+1 << " ";
        }
    }
    return 0;
}
