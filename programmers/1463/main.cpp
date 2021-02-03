#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int n;

int main() {
    cin >> n;
    dp.push_back(0);
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(1);
    for(int i = 4 ; i <= n ;i++){
        if(i%2 == 0 && i%3 == 0){
            dp.push_back(min(dp[i/2]+1, min(dp[i/3]+1, dp[i-1]+1)));
        } else if(i%2 == 0){
            dp.push_back(min(dp[i/2]+1,dp[i-1]+1));
        } else if(i%3 == 0){
            dp.push_back(min(dp[i/3]+1, dp[i-1]+1));
        } else {
            dp.push_back(dp[i-1]+1);
        }
    }
    cout << dp[n];
    return 0;
}
