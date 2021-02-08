#include <iostream>

using namespace std;

int main() {
    int n, k, answer=0;
    cin >> n >> k;
    int price[n];
    for(int i = 0 ; i < n ; i++){
        cin >> price[i];
    }
    for(int i = n-1 ; i >= 0 ; i--){
        if(price[i] > k) continue;
        answer += k/price[i];
        k %= price[i];
        if(k == 0) {
            cout << answer;
            return 0;
        }
    }
    return 0;
}
