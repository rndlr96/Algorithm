#include <iostream>

using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    if(n <= k) {
        cout << 0 << '\n';
        return 0;
    }
    int result;
    for(result = 0 ; ; result++){
        int cnt = 0;
        int tmp = n;
        while(tmp){
            if(tmp%2){
                cnt++;
            }
            tmp /= 2;
        }
        if(cnt <= k) break;
        n++;
    }
    cout << result << '\n';
    return 0;
}
