#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int board[n+2], DP[1002] ={0,};
    for(int i = 1 ; i <= n ; i++){
        cin >> board[i];
    }
    DP[1] = board[1];
    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j <= i/2 ; j++){
            DP[i] = max(DP[i], DP[i-j]+board[j]);
        }
        DP[i] = max(DP[i], board[i]);
    }
    cout << DP[n];
    return 0;
}
