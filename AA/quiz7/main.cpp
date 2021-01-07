#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    string answer;

    for (int i = 0 ; i < input.length() ; i++){
        if(input[i] >= 'a' && input[i] <= 'z'){
            answer += input[i];
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            answer += tolower(input[i]);
        }
    }
    cout << answer << endl;
    return 0;
}
