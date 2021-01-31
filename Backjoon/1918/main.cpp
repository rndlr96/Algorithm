#include <iostream>
#include <stack>

using namespace std;

int main() {
    string input;
    string output;
    cin >> input;
    stack<char> op;
    for(int i = 0 ; i < input.size() ; i++){
        if(input[i] >= 'A' && input[i] <= 'Z') output += input[i];
        else {
            switch(input[i]) {
                case '*':
                case '/':
                    while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
                        output += op.top();
                        op.pop();
                    }
                    op.push(input[i]);
                    break;
                case '+':
                case '-':
                    while (!op.empty() && op.top() != '(') {
                        output +=  op.top();
                        op.pop();
                    }
                    op.push(input[i]);
                    break;
                case '(':
                    op.push(input[i]);
                    break;
                case ')':
                    while (!op.empty() && op.top() != '(') {
                        output +=  op.top();
                        op.pop();
                    }
                    op.pop();
                    break;
            }
        }
    }
    while(!op.empty()){
        output +=  op.top();
        op.pop();
    }
    cout << output;
    return 0;
}
