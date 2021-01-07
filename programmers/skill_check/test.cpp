#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

void PrintStack(stack<int> s)
{
    // If stack is empty
    if (s.empty())
        return;

// Extract top of the stack
    int x = s.top();

    // Pop the top element
    s.pop();

    // Print the current top
    // of the stack i.e., x
    cout << x << ' ';

    // Proceed to print
// remaining stack
    PrintStack(s);

    // Push the element back
    s.push(x);
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> bucket;

    for (int i : moves){
        for(int j = 0 ; j < board.size() ; j++){
            if(board[j][i-1] != 0){
                if(bucket.empty()){
                    bucket.push(board[j][i-1]);
                } else {
                    if(bucket.top() == board[j][i-1]){
                        bucket.pop();
                        answer += 2;
                    } else{
                        bucket.push(board[j][i-1]);
                    }
                }
                board[j][i-1] = 0;
                break;  
            }
        }
        PrintStack(bucket);
        cout << endl;
    }
    return answer;
}

int main(void){
  std::vector<std::vector<int>> v{{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
  std::vector<int> moves{1,5,3,5,1,2,1,4};

  solution(v, moves);
}
