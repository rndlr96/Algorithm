#include <iostream>
#include <vector>

int board[10][10];
int copy_board[10][10];
int arr[8];
int n,m;

using namespace std;

struct cctv {
    int x;
    int y;
    int num;
};

vector<cctv> cctvs;
int area = 66;

void map_init(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            copy_board[i][j] = board[i][j];
        }
    }
}

void left(int x, int y){
    if(y == 0) return;
    for(int i = y-1 ; i >= 0 ; i--){
        if(board[x][i] == 0){
            copy_board[x][i] = 8;
        } else if (board[x][i] == 6) return;
    }
}
void right(int x, int y){
    if(y == m) return;
    for(int i = y+1 ; i < m ; i++){
        if(board[x][i] == 0){
            copy_board[x][i] = 8;
        } else if (board[x][i] == 6) return;
    }
}
void up(int x, int y){
    if(x == 0) return;
    for(int i = x-1 ; i >= 0 ; i--){
        if(board[i][y] == 0){
            copy_board[i][y] = 8;
        } else if (board[i][y] == 6) return;
    }
}
void down(int x, int y){
    if(x == n) return;
    for(int i = x+1 ; i < n ; i++){
        if(board[i][y] == 0){
            copy_board[i][y] = 8;
        } else if (board[i][y] == 6) return;
    }
}

void fill_array(cctv now, int dir){
    if(dir%4 == 0) up(now.x,now.y);
    else if(dir%4 == 1) right(now.x, now.y);
    else if(dir%4 == 2) down(now.x, now.y);
    else left(now.x, now.y);
}

void fill_map(){
    for(int i = 0 ; i < cctvs.size() ; i++){
        if(cctvs[i].num == 1){
            fill_array(cctvs[i], arr[i]);
        } else if (cctvs[i].num == 2){
            fill_array(cctvs[i], arr[i]);
            fill_array(cctvs[i], arr[i]+2);
        } else if (cctvs[i].num == 3){
            fill_array(cctvs[i], arr[i]);
            fill_array(cctvs[i], arr[i]+1);
        } else if (cctvs[i].num == 4){
            fill_array(cctvs[i], arr[i]);
            fill_array(cctvs[i], arr[i]+1);
            fill_array(cctvs[i], arr[i]+2);
        } else {
            fill_array(cctvs[i], arr[i]);
            fill_array(cctvs[i], arr[i]+1);
            fill_array(cctvs[i], arr[i]+2);
            fill_array(cctvs[i], arr[i]+3);
        }
    }
}

int get_answer(){
    int answer = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(copy_board[i][j] == 0) answer++;
        }
    }
    return answer;
}

void func(int cnt){
    if(cnt == cctvs.size()){
        map_init();
        fill_map();
        area = min(area, get_answer());
        return;
    }
    for(int idx = 0 ; idx < 4 ; idx++){
        arr[cnt] = idx;
        func(cnt+1);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5){
                cctvs.push_back({i,j,board[i][j]});
            }
        }
    }
    func(0);
    cout << area;
    return 0;
}