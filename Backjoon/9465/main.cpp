#include <iostream>

using namespace std;

int board[2][100002];

int main() {
    int t;
    cin >> t;
    for(t ; t > 0 ; t--){
        int n;
        cin >> n;
        int DP[2][n];
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 1 ; j <= n ; j++){
                cin >> board[i][j];
            }
        }
        DP[0][0] = DP[1][0] = 0;
        DP[0][1] = board[0][1];
        DP[1][1] = board[1][1];

        for(int i = 2 ; i <= n ; i++){
            DP[0][i] = max(DP[1][i-1], DP[1][i-2]) + board[0][i];
            DP[1][i] = max(DP[0][i-1], DP[0][i-2]) + board[1][i];
        }
        cout << max(DP[0][n],DP[1][n]) << '\n';
    }
    return 0;
}
