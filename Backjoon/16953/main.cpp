#include <iostream>

using namespace std;

int main() {
    int a,b, answer=0;
    cin >> a >> b;
    while(b > a){
        if(b%10 == 1) b /= 10;
        else if(b%2 == 0) b /= 2;
        else {
            cout << -1;
            return 0;
        }
        answer++;
    }
    if(b < a) {
        cout << -1;
        return 0;
    }
    cout << answer+1;
    return 0;
}
