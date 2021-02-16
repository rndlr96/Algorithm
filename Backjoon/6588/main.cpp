#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int num;
    bool board[1000000];
    fill(board, board+1000000, false);
    for(int i=2; i*i<1000000; i++)
    {
        if(board[i]==0)
            for(int j=i*i; j<1000000; j+=i)
            {
                board[j]=1;
            }
    }

    while(true){
        cin >> num;
        if(num == 0) break;
        for(int i = 3 ; i <= num/2 ; i += 2){
            if(board[i]){
                if(board[num-i]){
                    cout << num << " = " << i << " + " << num-i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

