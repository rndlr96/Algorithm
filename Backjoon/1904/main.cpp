#include <iostream>

using namespace std;
long long board[1000002];

int main() {
    int n;
    cin >> n;
    board[1] = 1; board[2] = 2;
    for(int i = 3 ; i <= n ; i++){
        board[i] = (board[i-1]+board[i-2])%15746;
    }
    cout<< board[n];
    return 0;
}