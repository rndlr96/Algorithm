#include <iostream>
#include <string>
#include <vector>

using namespace std;

void BFS(int index, vector<bool> &visit, vector<vector<int>> &computers){
    computers[index][index] = 0;
    visit[index] = true;
    cout << endl;
    for(int i = 0 ; i < computers.size()+1 ; i++){
        if( computers[index][i] == 1 && visit[i] == false )
            BFS(i, visit, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visit(n, false);
    for(int i = 0 ; i < n ; i++){
        if(visit[i] == false){
            BFS(i, visit, computers);
            cout << ++answer << endl;
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> computers{{1,1,0},{1,1,0},{0,0,1}};
    int n = 3;
    solution(n, computers);
    return 0;
}
