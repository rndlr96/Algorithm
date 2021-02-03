#include <iostream>

using namespace std;

string board[3];
char left_start, right_start;

pair<int, int> get_xy(char c){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            if(board[i][j] == c) return {i,j};
        }
    }
}

bool IsLeft(char c){
    string tmp = "bnmhjklyuiop";
    for(auto i : tmp){
        if(i == c) {
            return false;
        }
    }
    return true;
}

int main() {
    board[0] = "qwertyuiop";
    board[1] = "asdfghjkl#";
    board[2] = "zxcvbnm###";
    int answer = 0;
    cin >> left_start >> right_start;
    pair<int, int> left = get_xy(left_start);
    pair<int, int> right = get_xy(right_start);
    string input;
    cin >> input;
    for(auto i : input){
        if(IsLeft(i)){ // left
            pair<int, int> move = get_xy(i);
            answer += abs(left.first-move.first) + abs(left.second-move.second) + 1;
            left = move;
        } else {
            pair<int, int> move = get_xy(i);
            answer += abs(right.first-move.first) + abs(right.second-move.second) + 1;
            right = move;
        }
    }
    cout << answer;
    return 0;
}
