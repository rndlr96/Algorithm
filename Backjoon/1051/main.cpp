#include <iostream>
#include <string>

using namespace std;

string board[52];
int n,m;

int main() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> board[i];
    }
    int mx = 0;
    for(int i = min(n,m)-1 ; i > 0 ; i--){
        for(int j = 0 ; j < n ; j++){
            if(j+i > n) break;
            for(int k = 0 ; k < m ; k++){
                if(k+i > m) break;
                char now = board[j][k];
                char n1 = board[j+i][k];
                char n2 = board[j][k+i];
                char n3 = board[j+i][k+i];
                if(now == board[j+i][k] && now == board[j][k+i] && now == board[j+i][k+i]){
                    mx = max(mx, i);
                }
            }
            if(mx != 0) break;
        }
        if(mx != 0) break;
    }
    cout << (mx+1)*(mx+1);
    return 0;
}
