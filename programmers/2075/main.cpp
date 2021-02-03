#include <iostream>
#include <stack>

using namespace std;

stack<int> board[1502];
int n, num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> num;
            board[j].push(num);
        }
    }
    int min_num, idx;
    for(int i = 0 ; i < n ; i++){
        min_num = board[0].top();
        idx = 0;
        for(int j = 1 ; j < n ; j++){
            if(min_num < board[j].top()){
                min_num = board[j].top();
                idx = j;
            }
        }
        board[idx].pop();
    }
    cout << min_num;
    return 0;
}
