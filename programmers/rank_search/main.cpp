#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;

bool check(int x, int y, int size, vector<vector<int>> &board){
    int num = board[x][y];
    if(num != 0 && num != 1) {
        return false;
    }
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            if(num != board[x+i][y+j]) return false;
        }
    }
    answer.push_back(num);
    return true;
}

void fill(int x, int y, int size, int num, vector<vector<int>> &board){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            board[x+i][y+j] = num;
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    for(int i = arr.size() ; i >= 2 ; ){
        for(int j = 0 ; j < arr.size() ; ){
            for(int k = 0 ; k < arr.size() ; ){
                if(check(j,k,i,arr)) {
                    int num = i+2;
                    if(arr[j][k] == 1) num += 1;
                    fill(j,k,i,num,arr);
                }
                k += i;
            }
            j += i;
        }
        i = int(i/2);
    }
    for(int i = 0 ; i < arr.size() ; i++){
        for(int j = 0 ; j < arr.size() ; j++){
            if(arr[i][j] == 0 || arr[i][j] == 1){
                answer.push_back(arr[i][j]);
            }
        }
    }
    int one = 0;
    int zero = 0;
    for(auto i : answer){
        if(i == 0) one += 1;
        else zero +=1;
    }
    cout << one << " " << zero << endl;
    return {one,zero};
}

int main() {
    solution({{1,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1}});
    return 0;
}
