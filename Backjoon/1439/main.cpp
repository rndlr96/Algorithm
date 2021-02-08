#include <iostream>

using namespace std;

int main() {
    int cnt = 0;
    string input;
    cin >> input;
    int arr[2] ={0,};
    char cur = '2';
    for(int i = 0 ; i < input.size() ; i++){
        if(cur != input[i]){
            arr[input[i]-'0'] += 1;
            cur = input[i];
        }
    }
    cout << min(arr[0],arr[1]);
    return 0;
}
