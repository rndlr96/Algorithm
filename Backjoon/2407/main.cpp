#include <iostream>
#include <iomanip>


using namespace std;

long long int DP[102][102];
long long int DP2[102][102];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        DP[1][i] = i;
    }
    for(int i = 2 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(j == i) DP[i][j] = 1;
            else {
                DP[i][j] = DP[i][j-1] + DP[i-1][j-1];
                DP2[i][j] = DP2[i][j-1] + DP2[i-1][j-1];
            }
            if(DP[i][j] >= 10000000000000000){
                DP2[i][j]++;
                DP[i][j] -= 10000000000000000;
            }
        }
    }
    if(DP2[m][n] == 0){
        cout << DP[m][n];
    } else {
        cout << DP2[m][n];
        cout.width(16); // 폭을 10으로 지정
        cout.fill('0'); // 채움 문자는 '0'
        cout << DP[m][n];
    }
    return 0;
}