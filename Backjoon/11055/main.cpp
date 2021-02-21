#include <iostream>

using namespace std;

int main() {
    int DP[1002], board[1002], num, mx;
    cin >> num;
    for(int i = 0 ; i < num ; i++) {
        cin >> board[i];
        DP[i] = board[i];
    }
    mx = board[0];
    for(int i = 1 ; i < num ; i++) {
        for (int j = 0; j < i; j++) {
            if (board[i] > board[j]) {
                DP[i] = max(DP[i], DP[j] + board[i]);
                mx = max(mx, DP[i]);
            }
        }
    }
    cout << mx << " ";
    return 0;
}
