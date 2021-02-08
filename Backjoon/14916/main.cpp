#include <iostream>

using namespace std;

int main() {
    int money, answer = 0 ;
    cin >> money;
    for(int i = money/5 ; i >= 0 ; i--){
        int tmp = money;
        answer = i;
        tmp -= i*5;
        answer += tmp/2;
        tmp %= 2;
        if(tmp == 0) {
            cout << answer;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
